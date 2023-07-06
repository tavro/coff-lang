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
// NOTE: write documentation for whole class

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

// NOTE: Write desc
void code_generator::expand(quad_list *q_list) {
    long quad_nr = 0;

    quad_list_iterator *ql_iterator = new quad_list_iterator(q_list);
    quadruple *q = ql_iterator->get_current();

    while (q != NULL) {
        quad_nr++;

        if (q->op_code == q_label) {
            STREAM<< "L" << q->int1 << ":" << endl;
        }

        if (assembler_trace) {
            STREAM<< "\t" << "# QUAD " << quad_nr << ": " << short_symbols << q << long_symbols << endl;
        }

        switch (q->op_code) {
            case q_rload:
            case q_iload:
                STREAM << "\t\t" << "mov" << "\t" << "rax, " << q->int1 << endl;
                store(RAX, q->sym3);
                break;
            // TODO: not
            // TODO: uminus
            case q_rplus:
                fetch_float(q->sym1);
                fetch_float(q->sym2);
                STREAM << "\t\t" << "faddp" << endl;
                store_float(q->sym3);
                break;
            case q_iplus:
                fetch(q->sym1, RAX);
                fetch(q->sym2, RCX);
                STREAM << "\t\t" << "add" << "\t" << "rax, rcx" << endl;
                store(RAX, q->sym3);
                break;
            case q_rminus:
                fetch_float(q->sym1);
                fetch_float(q->sym2);
                STREAM << "\t\t" << "fsubp" << endl;
                store_float(q->sym3);
                break;
            case q_iminus:
                fetch(q->sym1, RAX);
                fetch(q->sym2, RCX);
                STREAM << "\t\t" << "sub" << "\t" << "rax, rcx" << endl;
                store(RAX, q->sym3);
                break;
            // TODO: or
            // TODO: and
            case q_rmult:
                fetch_float(q->sym1);
                fetch_float(q->sym2);
                STREAM << "\t\t" << "fmulp" << endl;
                store_float(q->sym3);
                break;
            case q_imult:
                fetch(q->sym1, RAX);
                fetch(q->sym2, RCX);
                STREAM << "\t\t" << "imul" << "\t" << "rax, rcx" << endl;
                store(RAX, q->sym3);
                break;
            case q_rdiv:
                fetch_float(q->sym1);
                fetch_float(q->sym2);
                STREAM << "\t\t" << "fdivp" << endl;
                store_float(q->sym3);
                break;
            case q_idiv:
                fetch(q->sym1, RAX);
                fetch(q->sym2, RCX);
                STREAM << "\t\t" << "cqo" << endl;
                STREAM << "\t\t" << "idiv" << "\t" << "rax, rcx" << endl;
                store(RAX, q->sym3);
                break;
            // TODO: mod
            case q_req: {
                int label = sym_tab->get_next_label();
                int label2 = sym_tab->get_next_label();
                fetch_float(q->sym1);
                fetch_float(q->sym2);
                STREAM << "\t\t" << "fcomip" << "\t" << "ST(0), ST(1)" << endl;
                STREAM << "\t\t" << "fstp" << "\t" << "ST(0)" << endl;
                STREAM << "\t\t" << "je" << "\t" << "L" << label << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 0" << endl;
                STREAM << "\t\t" << "jmp" << "\t" << "L" << label2 << endl;
                STREAM << "\t\t" << "L" << label << ":" << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 1" << endl;
                STREAM << "\t\t" << "L" << label2 << ":" << endl;
                store(RAX, q->sym3);
                break;
            }
            case q_ieq: {
                int label = sym_tab->get_next_label();
                int label2 = sym_tab->get_next_label();
                fetch(q->sym1, RAX);
                fetch(q->sym2, RCX);
                STREAM << "\t\t" << "cmp" << "\t" << "rax, rcx" << endl;
                STREAM << "\t\t" << "je" << "\t" << "L" << label << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 0" << endl;
                STREAM << "\t\t" << "jmp" << "\t" << "L" << label2 << endl;
                STREAM << "\t\t" << "L" << label << ":" << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 1" << endl;
                STREAM << "\t\t" << "L" << label2 << ":" << endl;
                store(RAX, q->sym3);
                break;
            }
            // TODO: not equal
            case q_rlt: {
                int label = sym_tab->get_next_label();
                int label2 = sym_tab->get_next_label();
                fetch_float(q->sym2);
                fetch_float(q->sym1);
                STREAM << "\t\t" << "fcomip" << "\t" << "ST(0), ST(1)" << endl;
                STREAM << "\t\t" << "fstp" << "\t" << "ST(0)" << endl;
                STREAM << "\t\t" << "jb" << "\t" << "L" << label << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 0" << endl;
                STREAM << "\t\t" << "jmp" << "\t" << "L" << label2 << endl;
                STREAM << "\t\t" << "L" << label << ":" << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 1" << endl;
                STREAM << "\t\t" << "L" << label2 << ":" << endl;
                store(RAX, q->sym3);
                break;
            }
            case q_ilt: {
                int label = sym_tab->get_next_label();
                int label2 = sym_tab->get_next_label();
                fetch(q->sym1, RAX);
                fetch(q->sym2, RCX);
                STREAM << "\t\t" << "cmp" << "\t" << "rax, rcx" << endl;
                STREAM << "\t\t" << "jl" << "\t" << "L" << label << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 0" << endl;
                STREAM << "\t\t" << "jmp" << "\t" << "L" << label2 << endl;
                STREAM << "\t\t" << "L" << label << ":" << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 1" << endl;
                STREAM << "\t\t" << "L" << label2 << ":" << endl;
                store(RAX, q->sym3);
                break;
            }
            case q_rgt: {
                int label = sym_tab->get_next_label();
                int label2 = sym_tab->get_next_label();
                fetch_float(q->sym2);
                fetch_float(q->sym1);
                STREAM << "\t\t" << "fcomip" << "\t" << "ST(0), ST(1)" << endl;
                STREAM << "\t\t" << "fstp" << "\t" << "ST(0)" << endl;
                STREAM << "\t\t" << "ja" << "\t" << "L" << label << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 0" << endl;
                STREAM << "\t\t" << "jmp" << "\t" << "L" << label2 << endl;
                STREAM << "\t\t" << "L" << label << ":" << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 1" << endl;
                STREAM << "\t\t" << "L" << label2 << ":" << endl;
                store(RAX, q->sym3);
                break;
            }
            case q_igt: {
                int label = sym_tab->get_next_label();
                int label2 = sym_tab->get_next_label();
                fetch(q->sym1, RAX);
                fetch(q->sym2, RCX);
                STREAM << "\t\t" << "cmp" << "\t" << "rax, rcx" << endl;
                STREAM << "\t\t" << "jg" << "\t" << "L" << label << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 0" << endl;
                STREAM << "\t\t" << "jmp" << "\t" << "L" << label2 << endl;
                STREAM << "\t\t" << "L" << label << ":" << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, 1" << endl;
                STREAM << "\t\t" << "L" << label2 << ":" << endl;
                store(RAX, q->sym3);
                break;
            }
            case q_rstore:
            case q_istore:
                fetch(q->sym1, RAX);
                fetch(q->sym3, RCX);
                STREAM << "\t\t" << "mov" << "\t" << "[rcx], rax" << endl;
                break;
            // TODO: assign
            case q_param: {
                fetch(q->sym1, RAX);
                STREAM << "\t\t" << "push" << "\t" << "rax" << endl;
                break;
            }
            case q_call: {
                sym_type tag = sym_tab->get_symbol_tag(q->sym1);

                if (tag == SYM_FUNC)
                {
                    function_symbol *fun_s = sym_tab->get_symbol(q->sym1)->get_function_symbol();
                    STREAM << "\t\t" << "call" << "\t" << "L" << fun_s->label_nr << "\t# " << sym_tab->pool_lookup(fun_s->id) << endl;
                    STREAM << "\t\t" << "add" << "\t" << "rsp, " << q->int2*STACK_WIDTH << endl;
                    store(RAX, q->sym3);
                }
                else if (tag == SYM_PROC)
                {
                    procedure_symbol *para_s = sym_tab->get_symbol(q->sym1)->get_procedure_symbol();
                    STREAM << "\t\t" << "call" << "\t" << "L" << para_s->label_nr << "\t# " << sym_tab->pool_lookup(para_s->id) << endl;
                    STREAM << "\t\t" << "add" << "\t" << "rsp, " << q->int2*STACK_WIDTH << endl;
                }
                break;
            }
            case q_rreturn:
            case q_ireturn:
                fetch(q->sym2, RAX);
                STREAM << "\t\t" << "jmp" << "\t" << "L" << q->int1 << endl;
                break;
            case q_lindex:
                array_address(q->sym1, RAX);
                fetch(q->sym2, RCX);
                STREAM << "\t\t" << "imul" << "\t" << "rcx, " << STACK_WIDTH << endl;
                STREAM << "\t\t" << "sub" << "\t" << "rax, rcx" << endl;
                store(RAX, q->sym3);
                break;
            case q_rrindex:
            case q_irindex:
                array_address(q->sym1, RAX);
                fetch(q->sym2, RCX);
                STREAM << "\t\t" << "imul" << "\t" << "rcx, " << STACK_WIDTH << endl;
                STREAM << "\t\t" << "sub" << "\t" << "rax, rcx" << endl;
                STREAM << "\t\t" << "mov" << "\t" << "rax, [rax]" << endl;
                store(RAX, q->sym3);
                break;
            // TODO: itor
            case q_jmp:
                STREAM << "\t\t" << "jmp" << "\t" << "L" << q->int1 << endl;
                break;
            case q_jmpf:
                fetch(q->sym2, RAX);
                STREAM << "\t\t" << "cmp" << "\t" << "rax, 0" << endl;
                STREAM << "\t\t" << "je" << "\t" << "L" << q->int1 << endl;
                break;
            case q_label:
                break;
            case q_nop:
                // q_nop quads should never be generated.
                fatal("code_generator::expand(): q_nop quadruple produced.");
                return;
        }
        
        q = ql_iterator->get_next();
    }

    STREAM << flush;
}