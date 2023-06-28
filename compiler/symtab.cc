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
    hash_table = new sym_index[MAX_HASH];
    for(int i = 0; i < MAX_HASH; i++) {
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