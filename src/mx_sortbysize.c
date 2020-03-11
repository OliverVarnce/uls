#include "uls.h"

void mx_sortbysize_asc(t_list_dir *first, t_list_dir *second, t_flags *opts) {
    if (first->stattemp->st_size < second->stattemp->st_size && opts) {
        mx_swap(first, second);
        return;
    }
    if (first->stattemp->st_size == second->stattemp->st_size) {
        if (mx_strcmp(first->d_name, second->d_name) > 0) {
            mx_swap(first, second);
            return;
        }
    }
}

void mx_sortbysize_desc(t_list_dir *first, t_list_dir *second, t_flags *opts) {
    if (first->stattemp->st_size > second->stattemp->st_size && opts) {
        mx_swap(first, second);
        return;
    }
    if (first->stattemp->st_size == second->stattemp->st_size) {
        if (mx_strcmp(first->d_name, second->d_name) < 0) {
            mx_swap(first, second);
            return;
        }
    }
}
