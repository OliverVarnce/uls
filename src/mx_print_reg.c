#include "uls.h"

void mx_print_reg(char *name, mode_t val) {
    if (((val & 0x040) && (val & 0x800))
       || (!(val & 0x040) && (val & 0x800)))
        mx_set_color(name, BLACK_RED);
    else if (val & 0x040 && !(val & 0x800)
            && (((val & 0x008) && (val & 0x400))
                || (!(val & 0x008) && (val & 0x400))))
        mx_set_color(name, AQUA_BLACK);
    else if ((val & 0x040 && !(val & 0x800))
            || (val & 0x008 && !(val & 0x400))
            || (val & 0x001 && !(val & 0x200))
            || (val & 0x001 && val & 0x200))
        mx_set_color(name, RED);
    else
        mx_set_color(name, COLOR_DEFAULT);
}
