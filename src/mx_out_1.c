#include "uls.h"

void mx_out_1(t_list_dir *head, t_flags *opts) {
    if (!head || !opts) 
    	return;
    for (t_list_dir *w = head; w != NULL; w = w->next) {
        opts->flag_G ?
        mx_out_G(w->d_name, w->stattemp->st_mode) :
        mx_printstr(w->d_name);
        mx_printchar('\n');
    }
}
