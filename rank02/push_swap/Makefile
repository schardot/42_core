# Compiler and Flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

# Directories
SRC_DIR = srcs
BONUS_SRC_DIR = $(SRC_DIR)/bonus
LIBFTDIR = include/libft
PRINTF_DIR = include/libft/ft_printf
INCLUDE_DIR = include

# Executables
NAME = push_swap
BONUS = checker

# Source files
PUSH_SRCS = $(SRC_DIR)/push_swap.c
SRCS = $(SRC_DIR)/linked_list_utils.c \
       $(SRC_DIR)/operations.c \
       $(SRC_DIR)/preprocessing.c \
       $(SRC_DIR)/update_stacks.c \
       $(SRC_DIR)/sorting_utils.c

BONUS_SRCS = $(BONUS_SRC_DIR)/checker.c

# Object files
OBJS_S = $(SRCS:.c=.o)
OBJS_P = $(PUSH_SRCS:.c=.o)
OBJS_B = $(BONUS_SRCS:.c=.o)

# Library paths
INCLUDE = -L$(LIBFTDIR) -L$(PRINTF_DIR) -lft -lftprintf
INCLUDES = -I$(INCLUDE_DIR)

# Default target
all: $(NAME)

# Build main executable
$(NAME): $(OBJS_S) $(OBJS_P)
	$(MAKE) -C $(LIBFTDIR)  # Build libft
	$(MAKE) -C $(PRINTF_DIR) # Build ft_printf
	$(CC) $(CFLAGS) $(OBJS_S) $(OBJS_P) -o $(NAME) $(INCLUDE)

# Build bonus executable
bonus: $(OBJS_S) $(OBJS_B)
	$(MAKE) -C $(LIBFTDIR)  # Build libft
	$(MAKE) -C $(PRINTF_DIR) # Build ft_printf
	$(CC) $(CFLAGS) $(OBJS_S) $(OBJS_B) -o $(BONUS) $(INCLUDE)

# Compile object files
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: $(BONUS_SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files and executables
clean:
	$(RM) $(OBJS_S) $(OBJS_B) $(OBJS_P)
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(PRINTF_DIR) && $(MAKE) clean

# Clean all
fclean: clean
	$(RM) $(NAME) $(BONUS)
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(PRINTF_DIR) && $(MAKE) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus
