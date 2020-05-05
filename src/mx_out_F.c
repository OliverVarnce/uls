#include "uls.h"

void mx_set_sym(char *name, char *sym) {
    mx_printstr(name);
    mx_printstr(sym);
}

void mx_check_perm(char *name, mode_t val) {
    if (((val & 0x040) && (val & 0x800)) || ((val & 0x008) && (!(val & 0x400)))
        || ((val & 0x001) && (!(val & 0x200))) || ((val & 0x001)
        && (val & 0x200)) || ((!(val & 0x040)) && (val & 0x800))
        || ((val & 0x008) && (val & 0x400)) || ((!(val & 0x008))
        && (val & 0x400)))
        mx_set_sym(name, "*");
    else
        mx_set_sym(name, "");
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
        default: mx_check_perm(name, val);
    }
}

void mx_out_F_1(mode_t val) {
    switch (mx_get_file_type(val)) {
        case 'd': mx_printstr("/");
            break;
        case 'p': mx_printstr("l");
            break;
        case 'l': mx_printstr("@");
            break;
        case 's': mx_printstr("=");
            break;
        //default: mx_check_perm(name, val);
    }
}
