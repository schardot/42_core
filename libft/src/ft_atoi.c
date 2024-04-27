/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:00:46 by nataliaschard     #+#    #+#             */
/*   Updated: 2024/04/25 15:00:48 by nataliaschard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_isspace(int c);

int	ft_atoi(const char *nptr)
{
	int	r;
	int	sign;

	sign = 1;
	r = 0;
	while (ft_isspace(*nptr))
		nptr ++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr != '\0' && ft_isdigit(*nptr))
	{
		r = (r * 10) + (*nptr - '0');
		nptr++;
	}
	r *= sign;
	return (r);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f')
		return (1);
	else if (c == '\v')
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("result for ft_atoi: %d\n", ft_atoi("+42"));
// 	printf("result for THE REAL atoi: %d\n", atoi("+42"));
// }

// ok ----- atoi retorna 0 qnd em a42
// ok ---- atoi retorna 42 qnd em " 42"
// ok ----- atoi retorna 4 qnd "4 2" meu atoi tb
// ok ----- atoi retorna -42 qnd em "-42", meu atoi retorna 42
// ok ----- atoi retorna 0 qnd "   +-42", meu atoi retorna 42
// ok ----- atoi retorna 0 qnd "   ++42", meu atoi retorna 42
// ok ----- atoi retorna 0 qnd "   --42"
// ok ----- atoi retorna 0 qnd " + 42", meu atoi tbm
// atoi retorna 42 qnd "+42", meu atoi tbm
