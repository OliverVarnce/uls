#include "uls.h"

char *get_link(t_dirlist *node, t_flags *fl) {
    char temp[256];
    char *res = NULL;

    mx_memset(temp, '\0', 256);
    if (fl->flag_G)
        mx_set_color(node->d_name, PINK);
    else
        mx_printstr(node->d_name);
    mx_printstr(" -> ");
    readlink(node->path, temp, 256);
    mx_printstr(temp);
    return res;
}

void mx_print_name_or_link(t_dirlist *w, t_flags *fl){
    char *link = NULL;

    if (mx_get_file_type(w->stattemp->st_mode) == 'l') {
        link = get_link(w, fl);
        mx_printstr(link);
        free(link);
    } 
    else {
        fl->flag_G ? mx_out_G(w->d_name, w->stattemp->st_mode)
        : mx_printstr(w->d_name);
    }
    mx_printchar('\n');
}
