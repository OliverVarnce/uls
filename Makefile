NAME = uls

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC   = mx_create_node_dir \
		mx_sortbysize \
		mx_sortbylexic \
		mx_sortbytmod \
		mx_delete_list_dir \
		mx_get_file_type \
		mx_list_size_dir \
		mx_out_1 \
		mx_out_G \
		mx_print_table \
		mx_out_l \
		mx_push_back_dir \
		mx_push_front_dir \
		mx_sort_list_dir \
		mx_constructor \
		mx_get_flags \
		mx_print_perm_and_link \
		mx_print_size_and_time \
		mx_print_uid_gid \
		mx_get_nums \
		mx_print_name_or_link \
		mx_other \
		main \
		mx_make_table \
		mx_create_lists

SRCS = $(addsuffix .c, $(SRC))

OBJO = $(SRCS:.c=.o)

INC = uls.h

LIBAR = libmx/libmx.a

all: install clean

install:
	@make -f Makefile install --directory=libmx
	@mkdir obj
	@cp $(addprefix src/, $(SRCS)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRCS) -I $(INC)
	@clang $(CFLGS) $(OBJO) $(LIBAR) -o $(NAME) -I $(LIBAR)

uninstall: clean
	@rm -rf $(NAME)
	@make -f Makefile uninstall --directory=libmx

clean:
	@make -f Makefile clean --directory=libmx
	@rm -rf $(SRCS)
	@rm -rf $(INC)
	@rm -rf $(addsuffix .o, $(SRC))
	@rm -rf ./obj
	
reinstall: uninstall install
