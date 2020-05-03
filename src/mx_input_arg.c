#include "uls.h"

void mx_check_arg(int argc, char **argv, int i, int *is_error) {
    struct stat sb;
    t_list *bad_list = NULL;

    for (; i < argc; i++) {
        if (lstat(argv[i], &sb) == -1) {
            *is_error = 1;
            mx_push_front(&bad_list, argv[i]);
        }
    }

    bad_list = mx_sort_list(bad_list, mx_cmp);
    mx_out_no_file(bad_list);
    mx_del_list(&bad_list);
}

int mx_read_arg(int argc, char **argv, t_flags *fl) {
    int pos = 1;

    if (!isatty(STDOUT_FILENO)) {
        fl->flag_C = false;
        fl->flag_1 = true;
    }

    for (int i = 1; i < argc; i++) {
        if (*argv[i] == '-' && mx_strlen(argv[i]) != 1) {
            pos++;
            fl = mx_get_flags(fl, argv[i]);
        }
    }

    return pos;
}
