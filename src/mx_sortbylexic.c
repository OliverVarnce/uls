#include "uls.h"

void mx_sortbylexic_desc(t_dirlist *first, t_dirlist *second, t_flags *opts) {
    if (mx_strcmp(first->d_name, second->d_name) < 0 && opts) {
        mx_swap(first, second);
    }
}

void mx_sortbylexic_asc(t_dirlist *first, t_dirlist *second, t_flags *opts) {
    if (mx_strcmp(first->d_name, second->d_name) > 0 && opts) {
        mx_swap(first, second);
    }
}
