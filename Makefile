NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRCS = daigo_main.c \
	config.c \
	parse.c \
	error.c \
	stack.c \
	compression.c \
	disorder.c \
	bench_names.c \
	bench_print.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
