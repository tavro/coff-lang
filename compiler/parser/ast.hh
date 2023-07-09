#ifndef __AST_HH__
#define __AST_HH__

#include "../symtab.hh"
#include "../codegen/quads.hh"

enum ast_node_types {
    AST_NODE,
    AST_STATEMENT,
    AST_EXPRESSION,
    AST_BINARY_OP,
    AST_BINARY_RELATION,
    AST_LVAL,
    AST_STATEMENT_LIST,
    AST_EXPRESSION_LIST,
    AST_ELSEIF_LIST,
    AST_ID,
    AST_INDEXED,
    AST_ADD,
    AST_SUB,
    AST_MULT,
    AST_DIV,
    AST_EQ,
    AST_LESS_THAN,
    AST_GREATER_THAN,
    AST_PROCEDURE_CALL,
    AST_WHILE,
    AST_IF,
    AST_RETURN,
    AST_FUNCTION_CALL,
    AST_ELSEIF,
    AST_INT,
    AST_REAL,
    AST_FUNCTION_HEAD,
    AST_PROCEDURE_HEAD,
    AST_PARAM,
    AST_CAST,
    AST_NOT,
    AST_AND,
    AST_MOD,
    AST_OR,
    AST_DO,
    AST_ASSIGN,
    AST_NOT_EQUAL,
    AST_MAIN
};
typedef enum ast_node_types ast_node_type;

class quad_list;

class ast_binary_operation;
class ast_statement_list;
class ast_id;
class ast_int;
class ast_real;
class ast_cast;

// NOTE: Write description
class ast_node {
protected:
    // used for printing
    static int indent_level;
    static bool branches[10000];

    void indent(ostream &);
    void indent_more();
    void indent_less();
    void begin_child(ostream &);
    void end_child(ostream &);
    void last_child(ostream &);

    virtual void print(ostream &);
    virtual void xprint(ostream &, string);

public:
    position_information *pos;
    ast_node_type tag;
    ast_node(position_information *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &) = 0;

    friend ostream &operator<<(ostream &, ast_node *);
};

class ast_statement : public ast_node {
protected:
    virtual void print(ostream &);

public:
    ast_statement(position_information *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &) = 0;
};

class ast_expression : public ast_node {
protected:
    virtual void print(ostream &);

public:
    sym_index type;
    ast_expression(position_information *);
    ast_expression(position_information *, sym_index);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &) = 0;

    virtual ast_int *get_ast_int() {
        return NULL;
    }

    virtual ast_real *get_ast_real() {
        return NULL;
    }

    virtual ast_id *get_ast_id() {
        return NULL;
    }

    virtual ast_cast *get_ast_cast() {
        return NULL;
    }

    virtual ast_binary_operation *get_ast_binary_operation() {
        fatal("Illegal downcast to ast_binary_operation from ast_expression");
        return NULL;
    }
};

class ast_binary_relation : public ast_expression {
protected:
    virtual void print(ostream &);
    virtual void xprint(ostream &, string);

public:
    ast_expression *left;
    ast_expression *right;

    ast_binary_relation(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &) = 0;
};

class ast_binary_operation : public ast_expression {
protected:
    virtual void print(ostream &);
    virtual void xprint(ostream &, string);

public:
    ast_expression *left;
    ast_expression *right;

    ast_binary_operation(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &) = 0;

    virtual ast_binary_operation *get_ast_binary_operation() {
        fatal("Illegal downcast to ast_binary_operation");
        return NULL;
    }
};

class ast_lval : public ast_expression {
protected:
    virtual void print(ostream &);

public:
    ast_lval(position_information *);
    ast_lval(position_information *, sym_index);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &) = 0;
    virtual void generate_assignment(quad_list &, sym_index) = 0;
};

class ast_elseif : public ast_node {
protected:
    virtual void print(ostream &);

public:
    ast_expression *condition;
    ast_statement_list *body;
    ast_elseif(position_information *, ast_expression *, ast_statement_list *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
    virtual void generate_quads_and_jump(quad_list &, int);
};

class ast_expression_list : public ast_node {
protected:
    virtual void print(ostream &);

public:
    ast_expression *last_expr;
    ast_expression_list *preceding;

    ast_expression_list(position_information *, ast_expression *);
    ast_expression_list(position_information *, ast_expression *, ast_expression_list *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
    virtual void generate_param_list(quad_list &, parameter_symbol *, int *);
};

class ast_statement_list : public ast_node {
protected:
    virtual void print(ostream &);

public:
    ast_statement *last_stmt;
    ast_statement_list *preceding;

    ast_statement_list(position_information *, ast_statement *);
    ast_statement_list(position_information *, ast_statement *, ast_statement_list *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

class ast_elseif_list : public ast_node {
protected:
    virtual void print(ostream &);

public:
    ast_elseif *last_elseif;
    ast_elseif_list *preceding;

    ast_elseif_list(position_information *, ast_elseif *);
    ast_elseif_list(position_information *, ast_elseif *, ast_elseif_list *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
    virtual void generate_quads_and_jump(quad_list &, int);
};

class ast_function_head : public ast_node {
protected:
    virtual void print(ostream &);

public:
    sym_index sym_p;

    ast_function_head(position_information *, sym_index);

    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
    quad_list *do_quads(ast_statement_list *s);
};

class ast_procedure_head : public ast_node {
protected:
    virtual void print(ostream &);

public:
    sym_index sym_p;

    ast_procedure_head(position_information *, sym_index);

    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
    quad_list *do_quads(ast_statement_list *s);
};

class ast_procedure_call : public ast_statement {
protected:
    virtual void print(ostream &);

public:
    ast_id *id;
    ast_expression_list *param_list;

    ast_procedure_call(position_information *, ast_id *, ast_expression_list *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

class ast_while : public ast_statement {
protected:
    virtual void print(ostream &);

public: 
    ast_expression *condition;
    ast_statement_list *body;

    ast_while(position_information *, ast_expression *, ast_statement_list *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

class ast_if : public ast_statement {
protected:
    virtual void print(ostream &);

public:
    ast_expression *condition;
    ast_statement_list *body;
    ast_elseif_list *elseif_list;
    ast_statement_list *else_body;

    ast_if(position_information *, ast_expression *, ast_statement_list *, ast_elseif_list *, ast_statement_list *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

class ast_return : public ast_statement {
protected:
    virtual void print(ostream &);

public:
    ast_expression *value;

    ast_return(position_information *);
    ast_return(position_information *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

class ast_function_call : public ast_expression {
protected:
    virtual void print(ostream &);

public:
    ast_id *id;
    ast_expression_list *param_list;

    ast_function_call(position_information *, ast_id *, ast_expression_list *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

// TODO: Implement uminus if necessary
class ast_not : public ast_expression {
protected:
    virtual void print(ostream &);

public:
    ast_expression *expr;

    ast_not(position_information *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};


class ast_int : public ast_expression {
protected:
    virtual void print(ostream &);

public:
    long value;
    ast_int(position_information *, long);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);

    virtual ast_int *get_ast_int() {
        return this;
    }
};

class ast_real : public ast_expression {
protected:
    virtual void print(ostream &);

public:
    double value;
    ast_real(position_information *, double);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);

    virtual ast_real *get_ast_real() {
        return this;
    }
};

class ast_cast : public ast_expression {
protected:
    virtual void print(ostream &);

public: 
    ast_expression *expr;

    ast_cast(position_information *, ast_expression *);

    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);

    virtual ast_cast *get_ast_cast() {
        return this;
    }
};

class ast_equal : public ast_binary_relation {
protected:
    virtual void print(ostream &);

public:
    ast_equal(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

class ast_not_equal : public ast_binary_relation {
protected:
    virtual void print(ostream &);

public:
    ast_not_equal(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

class ast_less_than : public ast_binary_relation {
protected:
    virtual void print(ostream &);

public:
    ast_less_than(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

class ast_greater_than : public ast_binary_relation {
protected:
    virtual void print(ostream &);

public:
    ast_greater_than(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

class ast_add : public ast_binary_operation {
protected:
    virtual void print(ostream &);

public:
    ast_add(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);

    virtual ast_add *get_ast_binary_operation() {
        return this;
    }
};

class ast_assign : public ast_statement {
protected:
    virtual void print(ostream &);

public:
    ast_lval *lhs;
    ast_expression *rhs;

    ast_assign(position_information *, ast_lval *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
};

class ast_sub : public ast_binary_operation {
protected:
    virtual void print(ostream &);

public:
    ast_sub(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);

    virtual ast_sub *get_ast_binary_operation() {
        return this;
    }
};

class ast_or : public ast_binary_operation {
protected:
    virtual void print(ostream &);

public:
    ast_or(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
    
    virtual ast_or *get_ast_binary_operation() {
        return this;
    }
};

class ast_and : public ast_binary_operation{
protected:
    virtual void print(ostream &);
public:
    ast_and(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
    
    virtual ast_and *get_ast_binary_operation() {
        return this;
    }
};

class ast_mult : public ast_binary_operation {
protected:
    virtual void print(ostream &);

public:
    ast_mult(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);

    virtual ast_mult *get_ast_binary_operation() {
        return this;
    }
};

class ast_div : public ast_binary_operation {
protected:
    virtual void print(ostream &);

public:
    ast_div(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);

    virtual ast_div *get_ast_binary_operation() {
        return this;
    }
};

// TODO: idiv if necessary
class ast_mod : public ast_binary_operation {
protected:
    virtual void print(ostream &);

public:
    ast_mod(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);

    virtual ast_mod *get_ast_binary_operation() {
        return this;
    }
};

class ast_id : public ast_lval {
protected:
    virtual void print(ostream &);

public:
    sym_index sym_p;

    ast_id(position_information *);
    ast_id(position_information *, sym_index);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
    virtual void generate_assignment(quad_list &, sym_index);

    virtual ast_id *get_ast_id() {
        return this;
    }
};

class ast_indexed : public ast_lval {
protected:
    virtual void print(ostream &);

public: 
    ast_id *id;
    ast_expression *index;

    ast_indexed(position_information *, ast_id *, ast_expression *);

    virtual sym_index type_check();
    virtual void optimize();
    virtual sym_index generate_quads(quad_list &);
    virtual void generate_assignment(quad_list &, sym_index);
};

ostream &operator<<(ostream &, ast_node *);

#endif