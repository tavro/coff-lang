#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <string.h>
#include "symtab.hh"

using namespace std;

/* global variables */

symbol_table *sym_tab = new symbol_table();
sym_index void_type;
sym_index int_type;
sym_index real_type;

/* symbol_table class */

/*
allocates data members.
the table itself is just a table of pointers to symbols
*/
symbol_table::symbol_table() {
    // TODO: documentation needed
    pool_pos = 0;
    pool_length = BASE_POOL_SIZE;

    string_pool = new char[pool_length];
    string_pool[0] = '\0';

    /* init hash table */
    hash_table = new sym_index[HASH_SIZE];
    for(int i = 0; i < HASH_SIZE; i++) {
        hash_table[i] = NULL_SYM;
    }

    /* init display */
    current_level = 0;
    block_table = new sym_index[MAX_BLOCK];
    for(int i = 0; i < MAX_BLOCK; i++) {
        block_table[i] = 0;
    }

    /* init symbol table */
    sym_table = new symbol*[MAX_SYM];
    for(int i = 0; i < MAX_SYM; i++) {
        sym_table[i] = NULL;
    }
    label_nr = -1;
    temp_nr = 0;
    sym_pos = -1;

    /* install predefined symbols */
    if(true) { // TODO: Leave it until scanner is finished
        return;
    }

    position_information *dummy_pos = new position_information();
    
    // TODO: implement the rest
    
}

/* utility functions */

// TODO: Write desc
long symbol_table::ieee(double d) {
    assert(sizeof(double) == 8);
    assert(sizeof(long) == 8);

    long l;
    memcpy(&l, &d, sizeof(long));
    return l;
}

long symbol_table::get_next_label() {
    return label_nr++; // labels start on -1
}

// TODO: Write desc
sym_index symbol_table::gen_temp_var(sym_index type) {
    string name = "$" + to_string(++sym_tab->temp_nr);

    // TODO: this is just me being lazy, fix this
    if (to_string(sym_tab->temp_nr).length() == 2) {
        name = name + "     ";
    }
    else if (to_string(sym_tab->temp_nr).length() == 1) {
        name = name + "      ";
    }

    pool_index pool_p = pool_install((char*)name.c_str());

    if (type == int_type) {
        // COMMENT: forgot this wasnt implemented yet
        // TODO: return enter_variable(pool_p, int_type);
    }
    // TODO: return enter_variable(pool_p, real_type);
}

// TODO: get_size() is not implemented

// TODO: write description
void symbol_table::print(int detail) {
    // TODO: implement
}

/* string pool methods */

/* 
capitalizes string, called by the scanner
this method causes a memory leak if the
string isnt deleted after use
*/
char *symbol_table::capitalize(const char *s) {
    char *capitalized_s = new char[strlen(s) + 1];

    unsigned int i;
    for (i = 0; i < strlen(s); i++) {
        capitalized_s[i] = (unsigned char) toupper(s[i]);
    }
    capitalized_s[i] = '\0';

    return capitalized_s;
}

// TODO: write description
pool_index symbol_table::pool_install(char *s) {
    // check if pool is full, if so, double its size
    if(pool_pos + 1 + (int) strlen(s) >= pool_length) {
        char *tmp_pool = new char[pool_length * 2];

        // double size
        pool_length *= 2;
        strcpy(tmp_pool, string_pool);
        delete[] string_pool;
        string_pool = tmp_pool;
    }

    long old_pos = pool_pos; // start of string

    // struct with length/char *
    // would be a better and more general solution
    if (strlen(s) >= 255) {
        fatal("symbol_table::pool_install: string too long");
        return 0;
    }

    string_pool[pool_pos++] = (unsigned char) strlen(s);
    string_pool[pool_pos] = '\0';

    strcpy(string_pool+pool_pos, s); // the string itself
    pool_pos += strlen(s) + 1;

    return old_pos;
}

char *symbol_table::pool_lookup(const pool_index p) {
    assert(p < pool_pos);

    char *start = &string_pool[p + 1];
    int length = (int) string_pool[p];

    char *s = new char[length + 1];
    strncpy(s, start, length);
    s[length] = '\0';

    return s;
}

/* compare strings */
bool symbol_table::pool_compare(const pool_index p1, const pool_index p2) {
    assert(p1 < pool_pos && p2 < pool_pos);
    return strcmp(pool_lookup(p1), pool_lookup(p2)) == 0;
}

pool_index symbol_table::pool_forget(const pool_index pool_p) {
    char *last_entry = pool_lookup(pool_p);

    // make sure it really is last entry
    assert((pool_p + (int) strlen(last_entry)) == pool_pos - 1);

    pool_pos = pool_p;
    string_pool[pool_pos] = '\0';
    return pool_pos;
}

// TODO: Write desc
char *symbol_table::fix_string(const char *old_str) {
    assert(strlen(old_str) >= 2);

    int new_index = 0;
    char *new_str = new char[strlen(old_str) - 2 + 1];

    // start on 1 to skip opening quote char
    // end on strlen-1 to skip closing quote char
    for (unsigned int i = 1; i < strlen(old_str) - 1; i++) {
        if(old_str[i] == '\'' && i < strlen(old_str) - 2 && old_str[i + 1] == '\'') {
            continue;
        }
        new_str[new_index++] = old_str[i];
    }

    new_str[new_index] = '\0';
    return new_str;
}

/* hash table methods */

/*
uses hash_x33 algorithm
*/
hash_index symbol_table::hash(const pool_index p) {
    char *s = pool_lookup(p);
    int len = (int) strlen(s);
    unsigned int h = 0;

    // calculate hash value
    while (len > 0) {
        h = (h << 5) + h + *s++;
        len--;
    }

    // memory leak since s is still allocated
    // delete[] s is not an good idea since s is changed
    return h % HASH_SIZE;
}

/* display methods */

sym_index symbol_table::current_environment() {
    return block_table[current_level];
}

void symbol_table::open_scope() {
    current_level++;

    if(current_level >= MAX_BLOCK) { // check if inside table range
        fatal("symbol_table::open_scope: symbol block table is full");
    }

    block_table[current_level] = sym_pos;
}

sym_index symbol_table::close_scope() {
    sym_index index = sym_pos;

    while (index > block_table[current_level]) {
        symbol* sym = sym_tab->get_symbol(index);

        if(sym->back_link != NULL_SYM) {
            hash_table[sym->back_link] = sym->hash_link;
        }

        sym->hash_link = NULL_SYM;
        index--;
    }

    block_table[current_level] = 0;
    current_level--;

    return sym_pos;
}

/* main methods */

// TODO: write description
sym_index symbol_table::lookup_symbol(const pool_index pool_p) {
    hash_index h_index = hash(pool_p);
    sym_index s_index = hash_table[h_index];

    while(s_index != NULL_SYM) {
        if(sym_tab->pool_compare(sym_table[s_index]->id, pool_p)) {
            return s_index;
        }
        s_index = sym_table[s_index]->hash_link;
    }

    return 0;
}

symbol *symbol_table::get_symbol(const sym_index sym_p) {
    if(sym_p == NULL_SYM) {
        return NULL;
    }
    
    return sym_table[sym_p];
}

//TODO: write description
pool_index symbol_table::get_symbol_id(const sym_index sym_p) {
    // this should never happen
    // 0 points to name of global level => 'program.'
    if(sym_p == NULL_SYM) {
        return 0;
    }

    return sym_table[sym_p]->id;
}

//TODO: write description
sym_index symbol_table::get_symbol_type(const sym_index sym_p) {
    if(sym_p == NULL_SYM) {
        return void_type;
    }

    return sym_table[sym_p]->type;
}

//TODO: write description
sym_type symbol_table::get_symbol_tag(const sym_index sym_p) {
    if(sym_p == NULL_SYM) {
        return SYM_UNDEF;
    }

    return sym_table[sym_p]->tag;
}

//TODO: write description
void symbol_table::set_symbol_type(const sym_index sym_p, const sym_index type_p) {
    if(sym_p == NULL_SYM) {
        return;
    }

    sym_table[sym_p]->type = type_p;
}

//TODO: write description
sym_index symbol_table::install_symbol(const pool_index pool_p, const sym_type tag) {
    //TODO: implement
}

//TODO: write description
sym_index symbol_table::enter_constant(position_information *pos, const pool_index pool_p, const sym_index type, const long ival) {
    // install constant in sym table
    sym_index sym_p = install_symbol(pool_p, SYM_CONST);
    constant_symbol *con = sym_table[sym_p]->get_constant_symbol();

    // check it's not already declared
    if (con->tag != SYM_UNDEF) {
        type_error(pos) << "Redeclaration: " << con << endl;
        return sym_p;
    }

    con->type = type;
    con->tag = SYM_CONST;
    con->const_value.ival = ival;
    sym_table[sym_p] = con;

    return sym_p;
}

//TODO: write description
sym_index symbol_table::enter_constant(position_information *pos, const pool_index pool_p, const sym_index type, const double rval) {
    sym_index sym_p = install_symbol(pool_p, SYM_CONST);
    constant_symbol *con = sym_table[sym_p]->get_constant_symbol();

    if (con->tag != SYM_UNDEF) {
        type_error(pos) << "Redeclaration: " << con << endl;
        return sym_p;
    }

    con->type = type;
    con->tag = SYM_CONST;
    con->const_value.rval = rval;
    sym_table[sym_p] = con;

    return sym_p;
}

// TODO: when parser implemented, create enter_variable methods
// as well as other relevant methods

sym_index symbol_table::enter_function(position_information *pos, const pool_index pool_p) {
    sym_index sym_p = install_symbol(pool_p, SYM_FUNC);
    function_symbol *func = sym_table[sym_p]->get_function_symbol();

    if (func->tag != SYM_UNDEF) {
        type_error(pos) << "Redeclaration: " << func << endl;
        return sym_p;
    }

    func->tag = SYM_FUNC;
    func->last_param = NULL;
    func->ar_size = 0;
    func->label_nr = get_next_label();
    sym_table[sym_p] = func;

    return sym_p;
}

sym_index symbol_table::enter_parameter(position_information *pos, const pool_index pool_p, const sym_index type) {
    sym_index sym_p = install_symbol(pool_p, SYM_PARAM);
    parameter_symbol *par = sym_table[sym_p]->get_parameter_symbol();

    if (par->tag != SYM_UNDEF) {
        type_error(pos) << "Redeclaration: " << par << endl;
        return sym_p;
    }

    // TODO: explain why we do this
    symbol *tmp = sym_table[current_environment()];

    parameter_symbol *tmp_param;

    // TODO: if-elseif-else
    
    par->preceding = tmp_param;

    int param_offset = 0;
    while (tmp_param != NULL) {
        param_offset += tmp_param->size;
        tmp_param = tmp_param->preceding;
    }

    par->offset = param_offset;
    par->tag = SYM_PARAM;
    par->size = get_size(type);
    par->type = type;
    sym_table[sym_p] = par;

    return sym_p;
}