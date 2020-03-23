#include "uls.h"

void mx_print_dir(char *name, mode_t value){
    if((value & 0x002) &&((value & 0x001 && value & 0x200)
                          || (value & 0x001 && value & 0x200)))
        mx_set_color(name, GREEN_BLACK);
    else if(value & 0x002 && (value & 0x001 && !(value & 0x200)))
        mx_set_color(name, YELLOW_BLACK);
    else
        mx_set_color(name, BLUE);
}

void mx_set_color(char *name, char *col){
    mx_printstr(col);
    mx_printstr(name);
    mx_printstr(COLOR_DEFAULT);
}

void mx_out_G(char *name, mode_t value) {
    switch (mx_get_file_type(value)) {
        case '-': mx_print_reg(name, value);
            break;
        case 'b': mx_set_color(name, LIGHT_BLUE);
            break;
        case 'c': mx_set_color(name, YELLOW_BLUE);
            break;
        case 'd': mx_print_dir(name, value);
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

