/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:39:57 by nleite-s          #+#    #+#             */
/*   Updated: 2024/04/23 18:39:59 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len > 0)
	{
		*ptr = (unsigned char)c;
		len --;
		ptr ++;
	}
	return (b);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	s[] = "palavra";
// 	int	c = 'a';
// 	size_t  len = ft_strlen(s);
//     printf("Before memset: %s\n", s);
//     ft_memset(s, c, len);
//     printf("After memset: %s\n", s);
//     ft_memset(s, c, len);
// }
