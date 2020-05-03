#include "uls.h"

void get_rc_num(int items, int win_width, int col_width, t_table_info *table) {
    int tot_width = items * col_width;

    if (col_width < win_width) {
        while (tot_width > win_width) {
            table->cols = 0;
            table->rows++;
            for (int i = 0; i < items; i++) {
                if (i % table->rows == 0)
                    table->cols++;
            }
            tot_width = table->cols * col_width;
        }
    }
    else {
        table->cols = 1;
        table->rows = items;
    }
}

void mx_print_table(t_dirlist *head, t_flags *opts) {
    int col_width = 0;
    int items = mx_list_size_dir(head, &col_width);
    t_table_info table;
    struct winsize w;
    
    table.cols = items;
    table.rows = 1;
    if (items == 0)
        return;
    ioctl(0, TIOCGWINSZ, &w);

    col_width = opts->flag_G ? col_width : col_width + 8 - col_width % 8;

    get_rc_num(items, (isatty(STDOUT_FILENO) ? w.ws_col : LS_STATIC_WIN_SIZE),
    col_width, &table);
    mx_make_table(head, table, col_width, opts);
}
