CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make $(CFLAGS) -C ./libft
	cp ./libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)

bonus: all

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
