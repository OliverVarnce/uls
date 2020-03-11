#ifndef ULS_H
#define ULS_H

#define MX_MINORBITS       24
#define MX_MINORMASK       ((1U << MX_MINORBITS) - 1)
#define MX_MAJOR(dev)      ((unsigned int) ((dev) >> MX_MINORBITS))
#define MX_MINOR(dev)      ((unsigned int) ((dev) & MX_MINORMASK))

#define RED  "\33[31m"
#define YELLOW  "\33[33m"
#define PINK  "\33[35m"
#define AQUA  "\33[36m"
#define BLUE  "\33[34m"
#define GREEN "\33[32m"
#define YELLOW_BLUE  "\33[43m\33[34m"
#define LIGHT_BLUE  "\33[46m\33[34m"
#define GREEN_BLACK "\33[42m\33[30m"
#define BLACK_RED "\33[30m\33[41m"
#define AQUA_BLACK "\33[46m\33[30m"
#define YELLOW_BLACK "\33[43m\33[30m"
#define COLOR_DEFAULT  "\33[0m"

#include "./libmx/inc/libmx.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/errno.h>

typedef struct s_list_dir {
    char *d_name;
    char *path;
    struct stat *stattemp;
    struct s_list_dir *next;
} t_list_dir;

typedef struct s_flags {
    bool flag_l;
    bool flag_C;
    bool flag_1;
    bool flag_a;
    bool flag_A;
    bool flag_G;
    bool flag_r;
    bool flag_R;
    bool flag_T;
    bool flag_n;
    bool flag_g;
    bool flag_u;
    bool flag_c;
    bool flag_S;
    bool flag_t;
}t_flags;

typedef struct s_column_size {
    int col_one_size;
    int col_two_size;
    int col_three_size;
    int col_four_size;
    int total_size; 
    struct passwd *pw;
    struct group *gr;
    int cur_col_one_size;
    int cur_col_two_size;
    int cur_col_three_size;
    int cur_col_four_size;
}t_col_size;

typedef struct s_node {
    t_list_dir *ptr;
}t_node;

typedef struct s_table {
    int cols;
    int rows;
}t_table_info;

typedef void (*fptr)(t_list_dir *first, t_list_dir *second, t_flags *opts);

t_list_dir *mx_create_node_dir(const char *d_name, const char *path);
void mx_push_front_dir(t_list_dir **list, const char *d_name,
const char *path);
void mx_create_lists(char *argv, t_list_dir **f_list, t_list_dir **d_list, t_flags *fl);
void mx_push_back_dir(t_list_dir **list, const char *d_name, const char *path);
int mx_list_size_dir(t_list_dir *list, int *max_len);
void mx_delete_list_dir(t_list_dir **head);
t_list_dir *mx_sort_list_dir(t_list_dir *lst, t_flags *opts);
char mx_get_file_type(mode_t value);
void mx_print_table(t_list_dir *head, t_flags *opts);
void mx_out_l(t_list_dir *lst, t_flags *fl, bool pr_total);
void mx_add_color(char *name, char *col);
void mx_out_G(char *name, mode_t value);
void mx_out_1(t_list_dir *head, t_flags *opts);
int mx_constructor(t_list_dir *file_list, t_list_dir *dir_list, t_flags flag,
int files_cnt);
void mx_dir_parser(char *path, t_flags *opts, bool print_header,
int *is_err);
t_list_dir *mx_make_dir_list(char *path, t_list_dir *list,
t_flags *opts, int *error_no);
void mx_print_dir_list(char *dir_name, t_list_dir *list, t_flags *opts,
bool print_header);
t_flags *mx_get_flags(t_flags *fl, char *flags);
void mx_sortbylexic_desc(t_list_dir *first, t_list_dir *second, t_flags *opts);
void mx_sortbysize_desc(t_list_dir *first, t_list_dir *second, t_flags *opts);
void mx_sortbytmod_desc(t_list_dir *first, t_list_dir *second, t_flags *opts);
void mx_sortbylexic_asc(t_list_dir *first, t_list_dir *second, t_flags *opts);
void mx_sortbysize_asc(t_list_dir *first, t_list_dir *second, t_flags *opts);
void mx_sortbytmod_asc(t_list_dir *first, t_list_dir *second, t_flags *opts);
void mx_swap(t_list_dir *first, t_list_dir *second);
struct timespec mx_get_time_type(t_list_dir *node, t_flags *opts);
int mx_get_nums(int num);
void mx_print_perm_and_link(t_list_dir *w, t_col_size info);
void mx_print_size_and_time(t_list_dir *w, t_flags *fl, t_col_size info);
void mx_print_uid_gid(t_list_dir *w, t_flags *fl, t_col_size info);
void mx_print_name_or_link(t_list_dir *w, t_flags *fl);
void mx_err_dir(char *path);
void mx_print_bad_list(t_list *lst);
bool mx_cmp(void *s1, void *s2);
void mx_printerror(char *path, int error_no, bool print_header);
bool mx_is_valid_flag(char *s);
void mx_make_table(t_list_dir *head, t_table_info table, int col_width,
t_flags *opts);

#endif
