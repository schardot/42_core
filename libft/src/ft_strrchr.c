/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:39:49 by nleite-s          #+#    #+#             */
/*   Updated: 2024/05/06 09:39:50 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[len]);
	while (len > 0)
	{
		if (s[len - 1] == (char)c)
			return ((char *)&s[len - 1]);
		len --;
	}
	return (NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	s[] = "hello";
// 	printf("%s", ft_strrchr(s, 'l'));
// }
