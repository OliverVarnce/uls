#include "uls.h"

void mx_print_table_FG (t_flags *opts, int col_width,
                            int str_len, int tabs) {
    if (str_len % 8 != 0)
        tabs++;
    if (opts->flag_G) {
        for (int z = 0; z <= (col_width - str_len); z++)
            mx_printchar(' ');
    }
    else {
        for (int i = 0; i < tabs; i++)
            mx_printchar('\t');
    }
}

void mx_else_FG (t_flags *opts, t_node **arr, int i, int j) {
    if (opts->flag_G) {
        mx_out_G(arr[i][j].ptr->d_name,
                 arr[i][j].ptr->stattemp->st_mode);
    }
    if (opts->flag_F && isatty(STDOUT_FILENO)) {
        mx_out_F(arr[i][j].ptr->d_name,
                 arr[i][j].ptr->stattemp->st_mode, opts);
    }
    if (opts->flag_p && isatty(STDOUT_FILENO)) {
        mx_out_F(arr[i][j].ptr->d_name,
                 arr[i][j].ptr->stattemp->st_mode, opts);
    }
    else {
        mx_printstr(arr[i][j].ptr->d_name);
    }
}
