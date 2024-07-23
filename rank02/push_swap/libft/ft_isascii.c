/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:36:06 by nleite-s          #+#    #+#             */
/*   Updated: 2024/04/23 18:36:08 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
// #include <stdio.h>
// int main()
// {
//     char ch = 's';

//     if (ft_isascii(ch))
//     {
//         printf("%c is ascii.\n", ch);
//     }
//     else
//     {
//         printf("%c is not ascii.\n", ch);
//     }

//     return 0;
// }
