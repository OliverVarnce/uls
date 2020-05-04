#include "uls.h"

void mx_push_front_dir(t_dirlist **list, const char *d_name,
const char *path) {
    t_dirlist *new_node = mx_create_node_dir(d_name, path);
    new_node->next = *list;
    *list = new_node;
}
