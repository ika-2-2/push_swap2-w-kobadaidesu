NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRCS = daigo_main.c \
	context.c \
	parse.c \
	error.c \
	stack.c \
	compression.c \
	disorder.c \
	sort_simple.c \
	sort_small.c \
	sort_selection.c \
	bench_names.c \
	bench_print.c \
	bench_print_utils.c \
	operation_count.c \
	operation_push.c \
	operation_swap.c \
	operation_rotate.c \
	operation_reverse_rotate.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_lotate.c
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
