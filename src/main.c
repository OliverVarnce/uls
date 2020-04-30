#include "uls.h"

static void init_opts(t_flags *opts) {
    opts->flag_l = false;
    opts->flag_C = true;
    opts->flag_1 = false;
    opts->flag_a = false;
    opts->flag_A = false;
    opts->flag_G = false;
    opts->flag_r = false;
    opts->flag_R = false;
    opts->flag_T = false;
    opts->flag_n = false;
    opts->flag_g = false;
    opts->flag_u = false;
    opts->flag_c = false;
    opts->flag_S = false;
    opts->flag_t = false;
}

static void check_arg(int argc, char **argv, int i, int *is_error) {
    struct stat sb;
    t_list *bad_list = NULL;

    for(; i < argc; i++) {
        if(lstat(argv[i], &sb) == -1) {
            *is_error = 1;
            mx_push_front(&bad_list, argv[i]);
        }
    }
    bad_list = mx_sort_list(bad_list, mx_cmp);
    mx_print_bad_list(bad_list);
    mx_del_list(&bad_list);
}

static int read_arg(int argc, char **argv, t_flags *fl) {
    int pos = 1;

    if (!isatty(STDOUT_FILENO)) {
        fl->flag_C = false;
        fl->flag_1 = true;
    }
    for (int k = 1; k < argc; k++){
        if(*argv[k] == '-' && mx_strlen(argv[k]) != 1){
            pos++;
            fl = mx_get_flags(fl, argv[k]);
        }
    }
    return pos;
}

int main(int argc, char **argv) {
    t_flags flag;
    t_dirlist *file_list = NULL;
    t_dirlist *dir_list = NULL;
    int first_file_pos = 1;
    int is_err = 0;

    init_opts(&flag);
    first_file_pos = read_arg(argc, argv, &flag);
    check_arg(argc, argv, first_file_pos, &is_err);
    if (first_file_pos == argc) {
        mx_dir_parser(".", &flag, false, &is_err);
        return is_err;
    }
    for (int i = first_file_pos; i < argc; i++)
        mx_create_lists(argv[i], &file_list, &dir_list, &flag);
    file_list = mx_sort_list_dir(file_list, &flag);
    dir_list = mx_sort_list_dir(dir_list, &flag);
    is_err = mx_constructor(file_list, dir_list, flag, argc - first_file_pos);

    return is_err;
}
