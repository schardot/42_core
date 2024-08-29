CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Source and Object files for client and server
CLIENT_S = client.c
CLIENT_O = $(CLIENT_S:.c=.o)
SERVER_S = server.c
SERVER_O = $(SERVER_S:.c=.o)

# Directories for libft and ft_printf
LIBFT_DIR = include/libft
PRINTF_DIR = include/libft/ft_printf

# Library files
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Include and Library directories
INCLUDE_DIR = include
INCLUDES = -I$(INCLUDE_DIR)
LIBS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf

.PHONY: all clean fclean re

# All target compiles the client and server
all: $(LIBFT) $(PRINTF) client server

# Build libft and ft_printf libraries
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Link client and server with the libraries
client: $(CLIENT_O) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o client $(CLIENT_O) $(LIBS)

server: $(SERVER_O) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o server $(SERVER_O) $(LIBS)

# Compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	rm -f $(CLIENT_O) $(SERVER_O)

# Clean object files and executables
fclean: clean
	rm -f client server

# Rebuild everything
re: fclean all
