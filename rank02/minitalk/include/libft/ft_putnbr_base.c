/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:24:53 by nataliaschard     #+#    #+#             */
/*   Updated: 2024/08/12 19:24:55 by nataliaschard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_checkbase(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;
	int		div;
	int		round;
	long	number;

	round = 0;
	b = ft_checkbase(base);
	if (b <= 1)
		return ;
	number = isnegative(nbr);
	if (number == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	while (b > 0 && number >= ft_expo(b, round))
		round ++;
	while (round --, round >= 0)
	{
		div = number / (ft_expo(b, round));
		number %= (ft_expo(b, round));
		write(1, &base[div], 1);
	}
}

static int	ft_checkbase(char *b)
{
	int	i;

	i = -1;
	while (i ++, b[i] != '\0')
	{
		if (b[i] == '+' || b[i] == '-' || b[i] == b[i - 1])
			return (1);
	}
	if (i < 2)
		return (1);
	return (i);
}

long	isnegative(int nbr)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	return (n);
}

long	ft_expo(long n, long powerof)
{
	long	number;

	number = 1;
	while (powerof > 0)
	{
		number *= n;
		powerof --;
	}
	return (number);
}
