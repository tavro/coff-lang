#include <iostream>
#include <iomanip>
#include <stdio.h>

#include "../symtab.hh"
#include "../parser/ast.hh"
#include "quads.hh"

using namespace std;

/* to suppress compiler warnings */
#define USE_Q { quad_list *foo = &q; foo = foo; }

quadruple::quadruple(quad_op_type op, long a1, long a2, long a3) :
    op_code(op), sym1(a1), sym2(a2), sym3(a3), int1(a1), int2(a2), int3(a3) {

}

quad_list_element::quad_list_element(quadruple *q, quad_list_element *n) :
    data(q), next(n) {

}

quad_list_iterator::quad_list_iterator(quad_list *q_list) :
    current(q_list->head) {

}

quadruple *quad_list_iterator::get_current() {
    if(current == NULL) {
        return NULL;
    }

    return current->data;
}

quadruple *quad_list_iterator::get_next() {
    if(current->next == NULL) {
        return NULL;
    }

    current = current->next;
    return get_current();
}

quad_list::quad_list(int label) :
    head(NULL), tail(NULL), last_label(label) {
    quad_nr = 1;
}

quad_list &quad_list::operator+=(quadruple *q) {
    if(head == NULL) {
        head = new quad_list_element(q, NULL);
        tail = head;
    } else {
        tail->next = new quad_list_element(q, NULL);
        tail = tail->next;
    }

    return *this;
}

/* methods for generating quads */

sym_index ast_expression_list::generate_quads(quad_list &q) {
    // TODO: Implement   
}

sym_index ast_elseif_list::generate_quads(quad_list &q) {
    // TODO: Implement   
}

sym_index ast_elseif::generate_quads(quad_list &q) {
    // TODO: Implement   
}

sym_index ast_id::generate_quads(quad_list &q) {
    // TODO: Implement   
}

sym_index ast_int::generate_quads(quad_list &q) {
    // TODO: Implement   
}

sym_index ast_real::generate_quads(quad_list &q) {
    // TODO: Implement   
}

// TODO: Implement NOT
// TODO: Implement uminus

sym_index ast_cast::generate_quads(quad_list &q) {
    // TODO: Implement   
}

sym_index do_binary_operation(quad_list &q, quad_op_type iop, quad_op_type rop, ast_binary_operation *node) {
    // TODO: Implement   
}

sym_index ast_add::generate_quads(quad_list &q) {
    USE_Q;
    return do_binary_operation(q, q_iplus, q_rplus, this);
}

sym_index ast_sub::generate_quads(quad_list &q) {
    USE_Q;
    return do_binary_operation(q, q_iminus, q_rminus, this);
}

sym_index ast_mult::generate_quads(quad_list &q) {
    USE_Q;
    return do_binary_operation(q, q_imult, q_rmult, this);
}

sym_index ast_div::generate_quads(quad_list &q) {
    USE_Q;
    return do_binary_operation(q, q_nop, q_rdiv, this);
}

// TODO: idiv
// TODO: mod
// TODO: or
// TODO: and

// TODO: binary relation

sym_index ast_equal::generate_quads(quad_list &q) {
    // TODO: Implement   
}

// TODO: not equal

sym_index ast_less::generate_quads(quad_list &q) {
    // TODO: Implement   
}

sym_index ast_greater::generate_quads(quad_list &q) {
    // TODO: Implement   
}

// TODO: assignment

void ast_expression_list::generate_param_list(quad_list &q, parameter_symbol *last_param, int *nr_params) {
    // TODO: Implement
}

sym_index ast_procedure_call::generate_quads(quad_list &q) {
    // TODO: Implement
}

sym_index ast_function_call::generate_quads(quad_list &q) {
    // TODO: Implement
}

sym_index ast_while::generate_quads(quad_list &q) {
    // TODO: Implement
}

void ast_elseif::generate_quads_and_jump(quad_list &q, int label) {
    // TODO: Implement
}

void ast_elseif_list::generate_quads_and_jump(quad_list &q, int label) {
    // TODO: Implement
}

sym_index ast_if::generate_quads(quad_list &q) {
    // TODO: Implement
}

sym_index ast_return::generate_quads(quad_list &q) {
    // TODO: Implement
}

sym_index ast_indexed::generate_quads(quad_list &q) {
    // TODO: Implement
}

sym_index ast_statement_list::generate_quads(quad_list &q) {
    // TODO: Implement
}

sym_index ast_procedure_head::generate_quads(quad_list &q) {
    // TODO: Implement
}

sym_index ast_function_head::generate_quads(quad_list &q) {
    // TODO: Implement
}

quad_list *ast_procedure_head::do_quads(ast_statement_list *s) {
    // TODO: Implement
}

quad_list *ast_function_head::do_quads(ast_statement_list *s) {
    // TODO: Implement
}

/* printing methods */

void quadruple::print(ostream &o) {
    // TODO: Implement
}

void quad_list::print(ostream &o) {
    // TODO: Implement
}

ostream &operator<<(ostream &o, quadruple *q) {
    if(q != NULL) {
        q->print(o);
    }
    else {
        o << "  Quad: NULL\n";
    }
    return o;
}

ostream &operator<<(ostream &o, quad_list *q) {
    if(q_list != NULL) {
        q_list->print(o);
    }
    else {
        o << "  Quad list: NULL\n";
    }
    return o;
}