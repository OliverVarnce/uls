#include "uls.h"

void mx_set_sym(char *name, char *sym) {
    mx_printstr(name);
    mx_printstr(sym);
}

void mx_check_perm_1(mode_t val, t_flags *opts) {
    if (((val & 0x040) && (val & 0x800)) || ((val & 0x008) && (!(val & 0x400)))
        || ((val & 0x001) && (!(val & 0x200))) || ((val & 0x001)
        && (val & 0x200)) || ((!(val & 0x040)) && (val & 0x800))
        || ((val & 0x008) && (val & 0x400)) || ((!(val & 0x008))
        && (val & 0x400)))
        opts->flag_F ? mx_printstr("*") : mx_printstr("");
    else
        mx_printstr("");
}

void mx_check_perm(char *name, mode_t val, t_flags *opts) {
    if (((val & 0x040) && (val & 0x800)) || ((val & 0x008) && (!(val & 0x400)))
        || ((val & 0x001) && (!(val & 0x200))) || ((val & 0x001)
        && (val & 0x200)) || ((!(val & 0x040)) && (val & 0x800))
        || ((val & 0x008) && (val & 0x400)) || ((!(val & 0x008))
        && (val & 0x400)))
        opts->flag_F ? mx_set_sym(name, "*") : mx_set_sym(name, "");
    else
        mx_set_sym(name, " ");
}

void mx_out_F(char *name, mode_t val, t_flags *opts) {

    switch (mx_get_file_type(val)) {
        case 'd': mx_set_sym(name, "/");
            break;
        case 'l': if (opts->flag_F)
                    mx_set_sym(name, "@");
            break;
        default: mx_check_perm(name, val, opts);
    }
}

void mx_out_F_1(mode_t val, t_flags *opts) {
    switch (mx_get_file_type(val)) {
        case 'd': mx_printstr("/");
            break;
        case 'l': if (opts->flag_F)
                    mx_printstr("@");
            break;
        default: mx_check_perm_1(val, opts);
    }
}
