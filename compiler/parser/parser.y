%{
#include <iostream>
#include "../semantics/semantic.hh"
#include "../codegen/codegen.hh"
#include "../optimizer/optimize.hh"

extern char *yytext;
extern int error_count;         // defined in error.cc
extern symbol_table *sym_tab;   // defined in symtab.cc
extern semantic *type_checker;
extern code_generator *code_gen;

extern int yylex();
extern void yyerror(string);

extern bool print_ast;
extern bool print_quads;
extern bool type_check;
extern bool optimize;
extern bool quads;
extern bool assembler;

#define YYDEBUG 1
%}

%union {
    ast_node            *ast;
    ast_id              *id;
    ast_statement_list  *statement_list;
    ast_statement       *statement;
    ast_expression_list *expression_list;
    ast_expression      *expression;
    ast_elseif_list     *elseif_list;
    ast_elseif          *elseif;
    ast_lval            *lval;
    ast_function_call   *function_call;
    ast_function_head   *function_head;
    ast_procedure_head  *procedure_head;
    ast_int             *integer;
    ast_real            *real;

    long                ival;
    double              rval;
    pool_index          str;
    pool_index          pool_p;
}

// NOTE: Desc may be a good idea
%type <id>              id const_id rvar_id array_id proc_id func_id type_id // TODO: lvar_id
%type <statement_list>  stmt_list comp_stmt else_part
%type <statement>       stmt
%type <expression_list> opt_param_list param_list opt_expr_list expr_list
%type <expression>      expr term factor simple_expr rvar
%type <elseif_list>     elseif_list
%type <elseif>          elseif
// TODO: %type <lval>            lvar
%type <param>           param
%type <function_call>   func_call
%type <function_head>   func_decl func_head
%type <procedure_head>  prog_decl prog_head proc_decl proc_head
%type <integer>         integer
%type <real>            real

%token T_EOF T_ERROR T_DOT T_SEMICOLON T_EQ T_COLON T_LEFTBRACKET
%token T_RIGHTBRACKET T_LEFTPAR T_RIGHTPAR T_COMMA T_LESSTHAN T_GREATERTHAN
%token T_ADD T_SUB T_MULT T_DIV T_IF T_VAR // TODO: OF, DO, ASSIGN, NOT EQ, OR
%token T_ELSE T_CONST T_ARRAY // TODO: end, and, not, then, mod
%token T_WHILE T_ELSEIF T_RETURN // TODO: begin
%token T_STRING
%token <pool_p> T_ID T_PROGRAM T_PROCEDURE T_FUNCTION
%token <ival> T_INT
%token <rval> T_REAL

// TODO: not, and, mod, or
%left T_ADD T_SUB
%left T_MULT T_DIV

%start program

// TODO: Implement rules
%%

program             : prog_decl subprog_part comp_stmt T_DOT
                    {
                        symbol *env = sym_tab->get_symbol($1->sym_p);

                        // following code depends on flags passed to compiler
                        if(type_check) {
                            type_checker->do_typecheck(env, $3);
                        }

                        if(print_ast) {
                            cout << "Unoptimized AST for global level" << endl;
                            cout << (ast_statement_list *)$3 << endl;
                        }

                        if(optimize) {
                            optimizer->do_optimize($3);
                            if(print_ast) {
                                cout << "\nOptimized AST for global level" << endl;
                                cout << (ast_statement_list *)$3 << endl;
                            }
                        }

                        if(error_count == 0) {
                            if(quads) {
                                quad_list *q = $1->do_quads($3);
                                if(print_quads) {
                                    cout << "\nQuad list for global level" << endl;
                                    cout << (quad_list *)q << endl;
                                }

                                if(assembler) {
                                    cout << "Generating assembler, global level" << endl;
                                    code_gen->generate_assembler(q, env);
                                }
                            }
                        }
                        else {
                            cout << "Found " << error_count << " errors. "
                                 << "Compilation aborted.\n";
                        }

                        sym_tab->close_scope();
                    }
                    ;

prog_decl           : prog_head T_SEMICOLON const_part var_part
                    {
                        $$ = $1;
                    }
                    ;

prog_head           : T_PROGRAM T_ID
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);

                        sym_index index = sym_tab->enter_procedure(pos, $2);

                        $$ = new ast_procedure_head(pos, index);
                        sym_tab->open_scope();
                    }
                    ;

const_part          : T_CONST const_decls
                    | error const_decls
                    | /* empty */
                    ;

const_decls         : const_decl
                    | const_decls const_decl
                    ;

const_decl          : T_ID T_EQ integer T_SEMICOLON
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        sym_tab->enter_constant(pos, $1, int_type, $3->value);
                    }
                    | T_ID T_EQ real T_SEMICOLON
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        sym_tab->enter_constant(pos, $1, real_type, $3->value);
                    }
                    | T_ID T_EQ T_STRING T_SEMICOLON
                    {
                        // TODO: Not supported in Coff yet.
                    }
                    | T_ID T_EQ const_id T_SEMICOLON
                    {
                        /*
                        EXAMPLE:
                        const foo = 0;
                        const bar = foo;
                        */
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        constant_symbol* sym = sym_tab->get_symbol($3->sym_p)->get_constant_symbol();

                        if($3->type == int_type) {
                            sym_tab->enter_constant(pos, $1, $3->type, sym->const_value.ival);
                        }
                        else {
                            sym_tab->enter_constant(pos, $1, $3->type, sym->const_value.rval);
                        }
                    }
                    | T_ID T_EQ error T_SEMICOLON
                    {
                        yyerrok;
                    }
                    ;

var_part            : T_VAR var_decls
                    | /* intentionally empty */
                    ;

var_decls           : var_decl
                    | var_decls var_decl
                    ;

var_decl            : T_ID T_COLON type_id T_SEMICOLON
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        sym_tab->enter_variable(pos, $1, $3->sym_p);
                    }
                    | T_ID T_COLON T_ARRAY T_LEFTBRACKET integer T_RIGHTBRACKET type_id T_SEMICOLON
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        sym_tab->enter_array(pos, $1, $7->sym_p, $5->value);
                    }
                    | T_ID T_COLON T_ARRAY T_LEFTBRACKET const_id T_RIGHTBRACKET type_id T_SEMICOLON
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        
                        /*
                        prevent entering real values for cardinality
                        */
                        symbol *tmp = sym_tab->get_symbol($5->sym_p);
                        if(tmp == NULL || tmp->tag != SYM_CONST) {
                            type_error(pos) << "bad index in array declaration: " << yytext << endl << flush;
                        }
                        else {
                            constant_symbol *con = tmp->get_constant_symbol();
                            if(con->type == int_type) {
                                sym_tab->enter_array(pos, $1, $7->sym_p, con->const_value.ival);
                            }
                            else {
                                sym_tab->enter_array(pos, $1, $7->sym_p, ILLEGAL_ARRAY_CARD);
                            }
                        }
                    }
                    ;

subprog_part        : subprog_decls
                    | /* intentionally empty */
                    ;
                
subprog_decls       : subprog_decl
                    | subprog_decls subprog_decl
                    ;

subprog_decl        : proc_decl subprog_part comp_stmt T_SEMICOLON
                    {
                        symbol *env = sym_tab->get_symbol($1->sym_p);

                        if(type_check) {
                            type_checker->do_typecheck(env, $3);
                        }

                        if(print_ast) {
                            cout << "\nUnoptimized AST for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                            cout << (ast_statement_list *)$3 << endl;
                        }

                        if(optimize) {
                            optimizer->do_optimize($3);
                            if(print_ast) {
                                cout << "\nOptimized AST for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                cout << (ast_statement_list*)$3 << endl;
                            }
                        }

                        if(error_count == 0) {
                            if(quads) {
                                quad_list *q = $1->do_quads($3);
                                if(print_quads) {
                                    cout << "\nQuad list for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                    cout << (quad_list *)q << endl;
                                }

                                if(assembler) {
                                    cout << "Generating assembler for procedure \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                    code_gen->generate_assembler(q, env);
                                }
                            }
                        }

                        sym_tab->close_scope();
                    }
                    | func_decl subprog_part comp_stmt T_SEMICOLON
                    {
                        symbol *env = sym_tab->get_symbol($1->sym_p);

                        if(type_check) {
                            type_checker->do_typecheck(env, $3);
                        }

                        if(print_ast) {
                            cout << "\nUnoptimized AST for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                            cout << (ast_statement_list *)$3 << endl;
                        }

                        if(optimize) {
                            optimizer->do_optimize($3);
                            if(print_ast) {
                                cout << "\nOptimized AST for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                cout << (ast_statement_list*)$3 << endl;
                            }
                        }

                        if(error_count == 0) {
                            if(quads) {
                                quad_list *q = $1->do_quads($3);
                                if(print_quads) {
                                    cout << "\nQuad list for \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                    cout << (quad_list *)q << endl;
                                }

                                if(assembler) {
                                    cout << "Generating assembler for procedure \"" << sym_tab->pool_lookup(env->id) << "\"" << endl;
                                    code_gen->generate_assembler(q, env);
                                }
                            }
                        }

                        sym_tab->close_scope();
                    }
                    ;

proc_decl           : proc_head opt_param_list T_SEMICOLON const_part var_part
                    {
                        $$ = $1;
                    }
                    ;

func_decl           : func_head opt_param_list T_COLON type_id T_SEMICOLON const_part var_part
                    {
                        sym_tab->get_symbol($1->sym_p)->type = $4->sym_p;
                        $$ = $1;
                    }
                    ;

proc_head           : T_PROCEDURE T_ID
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        sym_index proc_loc = sym_tab->enter_procedure(pos, $2);
                        sym_tab->open_scope();
                        
                        /*
                        this AST node is a temporary node
                        to provide the symbol table index
                        for proc
                        */
                        $$ = new ast_procedure_head(pos, proc_loc);
                    }
                    ;

func_head           : T_FUNCTION T_ID
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        sym_index func_loc = sym_tab->enter_procedure(pos, $2);
                        sym_tab->open_scope();
                        $$ = new ast_function_head(pos, func_loc);
                    }

opt_param_list      : T_LEFTPAR param_list T_RIGHTPAR
                    {
                        $$ = $2;
                    }
                    | T_LEFTPAR error T_RIGHTPAR
                    {
                        yyerrok;
                        $$ = NULL;
                    }
                    | /* intentionally empty */
                    {
                        $$ = NULL;
                    }
                    ;

param_list          : param
                    {
                        /*
                        we use expr_lists for params
                        */
                    }
                    | param_list T_SEMICOLON param
                    {
                    }
                    ;

param               : T_ID T_COLON type_id
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        
                        /*
                        param linking taken care of in enter_parameter
                        */
                        sym_index param_loc = sym_tab->enter_parameter(pos, $1, $3->sym_p);
                    }
                    ;

comp_stmt           : stmt_list
                    {
                        // TODO: Look over this, may need begin and end keywords
                        $$ = $1;
                    }
                    ;

stmt_list           : stmt
                    {
                        if($1 != NULL) {
                            $$ = new ast_statement_list($1->pos, $1);
                        }
                        else {
                            $$ = NULL;
                        }
                    }
                    | stmt_list T_SEMICOLON stmt
                    {
                        if($1 != NULL && $3 != NULL) {
                            $$ = new ast_statement_list($1->pos, $3, $1);
                        }
                        else if($3 != NULL) {
                            $$ = new ast_statement_list($3->pos, $3);
                        }
                        else {
                            $$ = $1;
                        }
                    }
                    ;

stmt                : T_IF expr stmt_list elseif_list else_part
                    {
                        // TODO: may need end keyword
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        $$ = new ast_if(pos, $2, $3, $4, $5);
                    }
                    | T_WHILE expr stmt_list
                    {
                        // TODO: may need end keyword
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        $$ = new ast_while(pos, $2, $3);
                    }
                    | proc_id T_LEFTPAR opt_expr_list T_RIGHTPAR
                    {
                        $$ = new ast_procedure_call($1->pos, $1, $3);
                    }
                    | T_RETURN expr
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        $$ = new ast_return(pos, $2);
                    }
                    | T_RETURN
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        $$ = new ast_return(pos);
                    }
                    | /* intentionally empty */ /* TODO: assignment */
                    {
                        $$ = NULL;
                    }
                    ;

/*
lvar                : lvar_id
                    {
                        $$ = $1;
                    }
                    | array_id T_LEFTBRACKET expr T_RIGHTBRACKET
                    {
                        $$ = new ast_indexed($1->pos, $1, $3);
                    }
                    | array_id T_LEFTBRACKET error T_RIGHTBRACKET
                    {
                        $$ = NULL;
                    }
                    ;
*/

rvar                : rvar_id
                    {
                        $$ = $1;
                    }
                    | array_id T_LEFTBRACKET expr T_RIGHTBRACKET
                    {
                        $$ = new ast_indexed($1->pos, $1, $3);
                    }
                    | array_id T_LEFTBRACKET error T_RIGHTBRACKET
                    {
                        yyerrok;
                        $$ = NULL;
                    }
                    ;

elseif_list         : elseif_list elseif
                    {
                        $$ = new ast_elseif_list($2->pos, $2, $1);
                    }
                    | /* intentionally empty */
                    {
                        $$ = NULL;
                    }
                    ;

elseif              : T_ELSEIF expr stmt_list
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        $$ = new ast_elseif(pos, $2, $3);
                    }
                    ;

else_part           : T_ELSE stmt_list
                    {
                        $$ = $2;
                    }
                    | /* intentionally empty */
                    {
                        $$ = NULL;
                    }
                    ;

opt_expr_list       : expr_list
                    {
                        $$ = $1;
                    }
                    | /* intentionally empty */
                    {
                        $$ = NULL;
                    }
                    ;

expr_list           : expr
                    {
                        $$ = new ast_expression_list($1->pos, $1);
                    }
                    | expr_list T_COMMA expr
                    {
                        $$ = new ast_expression_list($1->pos, $3, $1);
                    }
                    ;

expr                : simple_expr
                    {
                        $$ = $1;
                    }
                    | expr T_EQ simple_expr
                    {
                        // $$ = new ast_equal($1->pos, $1, $3);
                    }
                    | /* TODO: not eq */
                    {
                        // TODO: not eq
                    }
                    | expr T_LESSTHAN simple_expr
                    {
                        // $$ = new ast_less_than($1->pos, $1, $3);
                    }
                    | expr T_GREATERTHAN simple_expr
                    {
                        // $$ = new ast_greater_than($1->pos, $1, $3);
                    }
                    ;

simple_expr         : term
                    {
                        $$ = $1;
                    }
                    | T_ADD term
                    {
                        $$ = $2;
                    }
                    | T_SUB term
                    {
                        // TODO: uminus
                    }
                    | /* TODO: or */
                    {
                        // TODO: or
                    }
                    | simple_expr T_ADD term
                    {
                        $$ = new ast_add($1->pos, $1, $3);
                    }
                    | simple_expr T_SUB term
                    {
                        $$ = new ast_sub($1->pos, $1, $3);
                    }
                    ;

term                : factor
                    {
                        $$ = $1;
                    }
                    | /* TODO: and, idiv/rdiv, mod */
                    {
                        // TODO: and, idiv/rdiv, mod
                    }
                    | term T_MULT factor
                    {
                        $$ = new ast_mult($1->pos, $1, $3);
                    }
                    | term T_DIV factor
                    {
                        $$ = new ast_div($1->pos, $1, $3);
                    }
                    ;

factor              : rvar
                    {
                        $$ = $1;
                    }
                    | func_call
                    {
                        $$ = $1;
                    }
                    | integer
                    {
                        $$ = $1;
                    }
                    | real
                    {
                        $$ = $1;
                    }
                    | /* TODO: not */
                    {
                        // TODO: not
                    }
                    | T_LEFTPAR expr T_RIGHTPAR
                    {
                        $$ = $2;
                    }
                    ;

func_call           : func_id T_LEFTPAR opt_expr_list T_RIGHTPAR
                    {
                        $$ = new ast_function_call($1->pos, $1, $3);
                    }
                    ;

integer             : T_INT
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        $$ = new ast_int(pos, $1);
                    }
                    ;

real                : T_REAL
                    {
                        position_information* pos = new position_information(@1.first_line, @1.first_column);
                        $$ = new ast_real(pos, $1);
                    }
                    ;

type_id             : id
                    {
                        if(sym_tab->get_symbol_tag($1->sym_p) != SYM_TYPE) {
                            type_error($1->pos) << "not declared "
                            << "as type: "
                            << yytext << endl << flush;
                        }
                        $$ = $1;
                    }
                    ;

const_id            : id
                    {
                        if(sym_tab->get_symbol_tag($1->sym_p) != SYM_CONST) {
                            type_error($1->pos) << "not declared "
                            << "as const: "
                            << yytext << endl << flush;
                        }
                        $$ = $1;
                    }
                    ;

/*
lvar_id             : id
                    {
                        if(sym_tab->get_symbol_tag($1->sym_p) != SYM_VAR && sym_tab->get_symbol_tag($1->sym_p) != SYM_PARAM) {
                            type_error($1->pos) << "not declared "
                            << "as var or param: "
                            << yytext << endl << flush;
                        }
                        $$ = $1;
                    }
                    ;
*/

rvar_id             : id
                    {
                        if(sym_tab->get_symbol_tag($1->sym_p) != SYM_VAR && sym_tab->get_symbol_tag($1->sym_p) != SYM_PARAM && sym_tab->get_symbol_tag($1->sym_p) != SYM_CONST ) {
                            type_error($1->pos) << "not declared "
                            << "as var, param or const: "
                            << yytext << endl << flush;
                        }
                        $$ = $1;
                    }
                    ;

proc_id             : id
                    {
                        if(sym_tab->get_symbol_tag($1->sym_p) != SYM_PROC) {
                            type_error($1->pos) << "not declared "
                            << "as procedure: "
                            << yytext << endl << flush;
                        }
                        $$ = $1;
                    }
                    ;

func_id             : id
                    {
                        if(sym_tab->get_symbol_tag($1->sym_p) != SYM_FUNC) {
                            type_error($1->pos) << "not declared "
                            << "as function: "
                            << yytext << endl << flush;
                        }
                        $$ = $1;
                    }
                    ;

array_id            : id
                    {
                        if(sym_tab->get_symbol_tag($1->sym_p) != SYM_ARRAY) {
                            type_error($1->pos) << "not declared "
                            << "as array: "
                            << yytext << endl << flush;
                        }
                        $$ = $1;
                    }
                    ;

id                  : T_ID
                    {
                        sym_index sym_p;
                        position_information* pos = new position_information(@1.first_line, @1.first_column);

                        /*
                        make sure symbol is declared
                        */
                        sym_p = sym_tab->lookup_symbol($1);
                        if(sym_p == NULL_SYM) {
                            type_error(pos) << "not declared: " << yytext << endl << flush;
                        }

                        $$ = new ast_id(pos, sym_p);
                        $$->type = sym_tab->get_symbol_type(sym_p);
                    }
                    ;

%%