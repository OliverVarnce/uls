#include "uls.h"

static t_dirlist *make_dir_list(char *path, t_dirlist *list, t_flags *opts,
        int *error_no) {
    DIR *dir = NULL;
    struct dirent *entry;

    dir = opendir(path);
    if (!dir) {
        *error_no = errno;
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL)
        if (!(!opts->flag_a && entry->d_name[0] == '.')
            || (opts->flag_A && !(mx_strcmp(entry->d_name, ".") == 0
            || mx_strcmp(entry->d_name, "..") == 0)))
            mx_push_back_dir(&list, entry->d_name, path);

    closedir(dir);
    list = mx_sort_list_dir(list, opts);
    return list;
}

int mx_check_null_flg(int first_file_pos, int argc, t_flags flag) {
    int is_err = 0;

    if (first_file_pos == argc)
        mx_dir_parser(".", &flag, false, &is_err);

    return is_err;
}

void mx_dir_parser(char *path, t_flags *opts, bool print_header, int *is_err) {
    t_dirlist *list = NULL;
    int error_no = -1;

    list = make_dir_list(path, list, opts, &error_no);
    if (error_no != -1)
        *is_err = 1;

    mx_print_error(path, error_no, print_header);
    mx_dirlist_out(list, opts);

    if (opts->flag_R) {
        for (t_dirlist *w = list; w != NULL; w = w->next) {
            if (mx_get_file_type(w->stattemp->st_mode) == 'd'
                && !(mx_strcmp(w->d_name, ".") == 0
                     || mx_strcmp(w->d_name, "..") == 0)) {
                mx_printchar('\n');
                mx_dir_parser(w->path, opts, true, is_err);
            }
        }
    }
    mx_dirlist_del(&list);
}

void mx_print_selector(t_dirlist *file_list, t_flags flag) {
    if (flag.flag_l)
        mx_out_l(file_list, &flag, false);
    else if (flag.flag_1 || (!isatty(STDOUT_FILENO) && !flag.flag_C))
        mx_out_1(file_list, &flag);
    else
        mx_print_table(file_list, &flag);
}

int mx_constructor(t_dirlist *file_list, t_dirlist *dir_list, t_flags flag,
        int files_cnt) {
    int is_err = 0;

    file_list = mx_sort_list_dir(file_list, &flag);
    dir_list = mx_sort_list_dir(dir_list, &flag);
    mx_print_selector(file_list, flag);
    for (t_dirlist *w = dir_list; w != NULL; w = w->next) {
        if (dir_list->next == NULL && file_list == NULL && files_cnt == 1)
            mx_dir_parser(w->path, &flag, false, &is_err);
        else {
            if (w != dir_list || file_list != NULL)
                mx_printchar('\n');
            mx_dir_parser(w->path, &flag, true, &is_err);
        }
    }
    mx_dirlist_del(&file_list);
    mx_dirlist_del(&dir_list);
    return is_err;
}
