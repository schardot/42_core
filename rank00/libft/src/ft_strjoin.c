/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:42:03 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/06 16:42:05 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*big;
	int		len1;
	int		len2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	big = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (big == NULL)
		return (NULL);
	ft_strlcpy(big, s1, len1 + len2 + 1);
	ft_strlcat(big, s2, len1 + len2 + 1);
	return (big);
}
