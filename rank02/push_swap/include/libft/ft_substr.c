/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:40:00 by nleite-s          #+#    #+#             */
/*   Updated: 2024/09/24 10:12:26 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char	*substr;
	size_t	str_len;
    if (!s)
        return NULL;
    str_len = ft_strlen(s);
    if (start >= str_len)
    {
        substr = (char *)malloc(1);
        if (substr)
            substr[0] = '\0';
        return substr;
    }
    if (len > str_len - start)
        len = str_len - start;
    substr = (char *)malloc(len + 1);
    if (!substr)
        return NULL;
    ft_strlcpy(substr, s + start, len + 1);
    return substr;
}

