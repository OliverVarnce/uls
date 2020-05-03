#include "uls.h"

void mx_out_1(t_dirlist *head, t_flags *opts) {
    if (!head || !opts)
        return;

    for (t_dirlist *w = head; w != NULL; w = w->next) {
        opts->flag_G ?
        mx_out_G(w->d_name, w->stattemp->st_mode) :
        mx_printstr(w->d_name);
        mx_printchar('\n');
    }
}
