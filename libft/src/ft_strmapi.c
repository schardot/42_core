/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:38:13 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/06 14:38:18 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	unsigned int	i;

	i = 0;
	if(!(result = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i ++;
	}
	result[i] = '\0';
	return (result);
}
