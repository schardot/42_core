CC = cc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

SRC_DIR = srcs
BONUS_SRC_DIR = $(SRC_DIR)/bonus
LIBFTDIR = include/libft
PRINTF_DIR = include/libft/ft_printf
INCLUDE_DIR = include

NAME = push_swap
BONUS = checker

PUSH_SRCS = $(SRC_DIR)/push_swap.c
SRCS = $(SRC_DIR)/linked_list_utils.c \
       $(SRC_DIR)/operations.c \
       $(SRC_DIR)/preprocessing.c \
	   $(SRC_DIR)/argc_two_helpers.c \
       $(SRC_DIR)/update_stacks.c \
       $(SRC_DIR)/sorting_utils.c

BONUS_SRCS = $(BONUS_SRC_DIR)/checker.c

OBJS_S = $(SRCS:.c=.o)
OBJS_P = $(PUSH_SRCS:.c=.o)
OBJS_B = $(BONUS_SRCS:.c=.o)

INCLUDE = -L$(LIBFTDIR) -L$(PRINTF_DIR) -lft -lftprintf
INCLUDES = -I$(INCLUDE_DIR)

all: $(NAME)

$(NAME): $(OBJS_S) $(OBJS_P)
	$(MAKE) -C $(LIBFTDIR)  # Build libft
	$(MAKE) -C $(PRINTF_DIR) # Build ft_printf
	$(CC) $(CFLAGS) $(OBJS_S) $(OBJS_P) -o $(NAME) $(INCLUDE)

bonus: $(OBJS_S) $(OBJS_B)
	$(MAKE) -C $(LIBFTDIR)  # Build libft
	$(MAKE) -C $(PRINTF_DIR) # Build ft_printf
	$(CC) $(CFLAGS) $(OBJS_S) $(OBJS_B) -o $(BONUS) $(INCLUDE)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: $(BONUS_SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS_S) $(OBJS_B) $(OBJS_P)
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(PRINTF_DIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(PRINTF_DIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus
