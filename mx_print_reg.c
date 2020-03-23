#include "uls.h"

void mx_print_reg(char *name, mode_t value){
    if(((value & 0x040) && (value & 0x800))
       || (!(value & 0x040) && (value & 0x800)))
        mx_set_color(name, BLACK_RED);
    else if(value & 0x040 && !(value & 0x800)
            && (((value & 0x008) && (value & 0x400))
                || (!(value & 0x008) && (value & 0x400))))
        mx_set_color(name, AQUA_BLACK);
    else if((value & 0x040 && !(value & 0x800))
            || (value & 0x008 && !(value & 0x400))
            || (value & 0x001 && !(value & 0x200))
            || (value & 0x001 && value & 0x200))
        mx_set_color(name, RED);
    else
        mx_set_color(name, COLOR_DEFAULT);
}
