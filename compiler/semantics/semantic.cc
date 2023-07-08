#include "semantic.hh"

semantic *type_checker = new semantic();

/*
used to check that all functions contain return statements
*/
static bool has_return = false;

void semantic::do_typecheck(symbol *env, ast_statement_list *body) {
    has_return = false;
    if(body) {
        body->type_check();
    }

    /*
    this is what has_return is needed for
    all other cases are already handled
    */
    if(env->tag == SYM_FUNC && !has_return) {
        // TODO: overload do_typecheck() for procedure- and functionhead
        if(body != NULL) {
            type_error(body->pos) << "A function must return a value.\n";
        }
        else {
            type_error() << "A function must return a value.\n";
        }
    }
}

bool semantic::chk_param(ast_id *env, parameter_symbol *formals, ast_expression_list *actuals) {
    // TODO: Rewrite this, really bad
    position_information *pos;

    if(actuals) {
        pos = actuals->pos;
    }
    else {
        pos = env->pos;
    }

    while(formals || actuals) {
        if(!actuals) {
            type_error(pos) << "Too few parameters.\n";
            break;
        }
        else if(!formals) {
            type_error(pos) << "Too many parameters.\n";
            break;
        }
        
        if(formals->type != actuals->last_expr->type_check()) {
            type_error(pos) << "Parameter type mismatch.\n";
            return false;
        }

        formals = formals->preceding;
        actuals = actuals->preceding;
    }

    return true;
}

void semantic::check_params(ast_id *call_id, ast_expression_list *param_list) {
    symbol *tmp = sym_tab->get_symbol(call_id->sym_p);

    if(tmp->tag == SYM_FUNC) {
        function_symbol *func = tmp->get_function_symbol();
        parameter_symbol *decl_params = func->last_param;
        chk_param(call_id, decl_params, param_list);
    }
    else if(tmp->tag == SYM_PROC) {
        procedure_symbol *proc = tmp->get_procedure_symbol();
        parameter_symbol *decl_params = proc->last_param;
        chk_param(call_id, decl_params, param_list);
    }
    else {
        type_error(call_id->pos) << "Identifier not callable" << endl;
    }
}

sym_index ast_node::type_check() {
    fatal("Trying to type check abstract class ast_node");
    return void_type;
}

sym_index ast_statement::type_check() {
    fatal("Trying to type check abstract class ast_statement");
    return void_type;
}

sym_index ast_expression::type_check() {
    fatal("Trying to type check abstract class ast_expression");
    return void_type;
}

sym_index ast_lval::type_check() {
    fatal("Trying to type check abstract class ast_lval");
    return void_type;
}

sym_index ast_binary_operation::type_check() {
    fatal("Trying to type check abstract class ast_binary_operation");
    return void_type;
}

sym_index ast_binary_relation::type_check() {
    fatal("Trying to type check abstract class ast_binary_relation");
    return void_type;
}

sym_index ast_statement_list::type_check() {
    if(preceding != NULL) {
        preceding->type_check();
    }
    if(last_stmt != NULL) {
        last_stmt->type_check();
    }
    return void_type;
}

sym_index ast_expression_list::type_check() {
    if(preceding != NULL) {
        preceding->type_check();
    }
    if(last_expr != NULL) {
        last_expr->type_check();
    }
    return void_type;
}

sym_index ast_elseif_list::type_check() {
    if(preceding != NULL) {
        preceding->type_check();
    }
    if(last_elseif != NULL) {
        last_elseif->type_check();
    }
    return void_type;
}

// NOTE: Write description
sym_index ast_id::type_check() {
    if(sym_tab->get_symbol(sym_p)->tag != SYM_TYPE) {
        return type;
    }
    return sym_p;
}

sym_index ast_indexed::type_check() {
    symbol *arr = sym_tab->get_symbol(id->sym_p);

    if(arr->tag != SYM_ARRAY) {
        error(pos) << "Identifier is not an array" << endl;
        return void_type;
    }

    if(index->type_check() != int_type) {
        type_error(index->pos) << "Index must be of type integer" << endl;
    }

    return arr->type;
}

// NOTE: Write description
sym_index semantic::check_binop1(ast_binary_operation *node)
{
    sym_index left_type = node->left->type_check();
    sym_index right_type = node->right->type_check();

    bool fail = false;
    if (left_type == void_type) {
        type_error(node->left->pos) << "First operand is of type void\n";
        fail = true;
    }

    if (right_type == void_type) {
        type_error(node->right->pos) << "Second operand is of type void\n";
        fail = true;
    }
    
    if ( left_type != right_type && !fail ) {
        if (left_type == int_type) {
            node->left = new ast_cast(node->left->pos, node->left);
            return real_type;
        }
        else {
            node->right = new ast_cast(node->right->pos, node->right);
            return real_type;
        }
    }

    return left_type;
}


sym_index ast_add::type_check() {
    type = type_checker->check_binop1(this);
    return type;
}

sym_index ast_sub::type_check() {
    type = type_checker->check_binop1(this);
    return type;
}

sym_index ast_mult::type_check() {
    type = type_checker->check_binop1(this);
    return type;
}

// NOTE: Write description
sym_index ast_div::type_check() {
    sym_index left_type = left->type_check();
    sym_index right_type = right->type_check();

    if(left_type == void_type) {
        type_error(left->pos) << "Left operand must not be void" << endl;
    }

    if(right_type == void_type) {
        type_error(right->pos) << "Right operand must not be void" << endl;
    }

    if(left_type == int_type) {
        left = new ast_cast(left->pos, left);
    }
    
    if(right_type == int_type) {
        right = new ast_cast(right->pos, right);
    }

    type = real_type;
    return type;
}

// NOTE: Wrtie description
sym_index semantic::check_binop2(ast_binary_operation* node, string s) {
    if(node->left->type_check() != int_type || node->right->type_check() != int_type) {
        type_error(node->pos) << s << endl;
    }

    return int_type;
}

sym_index ast_or::type_check() {
    type = type_checker->check_binop2(this, "MSG"); // TODO: Change message
    return type;
}

sym_index ast_and::type_check() {
    type = type_checker->check_binop2(this, "MSG"); // TODO: Change message
    return type;
}

sym_index ast_mod::type_check() {
    type = type_checker->check_binop2(this, "MSG"); // TODO: Change message
    return type;
}
// TODO: Implement alt div

sym_index semantic::check_binrel(ast_binary_relation *node) {
    sym_index left_type = node->left->type_check();
    sym_index right_type = node->right->type_check();
   
    if (left_type != right_type) {
        if (left_type != real_type) {
            node->left = new ast_cast(node->left->pos, node->left);
        }

        if (right_type != real_type) {
            node->right = new ast_cast(node->right->pos, node->right);
        }
    }

    return int_type;
}

sym_index ast_not_equal::type_check() {
    return type_checker->check_binrel(this);
}

sym_index ast_equal::type_check() {
    return type_checker->check_binrel(this);
}

sym_index ast_less_than::type_check() {
    return type_checker->check_binrel(this);
}

sym_index ast_greater_than::type_check() {
    return type_checker->check_binrel(this);
}

sym_index ast_procedure_call::type_check() {
    type_checker->check_params(id, param_list);
    return void_type;
}

sym_index ast_assign::type_check() {
    sym_index lhs_type = lhs->type_check();
    sym_index rhs_type = rhs->type_check();

    if(lhs_type == void_type) {
        type_error(lhs->pos) << "Left operand must not be void" << endl;
    }

    if(rhs_type == void_type) {
        type_error(rhs->pos) << "Right operand must not be void" << endl;
    }

    if(lhs_type != rhs_type) {
        if(lhs_type == real_type && rhs_type == int_type) {
            rhs = new ast_cast(rhs->pos,rhs);
        }
        // TODO: error handling
    }
    
    return void_type;
}

sym_index ast_while::type_check() {
    if(condition->type_check() != int_type) {
        type_error(condition->pos) << "Condition must be of type integer" << endl;
    }

    if(body != NULL) {
        body->type_check();
    }

    return void_type;
}

sym_index ast_if::type_check() {
    if(condition->type_check() != int_type) {
        type_error(condition->pos) << "Condition must be of type integer" << endl;
    }

    if(body != NULL) {
        body->type_check();
    }

    if(elseif_list != NULL) {
        elseif_list->type_check();
    }

    if(else_body != NULL) {
        else_body->type_check();
    }

    return void_type;
}

// NOTE: Write description
sym_index ast_return::type_check() {
    has_return = true;

    symbol *tmp = sym_tab->get_symbol(sym_tab->current_environment());

    if(value == NULL) {
        if(tmp->tag != SYM_PROC) {
            type_error(pos) << "Function must return a value" << endl;
        }
        return void_type;
    }

    sym_index value_type = value->type_check();

    if(tmp->tag != SYM_FUNC) {
        type_error(pos) << "Procedure must not return a value" << endl;
        return void_type;
    }

    function_symbol *func = tmp->get_function_symbol();

    if(func->type != value_type) {
        type_error(value->pos) << "Bad return type from function." << endl;
    }

    return void_type;
}

sym_index ast_function_call::type_check() {
    type_checker->check_params(id, param_list);
    return type;
}

// TODO: Implement uminus if nessessary

sym_index ast_not::type_check() {
    sym_index t = expr->type_check();
    
    if(t == void_type) {
        type_error(pos) << "Type: NULL" << endl;
    }

    return t;
}

sym_index ast_elseif::type_check() {
    if(condition->type_check() != int_type) {
        type_error(condition->pos) << "Condition must be of type integer" << endl;
    }

    if(body != NULL) {
        body->type_check();
    }

    return void_type;
}

sym_index ast_int::type_check() {
    return int_type;
}

sym_index ast_real::type_check() {
    return real_type;
}