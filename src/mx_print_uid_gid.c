#include "uls.h"

void mx_print_uid_gid(t_list_dir *w, t_flags *fl, t_col_size info) {
    char *uid = mx_itoa(w->stattemp->st_uid);

    if(!fl->flag_g) {
        fl->flag_n ? mx_printstr(uid)
        : mx_printstr(info.pw->pw_name);
        for (int i = info.col_two_size - (fl->flag_n
        ? mx_get_nums(w->stattemp->st_uid)
        : mx_strlen(info.pw->pw_name)); i >= 0; i--)
            mx_printchar(' '); 
    }
    (!fl->flag_n && info.gr != NULL) ? mx_printstr(info.gr->gr_name)
    : mx_printint(w->stattemp->st_gid);
    for (int i = info.col_three_size - ((!fl->flag_n && info.gr != NULL)
    ? mx_strlen(info.gr->gr_name) 
    : mx_get_nums(w->stattemp->st_gid)); i >= 0; i--)
            mx_printchar(' ');
    if (malloc_size(uid) > 0)
        mx_strdel(&uid);
}
