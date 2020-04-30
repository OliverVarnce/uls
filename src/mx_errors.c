#include "uls.h"

void mx_dir_err(char *path) {
    char **split = mx_strsplit(path, '/');
    int i = mx_count_words(path, '/');

    mx_printerr("uls: ");
    perror(split[i-1]);
    mx_printerr("\n");
    for (int j = 0; j < i; j++) {
        free(split[j]);
    }
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
    static const char *all_flags = MX_VALID_FLG;

    while (*s) {
        res = false;
        for (int i = 0, j = mx_strlen(all_flags); i < j; i++) {
            if(*s == all_flags[i])
                res = true;
        }
        if (res == false) {
            mx_printerr("uls: illegal option -- ");
            write(2, s, 1);
            mx_printerr("\n");
            return false;
        }
        s++;
    }
    return true;
}
