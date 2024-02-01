NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRC_PATH = src/
OBJ_PATH = obj/

SRC_ALL =	main.c \
			initialization.c \
			mini_sort.c \
			micro_sort.c \
			stack_utils.c \
			swap.c \
			utils.c \
			rotate.c \
			rev_rotate.c \
			push.c \
			check.c \
			sort.c \
			check_utils.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC_ALL))
LIBFT = Libft/libft.a
OBJ_ALL =	$(SRC_ALL:.c=.o)
OBJS =	$(addprefix $(OBJ_PATH), $(OBJ_ALL))
INCS =	-I ./includes/

all:	$(OBJ_PATH) $(NAME)

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	make -C ./Libft
	@$(CC) $(CFLAGS) $(OBJS) ./Libft/libft.a -o $(NAME)
	@echo "$(GREEN)Compilation of '$(NAME)' completed successfully$(NC)"

clean:
	make clean -C ./Libft
	@rm -rf $(OBJ_PATH)

fclean:
	make fclean -C ./Libft
	@rm -f $(NAME)
	@echo "$(BLUE)Removed '$(NAME)'$(NC)"

re: fclean all
	@echo "$(GREEN)Everything recompiled$(NC)"

.PHONY: all clean fclean re