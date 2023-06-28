#ifndef __ERROR_HH__
#define __ERROR_HH__

#include <iostream>
#include <sstream>
#include <ostream>

using namespace std;

/* error and debug output routines */

extern int error_count; // defined in .cc file
extern int yylineno;    // defined in generated scanner.cc file

class position_information {
private:
    int line;
    int column;
public:
    position_information();
    position_information(int l, int c);

    int get_line();
    int get_column();
};

/* printing utility methods */
extern void fatal(string);  // aborts compiling
extern void yyerror(string);

extern ostream &error(string heade = "Error: ");
extern ostream &error(position_information *);

extern ostream &type_error();
extern ostream &type_error(position_information *);

extern ostream &debug(string header = "Debug: ");
extern ostream &debug(position_information *);

#endif