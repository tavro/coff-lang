%{
#include <iostream>
// TODO: Write semantic analyser
// TODO: Write oprimizer
// TODO: Write code generator

extern char *yytext;
extern int error_count;         // defined in error.cc
extern symbol_table *sym_tab;   // defined in symtab.cc

// TODO: type checker
// TODO: code generator

extern int yylex();
extern void yyerror(string);

// TODO: flags
%}

// TODO: Various definitions


// TODO: Implement rules
%%



%%