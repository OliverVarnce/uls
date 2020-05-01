#include "uls.h"

void mx_set_sym(char *name, char *sym){
    mx_printstr(name);
    mx_printstr(sym);
}

void mx_out_F(char *name, mode_t val) {
    switch (mx_get_file_type(val)) {
        case 'd': mx_set_sym(name, "/");
            break;
        case 'p': mx_set_sym(name, "l");
            break;
        case 'l': mx_set_sym(name, "@");
            break;
        case 's': mx_set_sym(name, "=");
            break;
        default: mx_set_sym(name, "*");
    }
}
