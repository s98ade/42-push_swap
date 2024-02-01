NAME =libftprintf.a
LIBFT =libft/libft.a
LIBFT_DIR =libft
CC = cc
AR = ar rcs
CP = cp
RM =rm -rf
CFLAGS =-Wall -Wextra -Werror

SRCS = \
	   ft_printf.c \
	   ft_print_chr.c \
	   ft_print_str.c \
	   ft_print_ptr.c \
	   ft_print_digit.c \
	   ft_print_unsigned.c \
	   ft_print_percent.c \
	   ft_print_hex_lower.c \
	   ft_print_hex_upper.c \

OBJ =${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CP) $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJ)

$(LIBFT) : $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
clean :
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean : clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
