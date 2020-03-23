#include "uls.h"

void mx_push_back_dir(t_dirlist **list, const char *d_name,
const char *path) {
    if (*list == NULL) {
        *list = mx_create_node_dir(d_name, path);
        return;
    }
    t_dirlist *walker = *list;
    for (; walker->next != NULL; walker = walker->next);
    walker->next = mx_create_node_dir(d_name, path);
}
