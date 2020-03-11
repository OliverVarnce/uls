#include "uls.h"

static fptr factory(t_flags *opts);

t_list_dir *mx_sort_list_dir(t_list_dir *lst, t_flags *opts) {
    fptr mx_cmp; 

    if (!lst || !opts)
        return NULL;
    mx_cmp = factory(opts);
    for (t_list_dir *i = lst; i != NULL; i = i->next) {
        for (t_list_dir *j = i->next; j != NULL; j = j->next) {
            mx_cmp(i, j, opts);
        }
    }
    return lst;
}

static fptr factory(t_flags *opts) {
    if (opts->flag_r) {
        if (opts->flag_S)
            return mx_sortbysize_desc;
        if (opts->flag_t)
            return mx_sortbytmod_desc;
        return mx_sortbylexic_desc;
    } 
    else {
        if (opts->flag_S)
            return mx_sortbysize_asc;
        if (opts->flag_t)
            return mx_sortbytmod_asc;
        return mx_sortbylexic_asc;
    }
}

void mx_swap(t_list_dir *first, t_list_dir *second) {
    struct stat *temp_stat = first->stattemp;
    char *temp_name = first->d_name;
    char *temp_path = first->path;

    first->d_name = second->d_name;
    second->d_name = temp_name;
    first->path = second->path;
    second->path = temp_path;
    first->stattemp = second->stattemp;
    second->stattemp = temp_stat;
}

struct timespec mx_get_time_type(t_list_dir *node, t_flags *opts) {
    if (opts->flag_u)
        return node->stattemp->st_atimespec;
    if (opts->flag_c)
        return node->stattemp->st_ctimespec;
    return node->stattemp->st_mtimespec;
}
