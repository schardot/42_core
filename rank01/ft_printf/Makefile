SRCS = ft_printf.c ft_putaddr.c ft_putnbr_base.c

OBJS_S = $(SRCS:.c=.o)

CC = cc

RM = rm -f

RN = ranlib

CFLAGS = -Wall -Wextra -Werror -I./libft

NAME = libftprintf.a

all: $(NAME)

libft:
	$(MAKE) -C libft

$(NAME): libft $(OBJS_S)
	ar rcs $(NAME) $(OBJS_S)
	${RN} ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS_S)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
