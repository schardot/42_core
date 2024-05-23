#include "printf.h"
#include "libft/libft.h"

int	ft_putnbr_base(int nbr, char *base)
{
	int		div;
	int		round;
	int	len;
	long long	number;

	len = 0;
	round = 0;
	number = putnegative(nbr, &len);
	if (number == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	while (16 > 0 && number >= ft_expo(16, round))
		round ++;
	while (round --, round >= 0)
	{
		div = number / (ft_expo(16, round));
		number %= (ft_expo(16, round));
		write(1, &base[div], 1);
		len ++;
	}
	return (len);
}

long putnegative(int nbr, int *len)
{
	long n;

	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		*len ++;
		n = -n;
	}
	return (n);
}

long long	ft_expo(long n, long powerof)
{
	long long	number;

	number = 1;
	while (powerof -- > 0)
		number *= n;
	return (number);
}