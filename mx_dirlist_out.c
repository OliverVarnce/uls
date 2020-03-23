#include "uls.h"

void mx_dirlist_out(t_dirlist *list, t_flags *opts) {
    if (opts->flag_l && list)
        mx_out_l(list, opts, true);
    else if (opts->flag_1 || (!isatty(STDOUT_FILENO) && !opts->flag_C))
        mx_out_1(list, opts);
    else
        mx_print_table(list, opts);
}
