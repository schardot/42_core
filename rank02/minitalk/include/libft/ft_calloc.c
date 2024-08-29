/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:26:23 by nataliaschard     #+#    #+#             */
/*   Updated: 2024/08/12 19:26:25 by nataliaschard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
