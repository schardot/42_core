/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:36:48 by nleite-s          #+#    #+#             */
/*   Updated: 2024/04/23 18:36:50 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c < 127);
}
// #include <stdio.h>

// int main(void)
// {
//     int c;

//     c = 127;
//     if (ft_isprint(c))
//         printf("yes its printabke");
//     else
//         printf("no it is not printable");
// }
