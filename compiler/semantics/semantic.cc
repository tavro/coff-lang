#include "semantic.hh"

semantic *type_checker = new semantic();

/*
used to check that all functions contain return statements
*/
static bool has_return = false;

void semantic:do_typecheck(symbol *env, ast_statement_list *body) {
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

// TODO: Implement rest