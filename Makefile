CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRCS=ft_printf.c \
	 part_of_parse.c \
	 part_of_print_conversion.c \
	 part_of_print_signed.c \
	 part_of_print_unsigned.c \
	 part_of_print_str.c \
	 part_of_print_signed_and_unsigned.c \
	 part_of_print_str.c \
	 part_of_convert_print_s_and_u.c \

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) $(CFLAGS) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
