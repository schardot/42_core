/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:32:56 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/15 11:55:00 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (count == 0 || size == 0)
	{
		arr = malloc(0);
		return (arr);		
	}
	if (size > SIZE_MAX / count)
		return (NULL);	
	arr = malloc (count * size);
	if (arr != NULL)
		ft_bzero(arr, count * size);
	return (arr);
}
