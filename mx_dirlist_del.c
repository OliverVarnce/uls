#include "uls.h"

void mx_dirlist_del(t_dirlist **head) {
    t_dirlist *w = *head;

    while (w != NULL) {
        t_dirlist *temp = w;
        w = w->next;

        free(temp->d_name);
        free(temp->path);
        free(temp->stattemp);
        free(temp);
    }
    *head = NULL;
}
