/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:38:20 by nleite-s          #+#    #+#             */
/*   Updated: 2024/04/23 18:38:23 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;
	int	i;

	i = 0;
	length = 0;
	while (s[i] != '\0')
	{
		length ++;
		i ++;
	}
	return (length);
}
// #include <stdio.h>

// int main(void)
// {
// 	char    *s = "palavra";
// 	printf("%ld", ft_strlen(s));
// }
