#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

int	ft_printf(const char *s, ...);
void	ft_putaddr(long long ptr, char  *base);
long	putnegative(int nbr);
long long	ft_expo(long n, long powerof);
void	ft_putnbr_base(int nbr, char *base);

#endif
