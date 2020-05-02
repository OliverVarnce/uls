#include "uls.h"

static void print_perm_type(mode_t val);
static char return_acl(char *filename);

void mx_print_perm_and_link(t_dirlist *w, t_col_size info) {
    mx_printchar(mx_get_file_type(w->stattemp->st_mode));
    print_perm_type(w->stattemp->st_mode);
    mx_printchar(return_acl(w->path));
    mx_printchar(' ');
    for (int i = info.col_one_size - mx_get_nums(w->stattemp->st_nlink);
    i > 0; i--)
        mx_printchar(' ');
    mx_printint(w->stattemp->st_nlink);
    mx_printchar(' ');
}

void print_perm_type(mode_t val) {
    S_IRUSR == (S_IRUSR & val) ? mx_printchar('r') : mx_printchar('-');
    S_IWUSR == (S_IWUSR & val) ? mx_printchar('w') : mx_printchar('-');
    S_IXUSR == (S_IXUSR & val) ? (val & 0x800 ? mx_printchar('s')
                : mx_printchar('x'))
                : (val & 0x800 ? mx_printchar('S') : mx_printchar('-'));
    S_IRGRP == (S_IRGRP & val) ? mx_printchar('r') : mx_printchar('-');
    S_IWGRP == (S_IWGRP & val) ? mx_printchar('w') : mx_printchar('-');
    S_IXGRP == (S_IXGRP & val) ? (val & 0x400 ? mx_printchar('s')
                : mx_printchar('x'))
                : (val & 0x400 ? mx_printchar('S') : mx_printchar('-'));
    S_IROTH == (S_IROTH & val) ? mx_printchar('r') : mx_printchar('-');
    S_IWOTH == (S_IWOTH & val) ? mx_printchar('w') : mx_printchar('-');
    S_IXOTH == (S_IXOTH & val) ? (val & 0x200 ? mx_printchar('t')
                : mx_printchar('x'))
                : (val & 0x200 ? mx_printchar('T') : mx_printchar('-'));
}

static char return_acl(char *filename) {
        acl_t acl = acl_get_file(filename, ACL_TYPE_EXTENDED);
    
    if (listxattr(filename, NULL, 0, XATTR_NOFOLLOW) > 0) {
        acl_free(acl);
        return '@';
    } 
    else if (acl == NULL) {
        acl_free(acl);
        return ' ';
    }
    else {
        acl_free(acl);
        return '+';
    }
}
