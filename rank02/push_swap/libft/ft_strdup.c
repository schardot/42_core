/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:02:20 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/06 13:02:22 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*cpy;

	len = ft_strlen(str);
	cpy = (char *)malloc(len + 1);
	if (cpy != NULL)
	{
		ft_strlcpy(cpy, str, len + 1);
		return (cpy);
	}
	else
		return (NULL);
}
