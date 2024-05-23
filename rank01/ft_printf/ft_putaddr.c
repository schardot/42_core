#include "ft_printf.h"
#include "libft/libft.h"

void    ft_putaddr(long long ptr, char  *base)
{
	int	round;
	size_t	div;

	round = 0;
	while (ptr >= ft_expo(16, round))
		round ++;
	while (round -- >= 0)
	{
		div = ptr / (ft_expo(16, round));
		ptr %= (ft_expo(16, round));
		write(1, &base[div], 1);
	}
}
