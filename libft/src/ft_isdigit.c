/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:21:24 by nleite-s          #+#    #+#             */
/*   Updated: 2024/04/23 18:21:25 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
// #include <stdio.h>
// int main()
// {
//     char ch = '8';

//     if (ft_isdigit(ch))
//     {
//         printf("%c is a digit.\n", ch);
//     }
//     else
//     {
//         printf("%c is not a digit.\n", ch);
//     }

//     return 0;
// }
