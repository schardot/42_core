/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:34:57 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/06 09:54:48 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*aux;
	char	*d;
	size_t	i;

	aux = (char *)malloc(len);
	if (aux == NULL)
	{
		free(aux);
		return (NULL);
	}
	d = dst;
	ft_bzero(aux, sizeof(char) * len);
	ft_memcpy(aux, src, sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		d[i] = aux[i];
		i++;
	}
	free(aux);
	return (&d[0]);
}

