#include "uls.h"

void mx_sortbysize_asc(t_dirlist *first, t_dirlist *second, t_flags *opts) {
    if (first->stattemp->st_size < second->stattemp->st_size && opts)
        mx_swap(first, second);
    else if (first->stattemp->st_size == second->stattemp->st_size) {
        if (mx_strcmp(first->d_name, second->d_name) > 0)
            mx_swap(first, second);
    }
}

void mx_sortbysize_desc(t_dirlist *first, t_dirlist *second, t_flags *opts) {
    if (first->stattemp->st_size > second->stattemp->st_size && opts)
        mx_swap(first, second);
    else if (first->stattemp->st_size == second->stattemp->st_size) {
        if (mx_strcmp(first->d_name, second->d_name) < 0)
            mx_swap(first, second);
    }
}
