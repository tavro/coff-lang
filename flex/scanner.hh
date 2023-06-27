#ifndef __SCANNER_HH__
#define __SCANNER_HH__

typedef union {
    long    ival; // integer value  (T_INTNUM)
    double  rval; // real value     (T_REALNUM)
    // TODO: add pool_index for string literals
} YYSTYPE;

typedef struct {
    int first_line;
    int first_column;
    int last_line;
    int last_column;
} YYLTYPE; // set for each token

extern YYSTYPE yylval; // additional info for certain tokens
extern YYLTYPE yylloc; // tracking position in source code

#endif // __SCANNER_HH__