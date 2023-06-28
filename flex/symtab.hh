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

/* TODO: class declarations */

#endif