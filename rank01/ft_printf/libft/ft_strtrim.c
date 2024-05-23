/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:39:39 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/06 16:45:13 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*s2;
	int			start;
	int			end;
	int			i;

	i = ft_strlen(s1) - 1;
	s2 = s1;
	start = 0;
	end = 0;
	while (ft_strchr(set, *s2) != NULL)
	{
		s2 ++;
		start ++;
	}
	while (ft_strchr(set, s1[i]) != NULL)
	{
		i --;
		end++;
	}
	return (ft_substr(s1, start, (ft_strlen(s1) - start - end)));
}
