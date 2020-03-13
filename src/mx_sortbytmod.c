#include "uls.h"

void mx_sortbytmod_asc(t_dirlist *first, t_dirlist *second, t_flags *opts) {
    struct timespec t1 = mx_get_time_type(first, opts);
    struct timespec t2 = mx_get_time_type(second, opts);

    if (t1.tv_sec < t2.tv_sec) {
        mx_swap(first, second);
        return;
    }
    if (t1.tv_sec == t2.tv_sec) {
        if (t1.tv_nsec < t2.tv_nsec) {
            mx_swap(first, second);
            return;
        }
        else if (t1.tv_nsec == t2.tv_nsec) {
            if (mx_strcmp(first->d_name, second->d_name) > 0) {
                mx_swap(first, second);
                return;
            }
        }
    }
}

void mx_sortbytmod_desc(t_dirlist *first, t_dirlist *second, t_flags *opts) {
    struct timespec t1 = mx_get_time_type(first, opts);
    struct timespec t2 = mx_get_time_type(second, opts);

    if (t1.tv_sec > t2.tv_sec) {
        mx_swap(first, second);
        return;
    }
    if (t1.tv_sec == t2.tv_sec) {
        if (t1.tv_nsec > t2.tv_nsec) {
            mx_swap(first, second);
            return;
        }
        else if (t1.tv_nsec == t2.tv_nsec) {
            if (mx_strcmp(first->d_name, second->d_name) < 0) {
                mx_swap(first, second);
                return;
            }
        }
    }
}
