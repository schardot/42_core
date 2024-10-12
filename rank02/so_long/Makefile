CC = cc
CFLAGS = -g #-framework OpenGL -framework AppKit

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
MINILIBX_DIR = include/minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MINILIBX = $(MINILIBX_DIR)/minilibx.a

LIBS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -L$(MINILIBX_DIR) -lft -lftprintf -lmlx -L/usr/X11/lib -lX11 -lXext -lXrandr

.PHONY: all clean fclean re

all: $(LIBFT) $(PRINTF) $(MINILIBX) so_long

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

so_long: $(LIBFT) $(PRINTF) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) -Iinclude -o so_long $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f so_long
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all