#include "uls.h"

int mx_list_size_dir(t_dirlist *list, int *max_len) {
    int size = 0;

    for (t_dirlist *w = list; w != NULL; w = w->next) {
        int len = mx_strlen(w->d_name);

        if (len > *max_len)
            *max_len = len;
        size++;
    }
    return size;
}
