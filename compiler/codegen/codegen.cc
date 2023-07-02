#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "../symtab.hh"
#include "quads.hh"
#include "codegen.hh"

using namespace std;

extern bool assembler_trace; // TODO: define in main.cc

#define STREAM out

// TODO: code_gen instance
// TODO: write documentation for whole class

code_generator::code_generator(const string object_file_name) {
    out.open(object_file_name);

    reg[RAX] = "rax";
    reg[RCX] = "rcx";
    reg[RDX] = "rdx";
}

code_generator::~code_generator() {
    out << flush;
    out.close();
}

void code_generator::generate_assembler(quad_list *q, symbol *env) {
    prologue(env);
    expand(q);
    epilogue(env);
}

int code_generator::align(int frame_size) {
    return ((frame_size + STACK_WIDTH - 1) / STACK_WIDTH) * STACK_WIDTH;
}

void code_generator::prologue(symbol *new_env) {
    int ar_size;
    int label_nr;

    block_level level;

    if(new_env->tag == SYM_PROC) {
        procedure_symbol *proc = new_env->get_procedure_symbol();
        ar_size = align(proc->ar_size);
        label_nr = proc->label_nr;
        level = proc->level;
    }
    else if(new_env->tag == SYM_FUNC) {
        function_symbol *func = new_env->get_function_symbol();
        ar_size = align(func->ar_size);
        label_nr = func->label_nr;
        level = func->level;
    }
    else {
        fatal("code_generator::prologue(): symbol is not a function or procedure");
        return;
    }

    // TODO: Probably have to rewrite this i'm not that good at assembly

    STREAM << "\t\t" << "push" << "\t" << "rbp" << endl;
    STREAM << "\t\t" << "mov" << "\t" << "rcx, rsp" << endl;

    for(int i = 1; i <= level; i++) {
        STREAM << "\t\t" << "push" << "\t" << "[rbp-" << i*STACK_WIDTH << "]" << endl;
    }

    STREAM << "\t\t" << "push" << "\t" << "rcx" << endl;
    STREAM << "\t\t" << "mov" << "\t" << "rbp, rcx" << endl;
    STREAM << "\t\t" << "sub" << "\t" << "rsp, " << ar_size << endl;

    STREAM << flush;
}

void code_generator::epilogue(symbol *old_env) {
    if(assembler_trace) {
        STREAM << "\t" << "# EPILOGUE (" << short_symbols << old_env << long_symbols << ")" << endl;
    }

    STREAM << "\t\t" << "leave" << "\t" << endl;
    STREAM << "\t\t" << "ret" << "\t" << endl;

    STREAM << flush;
}

void code_generator::find(sym_index sym_p, int *level, int *offset) {
    symbol *sym = sym_tab->get_symbol(sym_p);
    *level = sym->level;

    sym_type tag = sym->tag;
    if(tag == SYM_VAR || tag == SYM_ARRAY) {
        *offset = -((*level+1)*STACK_WIDTH + sym->offset);
    }
    else if(tag == SYM_PARAM) {
        *offset = STACK_WIDTH*2 + sym->offset;
    }
}

void code_generator::frame_address(int leve, const register_type dest) {
    STREAM << "\t\t" << "mov" << "\t" << reg[dest] << ", [rbp-" << (level)*STACK_WIDTH << "]" endl;
}

void code_generator::fetch(sym_index sym_p, register_type dest) {
    // TODO: Implement
}

void code_generator::fetch_float(sym_index sym_p) {
    // TODO: Implement
}

void code_generator::store(register_type src, sym_index sym_p) {
    // TODO: Implement
}

void code_generator::store_float(sym_index sym_p) {
    // TODO: Implement
}

void code_generator::array_address(sym_index sym_p, register_type dest) {
    // TODO: Implement
}

void code_generator::expand(quad_list *q_list) {
    // TODO: Implement
}