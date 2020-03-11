#include "uls.h"

static void init_cur_info(t_col_size *temp, t_list_dir *w, t_flags *fl) {
    temp->cur_col_one_size = 0;
    temp->cur_col_two_size = 0;
    temp->cur_col_three_size = 0;
    temp->cur_col_four_size = 0;
    temp->cur_col_one_size = mx_get_nums(w->stattemp->st_nlink);
    if(!fl->flag_n)
        temp->cur_col_two_size = (temp->pw != NULL
                                 ? mx_strlen(temp->pw->pw_name) + 1 : 0);
    else
        temp->cur_col_two_size = mx_get_nums(w->stattemp->st_uid) + 1;
    if(fl->flag_n)
        temp->cur_col_three_size = mx_get_nums(w->stattemp->st_gid);
    else
        temp->cur_col_three_size = (temp->gr != NULL ? mx_strlen(temp->gr->gr_name)
                                                   : mx_get_nums(w->stattemp->st_gid));
    if (mx_get_file_type(w->stattemp->st_mode) == 'c'
        || mx_get_file_type(w->stattemp->st_mode) == 'b')
        temp->cur_col_four_size = 8;
    else
        temp->cur_col_four_size = mx_get_nums(w->stattemp->st_size);
}

static void init_start_info(t_col_size *temp) {
    temp->col_one_size = 0;
    temp->col_two_size = 0;
    temp->col_three_size = 0;
    temp->col_four_size = 0;
    temp->total_size = 0;
}

static t_col_size get_column_size(t_list_dir *lst, t_flags *fl) {
    t_col_size temp;

    init_start_info(&temp);
    for (t_list_dir *w = lst; w != NULL; w = w->next) {
        temp.pw = getpwuid(w->stattemp->st_uid);
        temp.gr = getgrgid(w->stattemp->st_gid);
        init_cur_info(&temp, w, fl);
        if (temp.cur_col_one_size > temp.col_one_size)
            temp.col_one_size = temp.cur_col_one_size;
        if (temp.cur_col_two_size > temp.col_two_size)
            temp.col_two_size = temp.cur_col_two_size;
        if (temp.cur_col_three_size > temp.col_three_size)
            temp.col_three_size = temp.cur_col_three_size;
        if (temp.cur_col_four_size > temp.col_four_size)
            temp.col_four_size = temp.cur_col_four_size;
        temp.total_size += w->stattemp->st_blocks;
    }
    return temp;
}

void mx_out_l(t_list_dir *lst, t_flags *fl, bool pr_total) {
    t_col_size info = get_column_size(lst, fl);

    if (pr_total) {
        mx_printstr("total ");
        mx_printint(info.total_size);
        mx_printchar('\n');
    }
    for (t_list_dir *w = lst; w != NULL; w = w->next) {
        info.pw = getpwuid(w->stattemp->st_uid);
        info.gr = getgrgid(w->stattemp->st_gid);
        mx_print_perm_and_link(w, info);
        mx_print_uid_gid(w, fl, info);
        mx_print_size_and_time(w, fl, info);
        mx_print_name_or_link(w, fl);
    }
}
