#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "symtab.hh"
#include "scanner.hh"

using namespace std;

typedef struct {
    int token;
    string name;
} token_name;

YYSTYPE yylval;
YYLTYPE yylloc;

token_name tokens[] = {
    { T_EOF,            "T_EOF" },
    { T_ERROR,          "T_ERROR" },
    { T_DOT,            "T_DOT" },
    { T_SEMICOLON,      "T_SEMICOLON" },
    { T_EQ,             "T_EQ" },
    { T_COLON,          "T_COLON" },
    { T_LEFTBRACKET,    "T_LEFTBRACKET" },
    { T_RIGHTBRACKET,   "T_RIGHTBRACKET" },
    { T_LEFTPAR,        "T_LEFTPAR" },
    { T_RIGHTPAR,       "T_RIGHTPAR" },

    { T_COMMA,          "T_COMMA" },
    { T_LESSTHAN,       "T_LESSTHAN" },
    { T_GREATERTHAN,    "T_GREATERTHAN" },
    { T_ADD,            "T_ADD" },
    { T_SUB,            "T_SUB" },
    { T_MULT,           "T_MULT" },
    { T_DIV,            "T_DIV" },

    { T_IF,             "T_IF" },
    { T_ELSE,           "T_ELSE" },
    { T_ELSEIF,         "T_ELSEIF" },

    { T_ID,             "T_ID" },
    { T_CONST,          "T_CONST" },
    { T_WHILE,          "T_WHILE" },
    { T_INT,            "T_INT" },
    { T_REAL,           "T_REAL" },
    { T_RETURN,         "T_RETURN" },
    { T_PROGRAM,        "T_PROGRAM" },
    { T_FUNCTION,       "T_FUNCTION" },
    { T_STRING,         "T_STRING" },
    { T_VAR,            "T_VAR" },
    { T_PROCEDURE,      "T_PROCEDURE" },
    { T_ARRAY,          "T_ARRAY" }
};

const int nr_tokens = sizeof(tokens) / sizeof(*tokens);

/* see Stroustup page 346-347 */
ostream &print_token(ostream &o, int token) {
    int i;
    double re;
    long in;

    extern char *yytext;
    extern YYLTYPE yylloc;
    extern YYSTYPE yylval;

    for(i = 0; i < nr_tokens; i++) {
        if(token == tokens[i].token) {
            if(i == 24) { // REAL
                re = yylval.rval;
                o << tokens[i].name << " \'" << yytext << "\' "
                  << "(" << yylloc.first_line << ", " << yylloc.first_column << ")"
                  << " <yylval.rval = " << re << ">";
                return o;
            }
            else if(i == 23) { // INT
                in = yylval.ival;
                o << tokens[i].name << " \'" << yytext << "\' "
                  << "(" << yylloc.first_line << ", " << yylloc.first_column << ")"
                  << " <yylval.ival = " << in << ">";
                return o;
            }
            else if(i == 28) { // STRING
                o << tokens[i].name << " \'" << yytext << "\' "
                  << "(" << yylloc.first_line << ", " << yylloc.first_column << ")"
                  << " <yylval.str = " << sym_tab->capitalize(sym_tab->pool_lookup(yylval.str)) << ">";
                return o;
            }
            else if(i == 20) { // ID
                o << tokens[i].name << " \'" << yytext << "\' "
                  << "(" << yylloc.first_line << ", " << yylloc.first_column << ")"
                  << " <yylval.pool_p = " << sym_tab->pool_lookup(yylval.pool_p) << ">";
                return o;
            }
            else {
                o << tokens[i].name << " \'" << yytext << "\' "
                  << "(" << yylloc.first_line << ", " << yylloc.first_column << ")";
                return o;
            }
        }
    }

    o << '\'' << (unsigned char)token << '\'';
    return o;
}

class Omanip_int {
public:
    Omanip_int(ostream &(*f)(ostream &, int), int t) : _func(f), _arg(t) {}
    friend ostream &operator<<(ostream &os, const Omanip_int &manip) {
        (*manip._func)(os, manip._arg);
        return os;
    }
private:
    ostream &(* _func)(ostream &, int);
    int _arg;
};

const Omanip_int Token(int t) {
    return Omanip_int(&print_token, t);
}

/* interactive scanner */
int main(int argc, char **argv) {
    int token;
    extern FILE *yyin;
    extern int yylex();

    /* if input file */
    switch (argc) {
        case 1:
            yyin = stdin;
            break;
        case 2:
            yyin = fopen(argv[1], "r");
            if(yyin == NULL) {
                perror(argv[1]);
                exit(1);
            }
            break;
        default:
            cerr << "Usage: " << argv[0] << " [file]\n";
            exit(1);
    }

    while((token = yylex()) != 0) {
        cout << "Scanned " << Token(token) << '\n' << flush;
    }

    cout << "End of file\n";
    exit(0);
}