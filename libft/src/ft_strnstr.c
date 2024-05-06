/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:43:56 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/06 14:38:47 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (*big && len >= little_len)
	{
		i = 0;
		while (big[i] == little[i])
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			i ++;
		}
		big ++;
		len --;
	}
	return (NULL);
}
