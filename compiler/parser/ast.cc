#include "ast.hh"

int ast_node::indent_level = 0;
bool ast_node::branches[10000];

ast_node::ast_node(position_information *p) : pos(p) {
    tag = AST_NODE;
}

ast_statement::ast_statement(position_information *p) : ast_node(p) {
    tag = AST_STATEMENT;
}

ast_expression::ast_expression(position_information *p) : ast_node(p) {
    tag = AST_EXPRESSION;
    type = void_type; // will be changed later, or else it's an error
}

ast_expression::ast_expression(position_information *p, sym_index s) : ast_node(p), type(s) {
    tag = AST_EXPRESSION;
}

ast_binary_relation::ast_binary_relation(position_information *p, ast_expression *l, ast_expression *r) : ast_expression(p, int_type), left(l), right(r) {
    tag = AST_BINARY_RELATION;
}

ast_binary_operation::ast_binary_operation(position_information *p, ast_expression *l, ast_expression *r) : ast_expression(p), left(l), right(r) {
    tag = AST_BINARY_OP;
}

ast_lval::ast_lval(position_information *p) : ast_expression(p) {
    tag = AST_LVAL;
}

ast_lval::ast_lval(position_information *p, sym_index s) : ast_expression(p, s) {
    tag = AST_LVAL;
}

ast_elseif::ast_elseif(position_information *p, ast_expression *c, ast_statement_list *b) : ast_node(p), condition(c), body(b) {
    tag = AST_ELSEIF;
}

ast_expression_list::ast_expression_list(position_information *p, ast_expression *l) : ast_node(p), last_expr(l) {
    tag = AST_EXPRESSION_LIST;
    preceding = NULL;
}

ast_expression_list::ast_expression_list(position_information *p, ast_expression *l, ast_expression_list *prev) : ast_node(p), last_expr(l), preceding(prev) {
    tag = AST_EXPRESSION_LIST;
}

ast_statement_list::ast_statement_list(position_information *p, ast_statement *h) : ast_node(p), last_stmt(h) {
    tag = AST_STATEMENT_LIST;
    preceding = NULL;
}

ast_statement_list::ast_statement_list(position_information *p, ast_statement *h, ast_statement_list *t) : ast_node(p), last_stmt(h), preceding(t) {
    tag = AST_STATEMENT_LIST;
}

ast_elseif_list::ast_elseif_list(position_information *p, ast_elseif *h) : ast_node(p), last_elseif(h) {
    tag = AST_ELSEIF_LIST;
    preceding = NULL;
}

ast_elseif_list::ast_elseif_list(position_information *p, ast_elseif *h, ast_elseif_list *t) : ast_node(p), last_elseif(h), preceding(t) {
    tag = AST_ELSEIF_LIST;
}

ast_procedure_call::ast_procedure_call(position_information *p, ast_id *i, ast_expression_list *par) : ast_statement(p), id(i), param_list(par) {
    tag = AST_PROCEDURE_CALL;
}

// TODO: assignment

ast_while::ast_while(position_information *p, ast_expression *c, ast_statement_list *b) : ast_statement(p), condition(c), body(b) {
    tag = AST_WHILE;
}

ast_if::ast_if(position_information *p, ast_expression *c, ast_statement_list *b, ast_elseif_list *eil, ast_statement_list *eb) : ast_statement(p), condition(c), body(b), elseif_list(eil), else_body(eb) {
    tag = AST_IF;
}

ast_return::ast_return(position_information *p) : ast_statement(p) {
    tag = AST_RETURN;
    value = NULL;
}

ast_return::ast_return(position_information *p, ast_expression *v) : ast_statement(p), value(v) {
    tag = AST_RETURN;
}

ast_function_call::ast_function_call(position_information *p, ast_id *i, ast_expression_list *par) : ast_expression(p), id(i), param_list(par) {
    tag = AST_FUNCTION_CALL;
}

// TODO: uminus if neeccesary
// TODO: not if neccesary

ast_equal::ast_equal(position_information *p, ast_expression *l, ast_expression *r) : ast_binary_relation(p, l, r) {
    tag = AST_BINARY_RELATION;
}

// TODO: not equal if neccesary

ast_less_than::ast_less_than(position_information *p, ast_expression *l, ast_expression *r) : ast_binary_relation(p, l, r) {
    tag = AST_LESS_THAN;
}

ast_greater_than::ast_greater_than(position_information *p, ast_expression *l, ast_expression *r) : ast_binary_relation(p, l, r) {
    tag = AST_GREATER_THAN;
}

ast_add::ast_add(position_information *p, ast_expression *l, ast_expression *r) : ast_binary_operation(p, l, r) {
    tag = AST_ADD;
}

ast_sub::ast_sub(position_information *p, ast_expression *l, ast_expression *r) : ast_binary_operation(p, l, r) {
    tag = AST_SUB;
}

// TODO: or if neccesary
// TODO: and if neccesary

ast_mult::ast_mult(position_information *p, ast_expression *l, ast_expression *r) : ast_binary_operation(p, l, r) {
    tag = AST_MULT;
}

ast_div::ast_div(position_information *p, ast_expression *l, ast_expression *r) : ast_binary_operation(p, l, r) {
    tag = AST_DIV;
}

// TODO: idiv if neccesary
// TODO: mod if neccesary

ast_id::ast_id(position_information *p, sym_index s) : ast_lval(p), sym_p(s) {
    tag = AST_ID;
}

ast_indexed::ast_indexed(position_information *p, ast_id *i, ast_expression *n) : ast_lval(p), id(i), index(n) {
    tag = AST_INDEXED;
}

ast_int::ast_int(position_information *p, long i) : ast_expression(p, int_type), value(i) {
    tag = AST_INT;
}

ast_real::ast_real(position_information *p, double r) : ast_expression(p, real_type), value(r) {
    tag = AST_REAL;
}

ast_cast::ast_cast(position_information *p, ast_expression *n) : ast_expression(p, real_type), expr(n) {
    tag = AST_CAST;
}

ast_function_head::ast_function_head(position_information *p, sym_index s) : ast_node(p), sym_p(s) {
    tag = AST_FUNCTION_HEAD;
}

ast_procedure_head::ast_procedure_head(position_information *p, sym_index s) : ast_node(p), sym_p(s) {
    tag = AST_PROCEDURE_HEAD;
}

/* printing methods */

void ast_node::begin_child(ostream& o) {
    indent(o);
    o << "+-";
    branches[indent_level] = true;
    indent_more();
}

void ast_node::end_child(ostream& o) {
    o << "";
    indent_less();
    if(branches[indent_level]) {
        branches[indent_level] = false;
    }
}

void ast_node::last_child(ostream& o) {
    indent(o);
    o << "+-";
    branches[indent_level] = false;
    indent_more();
}

void ast_node::indent(ostream& o) {
    for(int i = 0; i < indent_level; i++) {
        if(branches[i]) {
            o << "|";
        }
        else {
            o << " ";
        }
    }
}

void ast_node::indent_more() {
    indent_level += 2;
}

void ast_node::indent_less() {
    indent_level -= 2;
}

void ast_node::print(ostream& o) {
    o << "ast_node";
}

void ast_node::xprint(ostream& o, string s) {
    o << "ast_node (" << s << ")";
}

void ast_statement::print(ostream& o) {
    o << "Statement";
}

void ast_expression::print(ostream& o) {
    o << "Expression [" << short_symbols << sym_tab->get_symbol(type) << long_symbols << "]\n";
}

void ast_binary_relation::print(ostream& o) {
    o << "Binary Relation";
}

void ast_binary_relation::xprint(ostream &o, string s) {
    o << s << " (left, right) [" << short_symbols << sym_tab->get_symbol(type) << long_symbols << "]\n";

    begin_child(o);
    o << left << endl;
    end_child(o);
    last_child(o);
    o << right;
    end_child(o);
}

void ast_binary_operation::print(ostream &o) {
    o << "Binary Operation";
}

void ast_binary_operation::xprint(ostream &o, string s) {
    o << s << " (left, right) [" << short_symbols << sym_tab->get_symbol(type) << long_symbols << "]\n";

    begin_child(o);
    o << left << endl;
    end_child(o);
    last_child(o);
    o << right;
    end_child(o);
}

void ast_lval::print(ostream& o) {
    o << "Lvalue";
}

void ast_elseif::print(ostream& o) {
    o << "Elseif (condition, body)\n";
    begin_child(o);
    o << condition << endl;
    end_child(o);
    last_child(o);
    o << body;
    end_child(o);
}

void ast_expression_list::print(ostream& o) {
    o << "Expression List (preceding, last_expression)\n";
    begin_child(o);
    o << preceding << endl;
    end_child(o);
    last_child(o);
    o << last_expr;
    end_child(o);
}

void ast_statement_list::print(ostream& o) {
    o << "Statement List (preceding, last_statement)\n";
    begin_child(o);
    o << preceding << endl;
    end_child(o);
    last_child(o);
    o << last_stmt;
    end_child(o);
}

void ast_elseif_list::print(ostream& o) {
    o << "Elseif List (preceding, last_elseif)\n";
    begin_child(o);
    o << preceding << endl;
    end_child(o);
    last_child(o);
    o << last_elseif;
    end_child(o);
}

void ast_procedure_call::print(ostream& o) {
    o << "Procedure Call (procedure, args)\n";
    begin_child(o);
    o << id << long_symbols << endl;
    end_child(o);
    last_child(o);
    o << param_list;
    end_child(o);
}

// TODO: Ast assign

void ast_while::print(ostream& o) {
    o << "While (condition, body)\n";
    begin_child(o);
    o << condition << endl;
    end_child(o);
    last_child(o);
    o << body;
    end_child(o);
}

void ast_if::print(ostream& o) {
    o << "If (condition, body, elseif, else)\n";
    begin_child(o);
    o << condition << endl;
    end_child(o);
    begin_child(o);
    o << body << endl;
    end_child(o);
    begin_child(o);
    o << elseif_list << endl;
    end_child(o);
    last_child(o);
    o << else_body;
    end_child(o);
}

void ast_return::print(ostream& o) {
    o << "Return (value)\n";
    begin_child(o);
    o << value;
    end_child(o);
}

void ast_function_call::print(ostream& o) {
    o << "Function Call (function, args) [" << short_symbols << sym_tab->get_symbol(type) << "]\n";
    begin_child(o);
    o << id << long_symbols << endl;
    end_child(o);
    last_child(o);
    o << param_list;
    end_child(o);
}

// TODO: uminus
// TODO: not
// TODO: notequal
// TODO: and
// TODO: or
// TODO: idiv
// TODO: mod

void ast_equal::print(ostream& o) {
    xprint(o, "Equal");
}

void ast_less_than::print(ostream& o) {
    xprint(o, "Less Than");
}

void ast_greater_than::print(ostream& o) {
    xprint(o, "Greater Than");
}

void ast_add::print(ostream& o) {
    xprint(o, "Add");
}

void ast_sub::print(ostream& o) {
    xprint(o, "Sub");
}

void ast_mult::print(ostream& o) {
    xprint(o, "Mult");
}

void ast_div::print(ostream& o) {
    xprint(o, "Div");
}

void ast_id::print(ostream& o) {
    o << "Id (" << short_symbols << sym_tab->get_symbol(sym_p) << ") " << "[" << sym_tab->get_symbol(type) << "]" << long_symbols;
}

void ast_indexed::print(ostream& o) {
    o << "Indexed (id, index)\n";
    begin_child(o);
    o << short_symbols << id << long_symbols << endl;
    end_child(o);
    last_child(o);
    o << index;
    end_child(o);
}

void ast_int::print(ostream& o) {
    o << "Int [" << value << "]";
}

void ast_real::print(ostream& o) {
    o << "Real [" << value << "]";
}

void ast_cast::print(ostream& o) {
    o << "Cast [" << short_symbols << sym_tab->get_symbol(type) << long_symbols << "]\n";
    last_child(o);
    o << expr;
    end_child(o);
}

void ast_function_head::print(ostream& o) {
    o << "Function Head (" << short_symbols << sym_tab->get_symbol(sym_p) << long_symbols << ")";
}

void ast_procedure_head::print(ostream& o) {
    o << "Procedure Head (" << short_symbols << sym_tab->get_symbol(sym_p) << long_symbols << ")";
}

ostream& operator<<(ostream& o, ast_node *node) {
    if(node == NULL) {
        o << "NULL" << flush;
    }
    else {
        node->print(o);
    }
    return o;
}