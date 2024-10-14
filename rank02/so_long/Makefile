CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SRC_DIR = srcs
SRCS = $(SRC_DIR)/new_game.c \
       $(SRC_DIR)/map_check.c \
	   $(SRC_DIR)/map_file.c \
	   $(SRC_DIR)/map_grid.c \
	   $(SRC_DIR)/render_game.c \
	   $(SRC_DIR)/key_handler.c \
	   $(SRC_DIR)/exit.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = include/libft
PRINTF_DIR = include/libft/ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -lmlx -lX11 -lXext

.PHONY: all clean fclean re

all: $(LIBFT) $(PRINTF) so_long

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

so_long: $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -Iinclude -o so_long $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f so_long
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

re: fclean all