#include "uls.h"

void mx_create_lists(char *argv, t_list_dir **f_list, t_list_dir **d_list,
t_flags *fl){
    struct stat statbuf;

    if (lstat(argv, &statbuf) != -1) {
        if (mx_get_file_type(statbuf.st_mode) == 'd'
            || (mx_get_file_type(statbuf.st_mode) == 'l' && !fl->flag_l))
            mx_push_front_dir(d_list, argv, NULL);
        else
            mx_push_back_dir(f_list, argv, NULL);
    }
}
