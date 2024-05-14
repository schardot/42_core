/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:34:30 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/13 10:36:38 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	temp_c;

	i = 0;
	temp_c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == temp_c)
			return ((char *)&s[i]);
		i ++;
	}
	if (s[i] == temp_c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
