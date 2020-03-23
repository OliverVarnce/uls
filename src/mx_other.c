#include "uls.h"

void mx_print_bad_list(t_list *lst) {
    while (lst) {
        mx_printerr("uls: ");
        mx_printerr((char*)lst->data);
        mx_printerr(": No such file or directory\n");
        lst = lst->next;
    }
}

bool mx_cmp(void *s1, void *s2) {
    if (mx_strcmp((char*) s1, (char*) s2) > 0) {
        return true;
    }
    return false;
}
