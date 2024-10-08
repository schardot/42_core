/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:38:26 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/25 10:38:27 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;
	int		i;

	i = 0;
	length = 0;
	while (s[i] != '\0')
	{
		length ++;
		i ++;
	}
	return (length);
}
