#ifndef __SEMANTIC_HH__
#define __SEMANTIC_HH__

#include "../parser/ast.hh"

class semantic;

extern semantic *type_checker; // defined in semantic.cc

class semantic {
private:
    /*
    checks formal vs actual params
    */
    bool chk_param(ast_id *, parameter_symbol *, ast_expression_list *);

public:
    /*
    type checks params and calles chk_param
    */
    void check_params(ast_id *, ast_expression_list *);

    void do_typecheck(symbol *env, ast_statement_list *body);

    sym_index check_binop1(ast_binary_operation *);
    sym_index check_binop2(ast_binary_operation *, string);

    sym_index check_binrel(ast_binary_relation *);
};

#endif