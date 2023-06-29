#ifndef __SCANNER_HH__
#define __SCANNER_HH__

#include "symtab.hh"

typedef union {
    long        ival;   // integer value  (T_INTNUM)
    double      rval;   // real value     (T_REALNUM)
    pool_index  str;    // string value   (T_STRING)
    pool_index  pool_p; // id value       (T_ID)
} YYSTYPE;

typedef struct {
    int first_line;
    int first_column;
    int last_line;
    int last_column;
} YYLTYPE; // set for each token

#define T_EOF           0   // end of file (requirement for bison)
#define T_ERROR         258 // invalid token
#define T_DOT           260 // .
#define T_SEMICOLON     261 // ;
#define T_EQ            262 // =
#define T_COLON         263 // :
#define T_LEFTBRACKET   264 // [
#define T_RIGHTBRACKET  265 // ]
#define T_LEFTPAR       266 // (
#define T_RIGHTPAR      267 // )

#define T_COMMA         268 // ,
#define T_LESSTHAN      269 // <
#define T_GREATERTHAN   270 // >
#define T_ADD           271 // +
#define T_SUB           272 // -
#define T_MULT          273 // *
#define T_DIV           274 // /

#define T_IF            275 // if
#define T_ELSE          276 // else
#define T_ELSEIF        277 // elseif

#define T_ID            278 // identifier
#define T_CONST         279 // const
#define T_WHILE         280 // while
#define T_INT           281 // 123
#define T_REAL          282 // 123.456
#define T_RETURN        283 // return
#define T_PROGRAM       284 // program
#define T_FUNCTION      285 // function
#define T_STRING        286 // 'coff lang'

// TODO: add nr of symbols

extern YYSTYPE yylval; // additional info for certain tokens
extern YYLTYPE yylloc; // tracking position in source code

#endif // __SCANNER_HH__