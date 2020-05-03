#include "uls.h"

void mx_dir_err(char *path) {
    char **split = mx_strsplit(path, '/');
    int i = mx_count_words(path, '/');

    mx_printerr(LS_FUNC_NAME);
    perror(split[i-1]);

    for (int j = 0; j < i; j++)
        free(split[j]);

    free(split);
}

void mx_print_error(char *path, int error_no, bool print_header) {
    if (print_header) {
        mx_printstr(path);
        mx_printstr(":\n");
    }
    if (error_no != -1)
        mx_dir_err(path);
}

bool mx_is_valid_flag(char *s) {
    bool res;
    static const char *all_flags = LS_VALID_FLG;

    while (*s) {
        res = false;
        for (int i = 0, j = mx_strlen(all_flags); i < j; i++) {
            if (*s == all_flags[i])
                res = true;
        }

        if (res == false) {
            mx_printerr(LS_VALID_STR_ONE);
            mx_printerr(s);
            mx_printerr("\n");
            return false;
        }
        s++;
    }
    return true;
}
