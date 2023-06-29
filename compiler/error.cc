#include <cstdlib>

#include "error.hh"

//TODO: write more detailed documentation for this file
int error_count = 0;

ostream &error(string header) {
    error_count++;
    return cerr << header;
}

ostream &error(position_information *pos) {
    return error("Error") << " line " << pos->get_line()
           << ", col " << pos->get_column() << ": ";
}

void fatal(string msg) {
    error() << "Fatal: " << msg << endl << flush;
    abort();
}

void yyerror(string msg) {
    error() << "line " << yylineno << ": " << msg << endl << flush;
}

ostream &type_error() {
    return error("Type conflict: ");
}

ostream &type_error(position_information *pos) {
    if (pos == NULL) {
        return type_error();
    }
    return error("Type conflict, line ") << pos->get_line()
           << ", col " << pos->get_column()
           << ": ";
}

ostream &debug(string header) {
    return cerr << header;
}

ostream &debug(position_information *pos) {
    if (pos == NULL) {
        return debug();
    }
    return debug("Debug") << " (line " << pos->get_line()
           << ", col " << pos->get_column() << "): ";
}

position_information::position_information() {
    line = 0;
    column = 0;
}

position_information::position_information(int l, int c) {
    line = l;
    column = c;
}

int position_information::get_line() {
    return line;
}

int position_information::get_column() {
    return column;
}