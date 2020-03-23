#include "uls.h"

void mx_create_lists(char *argv, t_dirlist **f_list, t_dirlist **d_list,
t_flags *fl){
    struct stat stattemp;

    if (lstat(argv, &stattemp) != -1) {
        if (mx_get_file_type(stattemp.st_mode) == 'd'
            || (mx_get_file_type(stattemp.st_mode) == 'l' && !fl->flag_l))
            mx_push_front_dir(d_list, argv, NULL);
        else
            mx_push_back_dir(f_list, argv, NULL);
    }
}
