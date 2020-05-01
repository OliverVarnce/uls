#include "uls.h"

void mx_out_no_file(t_list *lst) {
    while (lst) {
        mx_printerr("uls: ");
        mx_printerr((char*)lst->data);
        mx_printerr(": No such file or directory");
        mx_printerr("\n");
        lst = lst->next;
        exit(1);
    }
}
