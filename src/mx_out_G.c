#include "uls.h"

void print_reg(char *name, mode_t value){
    if(((value & 0x040) && (value & 0x800))
       || (!(value & 0x040) && (value & 0x800)))
        mx_add_color(name, BLACK_RED);
    else if(value & 0x040 && !(value & 0x800)
            && (((value & 0x008) && (value & 0x400))
                || (!(value & 0x008) && (value & 0x400))))
        mx_add_color(name, AQUA_BLACK);
    else if((value & 0x040 && !(value & 0x800))
            || (value & 0x008 && !(value & 0x400))
            || (value & 0x001 && !(value & 0x200))
            || (value & 0x001 && value & 0x200))
        mx_add_color(name, RED);
    else
        mx_add_color(name, COLOR_DEFAULT);
}

void print_dir(char *name, mode_t value){
    if((value & 0x002) &&((value & 0x001 && value & 0x200)
                          || (value & 0x001 && value & 0x200)))
        mx_add_color(name, GREEN_BLACK);
    else if(value & 0x002 && (value & 0x001 && !(value & 0x200)))
        mx_add_color(name, YELLOW_BLACK);
    else
        mx_add_color(name, BLUE);
}

void mx_add_color(char *name, char *col){
    mx_printstr(col);
    mx_printstr(name);
    mx_printstr(COLOR_DEFAULT);
}

void mx_out_G(char *name, mode_t value) {
    switch (mx_get_file_type(value)) {
        case 'p': mx_add_color(name, YELLOW);
            break;
        case 'c': mx_add_color(name, YELLOW_BLUE);
            break;
        case 'd': print_dir(name, value);
            break;
        case 'b': mx_add_color(name, LIGHT_BLUE);
            break;
        case '-': print_reg(name, value);
            break;
        case 'l': mx_add_color(name, PINK);
            break;
        case 's': mx_add_color(name, GREEN);
            break;
        default: mx_printstr(name);
    }
}

