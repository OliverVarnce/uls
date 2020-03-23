#include "uls.h"

void mx_print_dir(char *name, mode_t val){
    if((val & 0x002) &&((val & 0x001 && val & 0x200)
                          || (val & 0x001 && val & 0x200)))
        mx_set_color(name, GREEN_BLACK);
    else if(val & 0x002 && (val & 0x001 && !(val & 0x200)))
        mx_set_color(name, YELLOW_BLACK);
    else
        mx_set_color(name, BLUE);
}

void mx_set_color(char *name, char *col){
    mx_printstr(col);
    mx_printstr(name);
    mx_printstr(COLOR_DEFAULT);
}

void mx_out_G(char *name, mode_t val) {
    switch (mx_get_file_type(val)) {
        case '-': mx_print_reg(name, val);
            break;
        case 'b': mx_set_color(name, LIGHT_BLUE);
            break;
        case 'c': mx_set_color(name, YELLOW_BLUE);
            break;
        case 'd': mx_print_dir(name, val);
            break;
        case 'p': mx_set_color(name, YELLOW);
            break;
        case 'l': mx_set_color(name, PINK);
            break;
        case 's': mx_set_color(name, GREEN);
            break;
        default: mx_printstr(name);
    }
}

