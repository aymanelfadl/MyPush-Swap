NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c stack_utils.c swap_stacks.c rotate_stacks.c push_stacks.c \
	reverse_rotate_stacks.c args_parser.c args_parser_utils.c index_stack.c \
	sort_stack.c values_position.c operation_cost.c

BSRCS = checker_bonus.c stack_utils.c swap_stacks.c rotate_stacks.c push_stacks.c \
	reverse_rotate_stacks.c args_parser.c args_parser_utils.c index_stack.c \
	sort_stack.c values_position.c operation_cost.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
LIBFT_DIR = libft
GETNEXTLINEDIR = getNextLine
LIBFT = $(LIBFT_DIR)/libft.a
GETNEXTLINE = $(GETNEXTLINEDIR)/libgnl.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GETNEXTLINE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft
	
bonus: $(BOBJS) $(GETNEXTLINE) $(LIBFT)
	$(CC) $(CFLAGS) -o checker $(BOBJS) -L$(LIBFT_DIR) -lft -L$(GETNEXTLINEDIR) -lgnl

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GETNEXTLINE):
	make -C $(GETNEXTLINEDIR)

clean:
	rm -f $(OBJS) $(BOBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) checker
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus