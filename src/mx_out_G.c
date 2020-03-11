#include "uls.h"

void print_reg(char *name, mode_t value){
    if(((value & 0x040) && (value & 0x800))
       || (!(value & 0x040) && (value & 0x800)))
        mx_add_color(name, MX_BLACK_RED);
    else if(value & 0x040 && !(value & 0x800)
            && (((value & 0x008) && (value & 0x400))
                || (!(value & 0x008) && (value & 0x400))))
        mx_add_color(name, MX_AQUA_BLACK);
    else if((value & 0x040 && !(value & 0x800))
            || (value & 0x008 && !(value & 0x400))
            || (value & 0x001 && !(value & 0x200))
            || (value & 0x001 && value & 0x200))
        mx_add_color(name, MX_RED);
    else
        mx_add_color(name, MX_DEFAULT);
}

void print_dir(char *name, mode_t value){
    if((value & 0x002) &&((value & 0x001 && value & 0x200)
                          || (value & 0x001 && value & 0x200)))
        mx_add_color(name, GREEN_BLACK);
    else if(value & 0x002 && (value & 0x001 && !(value & 0x200)))
        mx_add_color(name, YELLOW_BLACK);
    else
        mx_add_color(name, MX_BLUE);
}

void mx_add_color(char *name, char *col){
    mx_printstr(col);
    mx_printstr(name);
    mx_printstr(MX_DEFAULT);
}

void mx_out_G(char *name, mode_t value) {
    char color = mx_get_file_type(value)
    if (color == 'p')
        mx_add_color(name, YELLOW);
    else if (color == 'c')
        mx_add_color(name, YELLOW);
    else if (color == 'd')
        print_dir(name, value);
    else if (color == 'b')
        mx_add_color(name, AQUA_BLUE);
    else if (color == '-')
        print_reg(name, value);
    else if (color == 'l')
        mx_add_color(name, PINK);
    else if (color == 's')
        mx_add_color(name, GREEN);
    mx_printstr(name);

}

