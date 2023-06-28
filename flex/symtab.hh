#ifndef __SYMTAB_HH__
#define __SYMTAB_HH__

/* to make code more readable */
typedef long pool_index;
typedef long hash_index;
typedef long sym_index;
typedef int  block_level;

typedef union {
    long    ival; // integer value
    double  rval; // real value
} const_val;

enum symbol_types {
    SYM_FUNC,
    SYM_PARAM,
    SYM_CONST,
};
typedef enum symbol_types sym_type;

/* constants used in symbol table */
const block_level MAX_BLOCK = 8;        // max nesting level (=block table size)
const hash_index  HASH_SIZE = 512;      // max size of hash table
const pool_index  BASE_POOL_SIZE = 1024;// base size of string pool
const sym_index   MAX_SYM = 1024;       // max size of symbol table
const sym_index   NULL_SYM = -1;        // signifies 'no symbol'

// TODO: handle non-int array sizes

/* sets limit for max nr of temp variables */
const int MAX_TEMP_VARS = 999999;
const int MAX_TEMP_VARS_LEN = 8;

/* predefined symbol classes */
class constant_symbol;
class parameter_symbol;
class function_symbol;

class symbol_table;

/* global pointer to symbol_table */
extern symbol_table *sym_tab; // implementation in symtab.cc

/* global symbol table variables */
extern sym_index void_type;
extern sym_index int_type;
extern sym_index real_type;

/* 
=============================
 Symbol classes declarations 
=============================
*/

/* 
symbol table consists of entries of subclasses to symbol.
this class contains data common to all symbol types.
do not use this class directly.
*/
class symbol {
protected:
    // called when symbol sent to outstream
    virtual void print(ostream &);

    // used to control level of detail given
    // when printing a symbol
    friend ostream &long_symbols(ostream &);
    friend ostream &summary_symbols(ostream &);
    friend ostream &short_symbols(ostream &);

    enum format_types { LONG, SUMMARY, SHORT };
    typedef enum format_types format_type;
    static format_type output_format;
public:
    /*
    index to string_pool
    
    the objects id is stored in the string table.
    index to string table is a value denoting where
    an id starts in the string table.
    */
    pool_index id;

    /*
    used to differentiate between symbol classes
    when downcasting from superclass.
    */
    sym_type tag;

    /*
    contains index to a name type which
    only can be int_type or real_type
    */
    sym_index type;

    hash_index hash_link;
    /*
    speeds up certain types of lookups
    */
    hash_index back_link;

    block_level level;

    /*
    specifies relative position object has
    in memory space which has been reserved
    for given lexical level on runtime stack.
    (used during code generation)
    */
    int offset;

    symbol(pool_index);

    virtual constant_symbol *get_constant_symbol() {
        // TODO: fatal("Illegal downcasting to constant from symbol class");
        return NULL;
    }
    virtual constant_symbol *get_parameter_symbol() {
        // TODO: fatal("Illegal downcasting to parameter from symbol class");
        return NULL;
    }
    virtual constant_symbol *get_function_symbol() {
        // TODO: fatal("Illegal downcasting to function from symbol class");
        return NULL;
    }

    friend ostream &operator<<(ostream &, symbol *); // allows to print a symbol by sending it to outstream
};

class constant_symbol : public symbol {
protected:
    virtual void print(ostream &);

public:
    const_val const_value;

    constant_symbol(const pool_index);

    virtual constant_symbol *get_constant_symbol() {
        return this;
    }
};

/*
TODO: write semantic check description
*/
class parameter_symbol : public symbol {
protected:
    virtual void print(ostream &);

public:
    int size; // byte size of parameter 
    parameter_symbol *preceding;
    parameter_symbol(const pool_index);

    virtual parameter_symbol *get_parameter_symbol() {
        return this;
    }
};

class function_symbol : public symbol {
protected:
    virtual void print(ostream &);

public:
    /*
    activation record size

    specifies the memory space needed
    to store local variables belonging to
    function on the runtime stack.
    */
    int ar_size;

    int label_nr; // assembler code label number

    /*
    list of params stored in reverse order
    to make type-checking easier
    */
    parameter_symbol *last_param;

    function_symbol(const pool_index);

    virtual function_symbol *get_function_symbol() {
        return this;
    }
};

ostream &short_symbols(ostream &);
ostream &summary_symbols(ostream &);
ostream &long_symbols(ostream &);

friend ostream &operator<<(ostream &, symbol *); // allows to print a node by sending it to outstream

/* 
================================
 Symbol table class declaration 
================================
*/
class symbol_table {
private:
    /* string pool variables */
    char *string_pool;
    long pool_length;
    long pool_pos; // points to end of string pool

    /* hash table variables */
    sym_index *hash_table;

    /* display variables */
    block_level current_level;
    sym_index *block_table; // pointers that points at start of a new block

    /* symbol table variables */
    symbol **sym_table;
    sym_index sym_pos; // last entered symbol
    int label_nr; // assembler label counter
    long temp_nr; // temp var counter
public:
    symbol_table();

    /* utility methods */
    
    long ieee(double); // convert double to ieee 64-bit long
    int get_size(const sym_index); // (byte size)

    /* string pool methods */

    /* 
    install string in string pool.
    returns index to installed string
    */
    pool_index pool_install(char *);

    /*
    returns string pool_index points at
    */
    char *pool_lookup(const pool_index);

    /*
    compare two strings.
    returns true if they are identical
    */
    bool pool_compare(const pool_index, const pool_index);

    /*
    remove last installed entry from string pool
    */
    pool_index pool_forget(const pool_index);

    char *fix_string(const char*);
    char *capitalize(const char*);

    /* hash table methods */

    /*
    return hash index given pool index
    */
    hash_index hash(const pool_index);

    /* symbol methods */
    symbol *get_symbol(const sym_index);

    // TODO: write description for this
    sym_index install_symbol(const pool_index, const sym_type tag);

    // TODO: write description for this
    sym_index lookup_symbol(const pool_index);

    /*
    dumping symbol table to stdout
    value of argument determines what info will be printed

    1: print one line of info per symbol table entry
    2: print only string table, show current pool_pos
    3: print only non-zero elements in hash table
    */
    void print(int);

};

#endif