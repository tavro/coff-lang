#ifndef __CODEGEN_HH__
#define __CODEGEN_HH__

#include <fstream>

#include "quads.hh"
#include "../symtab.hh"

using namespace std;

enum register_type { RAX, RCX, RDX };

const int MAX_PARAMS = 127;
const int STACK_WIDTH = 8;

// NOTE: Write documentation for this class
class code_generator {
private:
    string reg[3];
    ofstream out;

    int align(int);

    void prologue(symbol *);
    void epilogue(symbol *);

    void expand(quad_list *q);
    void find(sym_index, int*, int*);
    void fetch(sym_index, const register_type);
    void fetch_float(sym_index);
    void store(const register_type, sym_index);
    void store_float(sym_index);
    void array_address(sym_index, const register_type);
    void frame_address(int level, const register_type);

public:
    code_generator(const string);
    ~code_generator();

    void generate_assembler(quad_list *, symbol *env);
};

#endif