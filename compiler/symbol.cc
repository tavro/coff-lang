#include "symtab.hh"

symbol::symbol(pool_index pool_p) {
    id = pool_p;
    tag = SYM_UNDEF;
}

// TODO: Write description
constant_symbol::constant_symbol(const pool_index pool_p) : symbol(pool_p) {
    const_value.ival = 0;
}

parameter_symbol::parameter_symbol(const pool_index pool_p) : symbol(pool_p) { 
    size = 0;
    preceding = NULL;
}

function_symbol::function_symbol(const pool_index pool_p) : symbol(pool_p) {
    ar_size = 0;
    label_nr = 0;
    last_param = NULL;
}

/* printing functions */

symbol::format_type symbol::output_format = symbol::LONG; // default detail level

void symbol::print(ostream &o) {
    switch (output_format) {
        case LONG:
            o << "symbol:" << endl;
            o << " id:         " << sym_tab->pool_lookup(id) << endl;
            o << " type:       " << short_symbols
              << sym_tab->get_symbol(type) << long_symbols << endl;
            o << " level:      " << level << endl;
            o << " hash_link:  " << hash_link << endl;
            o << " back_link:  " << back_link << endl;
            o << " offset:     " << offset << endl;
            o << " tag:        ";

            switch (tag) {
                case SYM_UNDEF:
                    o << "SYM_UNDEF ";
                    break;
                case SYM_CONST:
                    o << "SYM_CONST ";
                    break;
                case SYM_PARAM:
                    o << "SYM_PARAM ";
                    break;
                case SYM_FUNC:
                    o << "SYM_FUNC ";
                    break;
            }
            
            o << endl;
            break;
        case SUMMARY:
            switch (tag) {
                case SYM_UNDEF:
                    o << "(SYM_UNDEF) ";
                    break;
                case SYM_CONST:
                    o << "(SYM_CONST) ";
                    break;
                case SYM_PARAM:
                    o << "(SYM_PARAM) ";
                    break;
                case SYM_FUNC:
                    o << "(SYM_FUNC) ";
                    break;
            }
            o << sym_tab->pool_lookup(id);
            break;
        case SHORT:
            o << sym_tab->pool_lookup(id);
            break;
        default:
            fatal("Bad output format in symbol::print()");
            break;
    }
}

ostream &operator<<(ostream &o, symbol *sym) {
    if (sym == NULL) {
        return o << "(null)" << endl;
    }
    
    sym->print(o);
    return o;
}

void constant_symbol::print(ostream &o) {
    symbol::print(o);

    switch (output_format) {
        case LONG:
            o << " class:      constant_symbol" << endl;

            if (type == int_type) {
                o << " const_value.ival:" << const_value.ival << endl;
            }
            else {
                o << " const_value.rval:" << const_value.rval << endl;
            }
            break;
        case SUMMARY:
        case SHORT:
            break;
        default:
            fatal("Bad output format in constant_symbol::print()");
            break;
    }
}

void parameter_symbol::print(ostream &o) {
    symbol::print(o);

    switch (output_format) {
        case LONG:
            o << " class:       parameter_symbol" << endl;
            o << " size:        " << size << endl;

            if (preceding == NULL) {
                o << " preceding:   none" << endl;
            }
            else {
                o << " preceding:   " << sym_tab->pool_lookup(preceding->id) << endl;
            }
            break;
        case SUMMARY:
            o << " <-- " << sym_tab->pool_lookup(preceding->id);
            break;
        case SHORT:
            break;
        default:
            fatal("Bad output format in parameter_symbol::print()");
            break;
    }
}

void function_symbol::print(ostream &o) {
    symbol::print(o);

    switch(output_format) {
        case LONG:
            o << " class:       function_symbol" << endl;
            o << " ar_size:     " << ar_size << endl;
            o << " label_nr:    " << label_nr << endl;
            o << " params:      ";

            if (last_param == NULL) {
                o << "none" << endl;
            }
            else {
                parameter_symbol *tmp = last_param;
                o << short_symbols;
                while (tmp != NULL) {
                    o << tmp << " ";
                    tmp = tmp->preceding;
                }
                o << long_symbols << endl;
            }
            break;
        case SUMMARY:
            o << "(";
            parameter_symbol *tmp = last_param;
            o << short_symbols;

            while (tmp != NULL) {
                o << tmp;
                tmp = tmp->preceding;
                if (tmp != NULL) {
                    o << ", ";
                }
            }

            o << ") returns " << sym_tab->get_symbol(type);
              << summary_symbols;
            break;
        case SHORT:
            break;
        default:
            fatal("Bad output format in function_symbol::print()");
            break;
    }
}

/* IO manipulators to control detail level */
ostream &short_symbols(ostream &o) {
    symbol::output_format = symbol::SHORT;
    return o;
}

ostream &summary_symbols(ostream &o) {
    symbol::output_format = symbol::SUMMARY;
    return o;
}

ostream &long_symbols(ostream &o) {
    symbol::output_format = symbol::LONG;
    return o;
}