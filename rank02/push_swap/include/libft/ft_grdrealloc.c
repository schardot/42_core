/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grdrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:32:11 by nleite-s          #+#    #+#             */
/*   Updated: 2024/09/24 09:58:08 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char **ft_grdrealloc(char **ptr, size_t size)
{
	char **newgrid;
	size_t h;

	h = 0;
	newgrid = (char **)malloc(size * sizeof(char *));
	if (!newgrid)
		return (NULL);
	if (ptr)
	{
		while (ptr[h] && h < size)
		{
			newgrid[h] = ptr[h];
			h ++;
		}
		free(ptr);
	}
	while (h < size)
        newgrid[h++] = NULL;
	return (newgrid);
}
