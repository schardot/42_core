/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:43:10 by nleite-s          #+#    #+#             */
/*   Updated: 2024/04/23 18:43:11 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	while (n > 0)
	{
		*d++ = *s++;
		n --;
	}
	return (dest);
}

// #include <stdio.h>

// int main(void)
// {
//     char dest[] = "Hello";
//     char src[] = "abc";

//     printf("Before memcpy, dest: %s\n", dest);
//     printf("After: %s\n", (char *)ft_memcpy(dest, src, ft_strlen(dest)));
// }
