CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

CLIENT_S = client.c
CLIENT_O = $(CLIENT_S:.c=.o)
SERVER_S = server.c
SERVER_O = $(SERVER_S:.c=.o)

BONUS_SCL = client_bonus.c
BONUS_OCL = $(BONUS_SCL:.c=.o)
BONUS_SSE = server_bonus.c
BONUS_OSE = $(BONUS_SSE:.c=.o)

LIBFT_DIR = include/libft
PRINTF_DIR = include/libft/ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCLUDE_DIR = include
INCLUDES = -I$(INCLUDE_DIR)
LIBS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf

.PHONY: all clean fclean re

all: $(LIBFT) $(PRINTF) client server

bonus: $(LIBFT) $(PRINTF) client_bonus server_bonus

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

client: $(CLIENT_O) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o client $(CLIENT_O) $(LIBS)

server: $(SERVER_O) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o server $(SERVER_O) $(LIBS)

client_bonus: $(BONUS_OCL) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o client_bonus $(BONUS_OCL) $(LIBS)

server_bonus: $(BONUS_OSE) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o server_bonus $(BONUS_OSE) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(CLIENT_O) $(SERVER_O) $(BONUS_OCL) $(BONUS_OSE)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f client server client_bonus server_bonus
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all
