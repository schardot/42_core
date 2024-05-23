#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

int	ft_printf(const char *s, ...);

int ft_printchar(char c);
int ft_printstr(char *s);
int ft_putaddr(long long ptr, char *base);
int ft_putnbr_base(int nbr, char *base);
long putnegative(int nbr, int *len);
long long ft_expo(long n, long powerof);
int ft_printnbr(int nb);

#endif
