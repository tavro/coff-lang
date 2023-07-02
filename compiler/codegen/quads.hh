#ifndef __QUADS_HH__
#define __QUADS_HH__

#include "../parser/ast.hh"

/*
quads used for code generation
comments show argument types
'-' means argument not used
*/
typedef enum {
    q_rload,        // int, -, sym
    q_iload,        // int, -, sym
    /* TODO: not */
    /* TODO: uminus */
    /* TODO: or */
    /* TODO: and */
    /* TODO: mod */
    /* TODO: not equal */
    q_rplus,        // sym, sym, sym
    q_iplus,        // sym, sym, sym
    q_rminus,       // sym, sym, sym
    q_iminus,       // sym, sym, sym
    q_rmult,        // sym, sym, sym
    q_imult,        // sym, sym, sym
    q_rdiv,         // sym, sym, sym
    q_idiv,         // sym, sym, sym
    q_req,          // sym, sym, sym
    q_ieq,          // sym, sym, sym
    q_rlt,          // sym, sym, sym
    q_ilt,          // sym, sym, sym
    q_rgt,          // sym, sym, sym
    q_igt,          // sym, sym, sym
    q_rstore,       // sym, -, sym
    q_istore,       // sym, -, sym
    /* TODO: assign */
    q_call,         // sym, int, sym (- for procedure)
    q_rreturn,      // int, sym, -
    q_ireturn,      // int, sym, -
    q_lindex,       // sym, sym, sym
    q_rrindex,      // sym, sym, sym
    q_irindex,      // sym, sym, sym
    q_itor,         // sym, -, sym
    q_jmp,          // int, -, -
    q_jmpf,         // int, sym, -
    q_param,        // sym, -, -
    q_labl,         // int, -, -
    q_nop,          // -, -, -
} quad_op_type;

class quad_list;

class quadruple {
private:
    void print(ostream &);

public:
    quad_op_type op_code;

    // TODO: May not need all of these vars
    sym_index sym1;
    sym_index sym2;
    sym_index sym3;

    long int1;
    long int2;
    long int3;
    
    quadruple(quad_op_type, sym_index, sym_index, sym_index);
    friend ostream &operator<<(ostream &, quadruple *);
};

/*
prevent quads from having to 
contain link to next quad
*/
class quad_list_element {
public:
    quadruple *data;
    quad_list_element *next;

    quad_list_element(quadruple *, quad_list_element *);
};

class quad_list_iterator {
private:
    quad_list_element *current;

public:
    quad_list_iterator(quad_list *q_list);

    quadtuple *get_current();
    quadruple *get_next();
};

class quad_list {
private:
    quad_list_element *head;
    quad_list_element *tail;

    int quad_nr;
    void print(ostream &);

public:
    int last_label;
    quad_list(int);

    quad_list &operator+=(quadruple *q);

    friend class quad_list_iterator;
    friend ostream &operator<<(ostream &, quad_list *);
};

#endif