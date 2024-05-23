/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:14:02 by nleite-s          #+#    #+#             */
/*   Updated: 2024/04/23 17:14:07 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
// #include <stdio.h>
// int main()
// {
//     char ch = 'a';

//     if (ft_isalpha(ch))
//     {
//         printf("%c is an alphabetic character.\n", ch);
//     }
//     else
//     {
//         printf("%c is not an alphabetic character.\n", ch);
//     }

//     return 0;
// }
