NAME = push_swap

SRCS = src/push_swap.c \
	src/push.c \
	src/rotate.c \
	src/reverse_rotate.c \
	src/swap.c \
	src/input_error.c \
	src/stack.c \
	src/small.c \
	src/shrink.c \
	src/input.c

LIBFT_DIR = libft

LIBFT_OBJ = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_OBJ)

$(LIBFT_OBJ):
	make bonus -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
