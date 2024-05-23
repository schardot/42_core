/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:36:35 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/07 09:33:42 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	clen;

	len = ft_strlen(src);
	if (dstsize <= 0)
		return (len);
	if (len < dstsize - 1)
		clen = len;
	else
		clen = dstsize - 1;
	ft_memcpy(dst, src, clen);
	dst[clen] = '\0';
	return (len);
}
