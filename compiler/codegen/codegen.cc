#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "../symtab.hh"
#include "quads.hh"
#include "codegen.hh"

using namespace std;

extern bool assembler_trace;

#define STREAM out

code_generator *code_gen = new code_generator("d.out");
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

void code_generator::frame_address(int level, const register_type dest) {
    STREAM << "\t\t" << "mov" << "\t" << reg[dest] << ", [rbp-" << (level)*STACK_WIDTH << "]" << endl;
}

void code_generator::fetch(sym_index sym_p, register_type dest) {
    symbol *sym = sym_tab->get_symbol(sym_p);
    sym_type tag = sym->tag;

    if(tag == SYM_CONST) {
        constant_symbol *cs = sym->get_constant_symbol();
        long value;

        if(cs->type == real_type) {
            value = sym_tab->ieee(cs->const_value.rval);
        }
        else {
            value = cs->const_value.ival;
        }

        STREAM << "\t\t" << "mov" << "\t" << reg[dest] << ", " << value << endl;
    }
    else if(tag == SYM_VAR) {
        int level, offset;
        find(sym_p, &level, &offset);
        frame_address(level, RCX);

        STREAM << "\t\t" << "mov" << "\t" << reg[dest] << ", [rcx";

        if(offset > 0) {
            STREAM << "+" << offset;
        }
        else if(offset < 0) {
            STREAM << offset;
        }

        STREAM << "]" << endl;
    }
    else if(tag == SYM_PARAM) {
        int level, offset;
        find(sym_p, &level, &offset);
        frame_address(level, RCX);

        STREAM << "\t\t" << "mov" << "\t" << reg[dest] << ", [rcx";

        if(offset > 0) {
            STREAM << "+" << offset;
        }
        else if(offset < 0) {
            STREAM << offset;
        }

        STREAM << "]" << endl;
    }
}

void code_generator::fetch_float(sym_index sym_p) {
    symbol *sym = sym_tab->get_symbol(sym_p);
    sym_type tag = sym->tag;

    if(tag == SYM_CONST) {
        constant_symbol *cs = sym->get_constant_symbol();
        long value = sym_tab->ieee(cs->const_value.rval);

        STREAM << "\t\t" << "mov" << "\t" << "rcx, " << value << endl;
        STREAM << "\t\t" << "push" << "\t" << "rcx" << endl;
        STREAM << "\t\t" << "fld" << "\t" << "qword ptr [rsp]" << endl;
        STREAM << "\t\t" << "add" << "\t" << "rsp, " << STACK_WIDTH << endl;
    }
    else {
        int level, offset;
        find(sym_p, &level, &offset);
        frame_address(level, RCX);

        STREAM << "\t\t" << "fld" << "\t" << "qword ptr [rcx";

        if(offset > 0) {
            STREAM << "+" << offset;
        }
        else if(offset < 0) {
            STREAM << offset;
        }

        STREAM << "]" << endl;
    }
}

void code_generator::store(register_type src, sym_index sym_p) {
    int level, offset;

    find(sym_p, &level, &offset);
    frame_address(level, RCX);

    STREAM << "\t\t" << "mov" << "\t" << "[rcx";

    if(offset > 0) {
        STREAM << "+" << offset;
    }
    else if(offset < 0) {
        STREAM << "-" << offset;
    }

    STREAM << "], " << reg[src] << endl;
}

void code_generator::store_float(sym_index sym_p) {
    int level, offset;
    find(sym_p, &level, &offset);
    frame_address(level, RCX);

    STREAM << "\t\t" << "fstp" << "\t" << "qword ptr [rcx";

    if(offset > 0) {
        STREAM << "+" << offset;
    }
    else if(offset < 0) {
        STREAM << offset;
    }

    STREAM << "]" << endl;
}

void code_generator::array_address(sym_index sym_p, register_type dest) {
    int level, offset;
    find(sym_p, &level, &offset);
    frame_address(level, RCX);

    if(offset > 0) {
        STREAM << "\t\t" << "add" << "\t" << "rcx, " << offset << endl;
    }
    else {
        STREAM << "\t\t" << "sub" << "\t" << "rcx, " << -offset << endl;
    }

    STREAM << "\t\t" << "mov" << "\t" << reg[dest] << ", rcx" << endl;
}

void code_generator::expand(quad_list *q_list) {
    // TODO: Implement
}