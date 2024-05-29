SRCS = ft_printf.c format_csp.c format_diuxX.c

OBJS_S = $(SRCS:.c=.o)

CC = cc

RM = rm -f

RN = ranlib

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS_S)
	ar r $(NAME) $(OBJS_S)
	${RN} ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_S)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
