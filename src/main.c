#include "uls.h"

int main(int argc, char **argv) {
    int first_file_pos = 1;
    int is_err = 0;
    t_flags flag;
    t_dirlist *file_list = NULL;
    t_dirlist *dir_list = NULL;

    mx_init_opts(&flag);
    first_file_pos = mx_read_arg(argc, argv, &flag);
    mx_check_arg(argc, argv, first_file_pos, &is_err);
    is_err = mx_check_null_flg(first_file_pos, argc, flag);

    for (int i = first_file_pos; i < argc; i++)
        mx_create_lists(argv[i], &file_list, &dir_list, &flag);

    file_list = mx_sort_list_dir(file_list, &flag);
    dir_list = mx_sort_list_dir(dir_list, &flag);
    is_err = mx_constructor(file_list, dir_list, flag, argc - first_file_pos);
    system("leaks -q uls");
    return is_err;
}
