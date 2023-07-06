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
    USE_Q;

    fatal("trying to call generate_quads on ast_expression_list");

    return NULL_SYM;   
}

sym_index ast_elseif_list::generate_quads(quad_list &q) {
    USE_Q;

    fatal("trying to call generate_quads on ast_elseif_list");

    return NULL_SYM;
}

sym_index ast_elseif::generate_quads(quad_list &q) {
    USE_Q;

    int bottom = sym_tab->get_next_label();
    sym_index pos = condition->generate_quads(q);

    q += new quadruple(q_jmpf, bottom, pos, NULL_SYM);
    pos = body->generate_quads(q);
    q += new quadruple(q_label, bottom, NULL_SYM, NULL_SYM);

    return NULL_SYM;
}

sym_index ast_id::generate_quads(quad_list &q) {
    USE_Q;
    return sym_p;  
}

sym_index ast_int::generate_quads(quad_list &q) {
    USE_Q;
    sym_index address = sym_tab->gen_temp_var(int_type);
    q += new quadruple(q_iload, value, NULL_SYM, address);
    return address;
}

sym_index ast_real::generate_quads(quad_list &q) {
    USE_Q;
    sym_index address = sym_tab->gen_temp_var(real_type);
    q += new quadruple(q_rload, sym_tab->ieee(value), NULL_SYM, address);
    return address;
}

// TODO: Implement NOT
// TODO: Implement uminus

sym_index ast_cast::generate_quads(quad_list &q) {
    USE_Q;

    sym_index sym_expr = expr->generate_quads(q);
    sym_index address = sym_tab->gen_temp_var(real_type);

    q += new quadruple(q_itor, sym_expr, NULL_SYM, address);

    return address; 
}

sym_index do_binary_operation(quad_list &q, quad_op_type iop, quad_op_type rop, ast_binary_operation *node) {
    sym_index sym_left = node->left->generate_quads(q);
    sym_index sym_right = node->right->generate_quads(q);

    sym_index address;

    if(sym_tab->get_symbol_type(sym_left) == int_type) {
        address = sym_tab->gen_temp_var(int_type);
        q += new quadruple(iop, sym_left, sym_right, address);
    }
    else {
        address = sym_tab->gen_temp_var(real_type);
        q += new quadruple(rop, sym_left, sym_right, address);
    }

    return address;
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

sym_index do_binary_relation(quad_list &q, quad_op_type iop, quad_op_type rop, ast_binary_relation *node) {
    sym_index sym_left = node->left->generate_quads(q);
    sym_index sym_right = node->right->generate_quads(q);
    sym_index tmp_var = sym_tab->gen_temp_var(int_type);

    if(sym_tab->get_symbol_type(sym_left) == int_type) {
        q += new quadruple(iop, sym_left, sym_right, tmp_var);
    }
    else {
        q += new quadruple(rop, sym_left, sym_right, tmp_var);
    }

    return tmp_var;
}

sym_index ast_equal::generate_quads(quad_list &q) {
    USE_Q;
    return do_binary_relation(q, q_ieq, q_req, this);
}

// TODO: not equal

sym_index ast_less_than::generate_quads(quad_list &q) {
    USE_Q;
    return do_binary_relation(q, q_ilt, q_rlt, this);
}

sym_index ast_greater_than::generate_quads(quad_list &q) {
    USE_Q;
    return do_binary_relation(q, q_igt, q_rgt, this);
}

// TODO: assignment

void ast_expression_list::generate_param_list(quad_list &q, parameter_symbol *last_param, int *nr_params) {
    USE_Q;

    sym_index param = last_expr->generate_quads(q);
    q += new quadruple(q_param, param, NULL_SYM, NULL_SYM);
    (*nr_params)++;

    if(preceding) {
        preceding->generate_param_list(q, NULL, nr_params);
    }
}

sym_index ast_procedure_call::generate_quads(quad_list &q) {
    USE_Q;

    int nr_params = 0;
    if(param_list) {
        param_list->generate_param_list(q, NULL, &nr_params);
    }

    q += new quadruple(q_call, id->sym_p, nr_params, NULL_SYM);
    return NULL_SYM;
}

sym_index ast_function_call::generate_quads(quad_list &q) {
    USE_Q;

    int nr_params = 0;
    sym_index address;

    if(type == int_type) {
        address = sym_tab->gen_temp_var(int_type);
    }
    else {
        address = sym_tab->gen_temp_var(real_type);
    }

    if(param_list) {
        param_list->generate_param_list(q, NULL, &nr_params);
    }

    q += new quadruple(q_call, id->sym_p, nr_params, address);
    return address;
}

sym_index ast_while::generate_quads(quad_list &q) {
    int top = sym_tab->get_next_label();
    int bottom = sym_tab->get_next_label();

    q += new quadruple(q_label, top, NULL_SYM, NULL_SYM);

    sym_index pos = condition->generate_quads(q);
    q += new quadruple(q_jmpf, bottom, pos, NULL_SYM);

    pos = body->generate_quads(q);
    q += new quadruple(q_jmp, top, NULL_SYM, NULL_SYM);

    q += new quadruple(q_label, bottom, NULL_SYM, NULL_SYM);

    return NULL_SYM;
}

void ast_elseif::generate_quads_and_jump(quad_list &q, int label) {
    USE_Q;

    int bottom = sym_tab->get_next_label();

    sym_index pos = condition->generate_quads(q);
    q += new quadruple(q_jmpf, bottom, pos, NULL_SYM);

    if (body) {
        pos = body->generate_quads(q);
    }

    q += new quadruple(q_jmp, label, pos, NULL_SYM);
    q += new quadruple(q_label, bottom, NULL_SYM, NULL_SYM);
}

void ast_elseif_list::generate_quads_and_jump(quad_list &q, int label) {
    USE_Q;

    if(preceding) {
        preceding->generate_quads_and_jump(q, label);
    }
    last_elseif->generate_quads_and_jump(q, label);
}

sym_index ast_if::generate_quads(quad_list &q) {
    USE_Q;

    int elseif = sym_tab->get_next_label();
    int bottom;

    if(elseif_list || else_body) {
        bottom = sym_tab->get_next_label();
    }

    sym_index pos = condition->generate_quads(q);
    q += new quadruple(q_jmpf, elseif, pos, NULL_SYM);

    if (body) {
        pos = body->generate_quads(q);
    }

    if (elseif_list || else_body) {
        q += new quadruple(q_jmp, bottom, pos, NULL_SYM);
    }

    q += new quadruple(q_label, elseif, NULL_SYM, NULL_SYM);
    if(elseif_list) {
        elseif_list->generate_quads_and_jump(q, bottom);
    }

    if(else_body) {
        else_body->generate_quads(q);
    }

    if(elseif_list || else_body) {
        q += new quadruple(q_label, bottom, NULL_SYM, NULL_SYM);
    }

    return NULL_SYM;
}

sym_index ast_return::generate_quads(quad_list &q) {
    USE_Q;

    if(value) {
        sym_index val = value->generate_quads(q);
        sym_index val_type = sym_tab->get_symbol_type(val);

        if(val_type == int_type) {
            q += new quadruple(q_ireturn, q.last_label, val, NULL_SYM);
        }
        else if(val_type == real_type) {
            q += new quadruple(q_rreturn, q.last_label, val, NULL_SYM);
        }
    }
    else {
        q += new quadruple(q_jmp, q.last_label, NULL_SYM, NULL_SYM);
    }

    return NULL_SYM;
}

sym_index ast_indexed::generate_quads(quad_list &q) {
    USE_Q;

    sym_index sym_ind = index->generate_quads(q);
    sym_index address;

    if(sym_tab->get_symbol_type(sym_ind) == int_type) {
        address = sym_tab->gen_temp_var(int_type);
        q += new quadruple(q_irindex, id->sym_p, sym_ind, address);
    }
    else if(sym_tab->get_symbol_type(sym_ind) == real_type) {
        address = sym_tab->gen_temp_var(real_type);
        q += new quadruple(q_rrindex, id->sym_p, sym_ind, address);
    }

    return address;
}

sym_index ast_statement_list::generate_quads(quad_list &q) {
    if(preceding != NULL) {
        preceding->generate_quads(q);
    }

    if(last_stmt != NULL) {
        last_stmt->generate_quads(q);
    }
    return NULL_SYM;
}

sym_index ast_procedure_head::generate_quads(quad_list &q) {
    USE_Q;
    return NULL_SYM;
}

sym_index ast_function_head::generate_quads(quad_list &q) {
    USE_Q;
    return NULL_SYM;
}

quad_list *ast_procedure_head::do_quads(ast_statement_list *s) {
    int last_label = sym_tab->get_next_label();
    quad_list *q = new quad_list(last_label);

    if(s != NULL) {
        s->generate_quads(*q);
    }

    (*q) += new quadruple(q_label, last_label, NULL_SYM, NULL_SYM);
    return q;
}

quad_list *ast_function_head::do_quads(ast_statement_list *s) {
    int last_label = sym_tab->get_next_label();
    quad_list *q = new quad_list(last_label);

    if(s != NULL) {
        s->generate_quads(*q);
    }

    (*q) += new quadruple(q_label, last_label, NULL_SYM, NULL_SYM);
    return q;
}

/* printing methods */

void quadruple::print(ostream &o) {
    o << "    ";
    o.flags(ios::left);
    
    switch (op_code) {
        case q_rload:
            o << setw(11) << "q_rload"
            << setw(11) << int1
            << setw(11) << "-"
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_iload:
            o << setw(11) << "q_iload"
            << setw(11) << int1
            << setw(11) << "-"
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_rplus:
            o << setw(11) << "q_rplus"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_iplus:
            o << setw(11) << "q_iplus"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_rminus:
            o << setw(11) << "q_rminus"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_iminus:
            o << setw(11) << "q_iminus"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_rmult:
            o << setw(11) << "q_rmult"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_imult:
            o << setw(11) << "q_imult"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_rdiv:
            o << setw(11) << "q_rdiv"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_idiv:
            o << setw(11) << "q_idiv"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_req:
            o << setw(11) << "q_req"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_ieq:
            o << setw(11) << "q_ieq"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_rlt:
            o << setw(11) << "q_rlt"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_ilt:
            o << setw(11) << "q_ilt"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_rgt:
            o << setw(11) << "q_rgt"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_igt:
            o << setw(11) << "q_igt"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_rstore:
            o << setw(11) << "q_rstore"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << "-"
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_istore:
            o << setw(11) << "q_istore"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << "-"
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_call:
            o << setw(11) << "q_call"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << int2
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_rreturn:
            o << setw(11) << "q_rreturn"
            << setw(11) << int1
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << "-";
            break;
        case q_ireturn:
            o << setw(11) << "q_ireturn"
            << setw(11) << int1
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << "-";
            break;
        case q_lindex:
            o << setw(11) << "q_lindex"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_rrindex:
            o << setw(11) << "q_rrindex"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_irindex:
            o << setw(11) << "q_irindex"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << sym_tab->get_symbol(sym3);
            break;
        case q_jmp:
            o << setw(11) << "q_jmp"
            << setw(11) << int1
            << setw(11) << "-"
            << setw(11) << "-";
            break;
        case q_jmpf:
            o << setw(11) << "q_jmpf"
            << setw(11) << int1
            << setw(11) << sym_tab->get_symbol(sym2)
            << setw(11) << "-";
            break;
        case q_param:
            o << setw(11) << "q_param"
            << setw(11) << sym_tab->get_symbol(sym1)
            << setw(11) << "-"
            << setw(11) << "-";
            break;
        case q_label:
            o << setw(11) << "q_label"
            << setw(11) << int1
            << setw(11) << "-"
            << setw(11) << "-";
            break;
        case q_nop:
            o << setw(11) << "q_nop"
            << setw(11) << "-"
            << setw(11) << "-"
            << setw(11) << "-";
            break;
        default:
            o << "unknown (" << (int)op_code << ")";
    }

    o.flags(ios::right);
}

void quad_list::print(ostream &o) {
    quad_list_element *e;
    o << short_symbols;

    quad_nr = 1;
    e = head;

    while(e != NULL) {
        o << setw(5) << quad_nr << e->data << endl;
        e = e->next;
        quad_nr++;
    }

    o << long_symbols;
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

ostream &operator<<(ostream &o, quad_list *q_list) {
    if(q_list != NULL) {
        q_list->print(o);
    }
    else {
        o << "  Quad list: NULL\n";
    }
    return o;
}