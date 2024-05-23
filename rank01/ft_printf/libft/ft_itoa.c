/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:50:35 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/06 16:50:36 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(long n);
static char		*iszero(long n);
static long		sign(int n, char *str);

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	size_t	len;
	long	longn;

	result = iszero(n);
	if (result != NULL)
		return (result);
	else
		free (result);
	len = intlen(n);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	longn = sign(n, result);
	i = 0;
	while (longn > 0)
	{
		result[(len - 1) - i] = (longn % 10) + '0';
		longn /= 10;
		i ++;
	}
	result[len] = '\0';
	return (result);
}

static size_t	intlen(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len ++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len ++;
	}
	len ++;
	return (len);
}

static char	*iszero(long n)
{
	char	*result;

	result = NULL;
	if (n == 0)
	{
		result = (char *)malloc(2 * sizeof(char));
		if (result == NULL)
		{
			free (result);
			return (NULL);
		}
		result[0] = '0';
		result[1] = '\0';
	}
	return (result);
}

static long	sign(int n, char *str)
{
	long	longn;

	longn = n;
	if (longn < 0)
	{
		str[0] = '-';
		longn *= -1;
	}
	return (longn);
}
