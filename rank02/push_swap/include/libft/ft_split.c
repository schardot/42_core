/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:36:16 by nleite-s          #+#    #+#             */
/*   Updated: 2024/09/24 14:11:02 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_count_words(const char *s, char c)
{
	int	counter;
	int	in_word;

	counter = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_word)
			{
				counter++;
				in_word = 0;
			}
		}
		else
		{
			if (!in_word)
				in_word = 1;
		}
		s++;
	}
	if (in_word)
		counter++;
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;
	int		words;

	words = ft_count_words(s, c);
	i = 0;
	result = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		result[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!result[i])
			return (NULL);
		ft_strlcpy(result[i], s, len + 1);
		s += len;
		i++;
	}
	return (result);
}