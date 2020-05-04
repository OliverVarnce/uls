#include "uls.h"

bool mx_cmp(void *s1, void *s2) {
    if (mx_strcmp((char*) s1, (char*) s2) > 0) {
        return true;
    }
    return false;
}
