#include "printf.h"
#include "libft/libft.h"

int ft_printchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_printstr(char *s)
{
    int i;

    i = 0;
	while (s[i] != '\0')
	{
		ft_printchar(s[i]);
		i ++;
	}
	return (i);
}

int ft_putaddr(long long ptr, char *base)
{
	int round;
	int i;
	size_t div;

	round = 0;
	i = 0;
	while (ptr >= ft_expo(16, round))
		round++;
	while (round-- >= 0)
	{
		div = ptr / (ft_expo(16, round));
		ptr %= (ft_expo(16, round));
		write(1, &base[div], 1);
		i++;
	}
	return (i);
}

int ft_printnbr(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len += ft_printchar('-');
	}
	if (nb < 10)
		len += ft_printchar('0' + nb);
	else
	{
		len += ft_printnbr(nb / 10);
		len += ft_printnbr(nb % 10);
	}
	return (len);
}