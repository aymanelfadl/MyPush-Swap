NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c stack_utils.c swap_stacks.c rotate_stacks.c push_stacks.c \
	reverse_rotate_stacks.c args_parser.c args_parser_utils.c index_stack.c \
	sort_stack.c values_position.c operation_cost.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re