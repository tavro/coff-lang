#ifndef __AST_HH__
#define __AST_HH__

#include "../symtab.hh"

// TODO: Implement intermediate code generation

enum ast_node_types {
    AST_NODE,
    AST_STATEMENT,
    AST_EXPRESSION,
    AST_BINARY_OP,
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
    AST_CAST
};
typedef enum ast_node_types ast_node_type;

// TODO: intermidiate code generation

class ast_binary_operation;
class ast_statement_list;
class ast_id;
class ast_int;
class ast_real;
class ast_cast;

// TODO: Write description
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

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation

    friend ostream &operator<<(ostream &, ast_node *);
};

class ast_statement : public ast_node {
protected:
    virtual void print(ostream &);

public:
    ast_statement(position_information *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
};

class ast_expression : public ast_node {
protected:
    virtual void print(ostream &);

public:
    sym_index type;
    ast_expression(position_information *);
    ast_expression(position_information *, sym_index);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation

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

// TODO: Implement binary relation if necessary

class ast_binary_operation : public ast_expression {
protected:
    virtual void print(ostream &);
    virtual void xprint(ostream &, string);

public:
    ast_expression *left;
    ast_expression *right;

    ast_binary_operation(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation

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

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
    // TODO: Code generation
};

class ast_elseif : public ast_node {
protected:
    virtual void print(ostream &);

public:
    ast_expression *condition;
    ast_statement_list *body;
    ast_elseif(position_information *, ast_expression *, ast_statement_list *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
    // TODO: Code generation
};

class ast_expression_list : public ast_node {
protected:
    virtual void print(ostream &);

public:
    ast_expression *last_expr;
    ast_expression_list *preceding;

    ast_expression_list(position_information *, ast_expression *);
    ast_expression_list(position_information *, ast_expression *, ast_expression_list *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
    // TODO: Code generation
};

class ast_statement_list : public ast_node {
protected:
    virtual void print(ostream &);

public:
    ast_statement *last_stmt;
    ast_statement_list *preceding;

    ast_statement_list(position_information *, ast_statement *);
    ast_statement_list(position_information *, ast_statement *, ast_statement_list *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
};

class ast_elseif_list : public ast_node {
protected:
    virtual void print(ostream &);

public:
    ast_elseif *last_elseif;
    ast_elseif_list *preceding;

    ast_elseif_list(position_information *, ast_elseif *);
    ast_elseif_list(position_information *, ast_elseif *, ast_elseif_list *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
    // TODO: Code generation
};

class ast_function_head : public ast_node {
protected:
    virtual void print(ostream &);

public:
    sym_index sym_p;

    ast_function_head(position_information *, sym_index);

    virtual void optimize(); // TODO: Implement optimizer
    // TODO: Intermediate code generation
    // TODO: Code generation
};

class ast_procedure_head : public ast_node {
protected:
    virtual void print(ostream &);

public:
    sym_index sym_p;

    ast_procedure_head(position_information *, sym_index);

    virtual void optimize(); // TODO: Implement optimizer
    // TODO: Intermediate code generation
    // TODO: Code generation
};

class ast_procedure_call : public ast_statement {
protected:
    virtual void print(ostream &);

public:
    ast_id *id;
    ast_expression_list *param_list;

    ast_procedure_call(position_information *, ast_id *, ast_expression_list *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
};

class ast_while : public ast_statement {
protected:
    virtual void print(ostream &);

public: 
    ast_expression *condition;
    ast_statement_list *body;

    ast_while(position_information *, ast_expression *, ast_statement_list *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
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

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
};

class ast_return : public ast_statement {
protected:
    virtual void print(ostream &);

public:
    ast_expression *value;

    ast_return(position_information *);
    ast_return(position_information *, ast_expression *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
};

class ast_function_call : public ast_expression {
protected:
    virtual void print(ostream &);

public:
    ast_id *id;
    ast_expression_list *param_list;

    ast_function_call(position_information *, ast_id *, ast_expression_list *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
};

// TODO: Implement uminus if necessary
// TODO: Implement not if necessary

class ast_int : public ast_expression {
protected:
    virtual void print(ostream &);

public:
    long value;
    ast_int(position_information *, long);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation

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

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation

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

    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation

    virtual ast_cast *get_ast_cast() {
        return this;
    }
};

                // TODO: this may actually better derive from a
                // new binary_relation class
class ast_equal : public ast_expression {
protected:
    virtual void print(ostream &);

public:
    ast_equal(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Intermediate code generation
};

// TODO: not equal if necessary

                    // TODO: this may actually better derive from a
                    // new binary_relation class
class ast_less_than : public ast_expression {
protected:
    virtual void print(ostream &);

public:
    ast_less_than(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Implement intermediate code generation
};

                        // TODO: this may actually better derive from a
                        // new binary_relation class
class ast_greater_than : public ast_expression {
protected:
    virtual void print(ostream &);

public:
    ast_greater_than(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Implement intermediate code generation
};

class ast_add : public ast_binary_operation {
protected:
    virtual void print(ostream &);

public:
    ast_add(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();   // TODO: Implement optimizer
    // TODO: Implement intermediate code generation

    virtual ast_add *get_ast_binary_operation() {
        return this;
    }
};

class ast_sub : public ast_binary_operation {
protected:
    virtual void print(ostream &);

public:
    ast_sub(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();   // TODO: Implement optimizer
    // TODO: Implement intermediate code generation

    virtual ast_sub *get_ast_binary_operation() {
        return this;
    }
};

// TODO: Implement or if necessary
// TODO: Implement and if necessary

class ast_mult : public ast_binary_operation {
protected:
    virtual void print(ostream &);

public:
    ast_mult(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();   // TODO: Implement optimizer
    // TODO: Implement intermediate code generation

    virtual ast_mult *get_ast_binary_operation() {
        return this;
    }
};

class ast_div : public ast_binary_operation {
protected:
    virtual void print(ostream &);

public:
    ast_div(position_information *, ast_expression *, ast_expression *);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();   // TODO: Implement optimizer
    // TODO: Implement intermediate code generation

    virtual ast_div *get_ast_binary_operation() {
        return this;
    }
};

// TODO: idiv if necessary
// TODO: mod if necessary

class ast_id : public ast_lval {
protected:
    virtual void print(ostream &);

public:
    sym_index sym_p;

    ast_id(position_information *);
    ast_id(position_information *, sym_index);

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Implement intermediate code generation
    // TODO: code generation

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

    virtual sym_index type_check(); // TODO: Implement semantic analyser
    virtual void optimize();        // TODO: Implement optimizer
    // TODO: Implement intermediate code generation
    // TODO: code generation
};

ostream &operator<<(ostream &, ast_node *);

#endif