CHECKER = checker
PUSH_SWAP = push_swap

FLAGS = -g -Wall -Werror -Wextra

INCLUDES = -I ./includes

SRC_CK =	main_checker.c

SRC_PS =	main_push_swap.c

COMMON =	check_string_argv.c \
			push_init_stacks.c \
			program_answers.c \
			operations_s.c \
			operations_p.c \
			operations_r.c \
			operations_rr.c \
			check_stdin_operations.c \
			push_swap_processing.c \
			investigations_in_a_stack.c \
			other_functions.c \
			print_for_convenience.c

DIR_O_CK = objs_ck
DIR_O_PS = objs_ps
DIR_O_COM = objs_common

DIR_S_CK = srcs_ck
DIR_S_PS = srcs_ps
DIR_S_COM = both_ck_ps

SRCS_CK = $(addprefix $(DIR_S_CK)/,$(SRC_CK))
SRCS_PS = $(addprefix $(DIR_S_PS)/,$(SRC_PS))
SRCS_COMMON = $(addprefix $(DIR_S_COM)/,$(COMMON))

OBJS_CK = $(addprefix $(DIR_O_CK)/,$(SRC_CK:.c=.o))
OBJS_PS = $(addprefix $(DIR_O_PS)/,$(SRC_PS:.c=.o))
OBJS_COMMON = $(addprefix $(DIR_O_COM)/,$(COMMON:.c=.o))

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(OBJS_CK) $(OBJS_COMMON)
	@echo "\033[1;32mCompiling push_swap...\033[0m"
	@make -C ./libft
	gcc $(FLAGS) $(OBJS_CK) $(OBJS_COMMON) -o $(CHECKER) libft/libft.a

$(OBJS_CK): $(DIR_O_CK)/%.o: $(DIR_S_CK)/%.c includes/push_swap.h
	@mkdir -p $(DIR_O_CK)
	@gcc $(FLAGS) -c $(INCLUDES) -o $@ $<

$(OBJS_COMMON): $(DIR_O_COM)/%.o: $(DIR_S_COM)/%.c includes/push_swap.h
	@mkdir -p $(DIR_O_COM)
	@gcc $(FLAGS) -c $(INCLUDES) -o $@ $<

$(PUSH_SWAP): $(OBJS_PS) $(OBJS_COMMON)
	gcc $(FLAGS) $(OBJS_PS) $(OBJS_COMMON) -o $(PUSH_SWAP) libft/libft.a
	@echo "\033[1;32mPush_swap and checker are ready\033[0m"

$(OBJS_PS): $(DIR_O_PS)/%.o: $(DIR_S_PS)/%.c includes/push_swap.h
	@mkdir -p $(DIR_O_PS)
	@gcc $(FLAGS) -c $(INCLUDES) -o $@ $<

clean:
	@echo "\033[34mDeleting push_swap o-files\033[0m"
	@/bin/rm -Rf $(DIR_O_CK) $(DIR_O_PS) $(DIR_O_COM)
	@make clean --directory ./libft

fclean:	clean
	@echo "\033[34mDeleting push_swap binary\033[0m"
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)
	@make fclean --directory ./libft

re:		fclean all

.PHONY:	all clean fclean re
