#ifndef __OPTIMIZE_HH__
#define __OPTIMIZE_HH__

#include "../parser/ast.hh"

class ast_optimizer;

extern ast_optimizer *optimizer; // defined in optimize.cc

// TODO: Write documentation for whole file
class ast_optimizer {
public:
    void do_optimize(ast_statement_list *body);

    bool is_binop(ast_expression *);
    bool is_const(ast_expression *node);

    ast_expression *fold_constants(ast_expression *);
};

#endif