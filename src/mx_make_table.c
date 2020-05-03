#include "uls.h"

static t_node **create_table(int rows, int cols) {
    t_node **arr;

    arr = (t_node **)malloc(rows * sizeof(t_node*));
    for (int i = 0; i < rows; i++)
        arr[i] = (t_node *)malloc(cols * sizeof(t_node *));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j].ptr = NULL;

    return arr;
}

static void fill_table(t_dirlist *head, t_node **arr, int rows) {
    int row = 0;
    int col = -1;

    for (t_dirlist *w = head; w != NULL; w = w->next) {
        if (row % rows == 0) {
            row = 0;
            col++;
        }
        arr[row][col].ptr = w;
        row++;
    }
}

static void print_table(t_node **arr, t_table_info table, int col_width,
        t_flags *opts) {
    int str_len = 0;
    int tabs = 0;
    for (int i = 0; i < table.rows; i++) {
        for (int j = 0; j < table.cols; j++)
            if (arr[i][j].ptr != NULL) {
                mx_else_FG (opts, arr, i, j);
                if (j != table.cols - 1
                    && !(j == table.cols - 2 && arr[i][j+1].ptr == NULL)) {
                        str_len = mx_strlen(arr[i][j].ptr->d_name);
                    if (opts->flag_F)
                        str_len +=  1;
                    tabs = (col_width - str_len) / 8;
                    mx_print_table_FG(opts, col_width, str_len, tabs);
                }
            }
        mx_printchar('\n');
    }
}

static void delete_table(t_node ***arr, int rows) {
    for (int i = 0; i < rows; i++)
        free((*arr)[i]);

    free(*arr);
    *arr = NULL;
}

void mx_make_table(t_dirlist *head, t_table_info table, int col_width,
        t_flags *opts) {
    t_node **arr = create_table(table.rows, table.cols);

    if (!arr)
        return;

    fill_table(head, arr, table.rows);
    print_table(arr, table, col_width, opts);
    delete_table(&arr, table.rows);
}
