#include "optimize.hh"

ast_optimizer *optimizer = new ast_optimizer();

void ast_optimizer::do_optimize(ast_statement_list *body) {
    if(body != NULL) {
        body->optimize();
    }
}

bool ast_optimizer::is_binop(ast_expression *node) {
    // TODO: OR, AND, MOD, etc...
    switch(node->tag) {
        case AST_ADD:
        case AST_SUB:
        case AST_MULT:
        case AST_DIV:
            return true;
        default:
            return false;
    }
}

void ast_node::optimize() {
    fatal("Trying to optimize abstract class ast_node");
}

void ast_statement::optimize() {
    fatal("Trying to optimize abstract class ast_statement");
}

void ast_expression::optimize() {
    fatal("Trying to optimize abstract class ast_expression");
}

void ast_lval::optimize() {
    fatal("Trying to optimize abstract class ast_lval");
}

void ast_binary_operation::optimize() {
    fatal("Trying to optimize abstract class ast_binary_operation");
}

void ast_binary_relation::optimize() {
    fatal("Trying to optimize abstract class ast_binary_relation");
}

void ast_statement_list::optimize() {
    if(preceding != NULL) {
        preceding->optimize();
    }
    if(last_stmt != NULL) {
        last_stmt->optimize();
    }
}

void ast_expression_list::optimize() {
    if(preceding != NULL) {
        preceding->optimize();
    }
    if(last_expr != NULL) {
        last_expr = optimizer->fold_constants(last_expr);
    }
}

void ast_elseif_list::optimize() {
    if(preceding != NULL) {
        preceding->optimize();
    }
    if(last_elseif != NULL) {
        last_elseif->optimize();
    }
}

void ast_id::optimize() {

}

void ast_indexed::optimize() {
    if(index) {
        index = optimizer->fold_constants(index);
    }
}

/* helper functions */

long get_id_int_val(ast_expression* node) {
    if(node->tag == AST_ID) {
        sym_index index = node->get_ast_id()->sym_p;
        constant_symbol* sym = sym_tab->get_symbol(index)->get_constant_symbol();
        return sym->const_value.ival;
    }

    return node->get_ast_int()->value;
}

double get_id_real_val(ast_expression* node) {
    if(node->tag == AST_ID) {
        sym_index index = node->get_ast_id()->sym_p;
        constant_symbol* sym = sym_tab->get_symbol(index)->get_constant_symbol();
        return sym->const_value.rval;
    }

    return node->get_ast_real()->value;
}

bool ast_optimizer::is_const(ast_expression *node) {
    switch(node->tag) {
        case AST_INT:
        case AST_REAL:
            return true;
        case AST_ID:
            return sym_tab->get_symbol_tag(node->get_ast_id()->sym_p) == SYM_CONST;
        default:
            return false;
    }
}

ast_expression *ast_optimizer::fold_constants(ast_expression *node) {
    // TODO: This is just bad code, rewrite it
    node->optimize();

    if(is_binop(node)) {
        ast_binary_operation *binop = node->get_ast_binary_operation();
        ast_expression *lhs = fold_constants(binop->left);
        ast_expression *rhs = fold_constants(binop->right);

        if(!(is_const(lhs) && is_const(rhs))) {
            return node;
        }

        // TODO: MULT, AND, OR, MOD, etc...

        if(lhs->type == int_type && rhs->type == int_type) {
            long lhs_val = get_id_int_val(lhs);
            long rhs_val = get_id_int_val(rhs);

            switch(binop->tag) {
                case AST_ADD:
                    return new ast_int(binop->pos, lhs_val + rhs_val);
                case AST_SUB:
                    return new ast_int(binop->pos, lhs_val - rhs_val);
                case AST_MULT:
                    return new ast_int(binop->pos, lhs_val * rhs_val);
                case AST_DIV:
                    return new ast_int(binop->pos, lhs_val / rhs_val);
                default:
                    return node;
            }
        }
        else if(lhs->type == real_type && rhs->type == real_type) {
            long lhs_val = get_id_real_val(lhs);
            long rhs_val = get_id_real_val(rhs);

            switch(binop->tag) {
                case AST_ADD:
                    return new ast_real(binop->pos, lhs_val + rhs_val);
                case AST_SUB:
                    return new ast_real(binop->pos, lhs_val - rhs_val);
                case AST_MULT:
                    return new ast_real(binop->pos, lhs_val * rhs_val);
                case AST_DIV:
                    return new ast_real(binop->pos, lhs_val / rhs_val);
                default:
                    return node;
            }
        }
    }

    return node;
}

void ast_add::optimize() {
    if(left) {
        left->optimize();
        left = optimizer->fold_constants(left);
    }

    if(right) {
        right->optimize();
        right = optimizer->fold_constants(right);
    }
}

void ast_sub::optimize() {
    if(left) {
        left->optimize();
        left = optimizer->fold_constants(left);
    }

    if(right) {
        right->optimize();
        right = optimizer->fold_constants(right);
    }
}

void ast_mult::optimize() {
    if(left) {
        left->optimize();
        left = optimizer->fold_constants(left);
    }

    if(right) {
        right->optimize();
        right = optimizer->fold_constants(right);
    }
}

void ast_div::optimize() {
    if(left) {
        left->optimize();
        left = optimizer->fold_constants(left);
    }

    if(right) {
        right->optimize();
        right = optimizer->fold_constants(right);
    }
}

// TODO: OR, AND, NOT, MOD, etc...

void ast_equal::optimize() {
    if(left) {
        left->optimize();
        left = optimizer->fold_constants(left);
    }

    if(right) {
        right->optimize();
        right = optimizer->fold_constants(right);
    }
}

void ast_less_than::optimize() {
    if(left) {
        left->optimize();
        left = optimizer->fold_constants(left);
    }

    if(right) {
        right->optimize();
        right = optimizer->fold_constants(right);
    }
}

void ast_greater_than::optimize() {
    if(left) {
        left->optimize();
        left = optimizer->fold_constants(left);
    }

    if(right) {
        right->optimize();
        right = optimizer->fold_constants(right);
    }
}

void ast_procedure_call::optimize() {
    if(param_list) {
        param_list->optimize();
    }
}

// TODO: assign, not eq

void ast_while::optimize() {
    if(condition) {
        condition->optimize();
        condition = optimizer->fold_constants(condition);
    }

    if(body) {
        body->optimize();
    }
}

void ast_if::optimize() {
    if(condition) {
        condition->optimize();
        condition = optimizer->fold_constants(condition);
    }

    if(body) {
        body->optimize();
    }

    if(elseif_list) {
        elseif_list->optimize();
    }

    if(else_body) {
        else_body->optimize();
    }
}

void ast_return::optimize() {
    if(value) {
        value->optimize();
        value = optimizer->fold_constants(value);
    }
}

void ast_function_call::optimize() {
    if(param_list) {
        param_list->optimize();
    }
}

// TODO: umin

void ast_elseif::optimize() {
    if(condition) {
        condition->optimize();
        condition = optimizer->fold_constants(condition);
    }

    if(body) {
        body->optimize();
    }
}

void ast_int::optimize() {
    // Nothing to do
}

void ast_real::optimize() {
    // Nothing to do
}

void ast_cast::optimize() {
    // TODO: think about this
}

void ast_procedure_head::optimize() {
    fatal("ast_procedure_head::optimize() called");
}

void ast_function_head::optimize() {
    fatal("ast_function_head::optimize() called");
}