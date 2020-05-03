#include "uls.h"

int mx_get_nums(int num) {
    int digits = 0;

    if (num == 0)
        return 1;
    for (; num != 0; num /= 10, digits++);

    return digits;
}
