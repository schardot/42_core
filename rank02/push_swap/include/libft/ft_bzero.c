/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:41:25 by nleite-s          #+#    #+#             */
/*   Updated: 2024/04/23 18:41:26 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[] = "palavra";
// 	size_t  len = ft_strlen(s);
//     printf("Before bzero: %s\n", s);
//     ft_bzero(s, len);
//     printf("After bzero: ");
//     for (size_t i = 0; i < len; i++)
//     {
//         printf("%d", (unsigned char)s[i]);
//     }
//     printf("\n");
// }
