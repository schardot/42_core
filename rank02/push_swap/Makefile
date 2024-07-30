# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
NAME = push_swap

# Targets
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
