#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// TODO: implement AST classes
// TODO: implement parser

using namespace std;

extern int error_count;
extern bool yydebug;

// TODO: flag variables

void usage(char *program_name) {
    cerr << "Usage:\n"
         << program_name << " [-flags] <file>\n"
         << program_name << " [-h]\n"
         << "Options:\n"
         << "  -h: print this help message\n";
    // TODO: add flags
    exit(1);
}

int main(int argc, char **argv) {
    char options[] = "h";
    int option;
    bool print_symtab = false;

    extern FILE *yyin;

    // TODO: implement parser => yyparse();

    if(print_symtab) {
        sym_tab->print(2);
        sym_tab->print(1);
    }

    exit(error_count);
}