NAME	=	uls

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic)

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/$(INCD)

INC		=	uls.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC     =   main.c \
            mx_else_FG.c \
            mx_list_size_dir.c \
            mx_print_name_or_link.c \
            mx_push_front_dir.c \
            mx_comparator.c \
            mx_errors.c \
            mx_make_table.c \
            mx_print_perm_and_link.c \
            mx_sort_list_dir.c \
            mx_constructor.c \
            mx_get_file_type.c \
            mx_out_1.c \
            mx_print_reg.c \
            mx_sortbylexic.c \
            mx_create_lists.c \
            mx_get_flags.c \
            mx_out_F.c \
            mx_print_size_and_time.c \
            mx_sortbysize.c \
            mx_create_node_dir.c \
            mx_get_nums.c \
            mx_out_G.c \
            mx_print_table.c \
            mx_sortbytmod.c \
            mx_dirlist_del.c \
            mx_init_opts.c \
            mx_out_l.c \
            mx_print_uid_gid.c \
            mx_dirlist_out.c \
            mx_input_arg.c \
            mx_out_no_file.c \
            mx_push_back_dir.c

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: $(LMXD) $(NAME)

$(FILE:a/%=%)

#install: $(LMXA) $(NAME)

$(NAME): $(LMXA) $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXD): $(LMXA)

$(LMXA):
	@make -sC $(LMXD)

clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all
