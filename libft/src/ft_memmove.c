#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	aux[len];
	char	*d;

	d = dst;
	ft_bzero(aux,  sizeof(char) * len);
	ft_memcpy(aux, src, sizeof(char) * len);
	size_t i = 0;
	while (i < len)
	{
		d[i] = aux[i];
		i++;
	}
	return (&d[0]);
}

//  #include <stdio.h>

// int	main(void)
// {
// 	char s[] = {65, 66, 67, 68, 69, 0, 45};
// 	char s0[] = {0, 0, 0, 0, 0, 0, 0};

// 	printf("Before memmove, dest: %s\n", s0);
// 	printf("After memmove, dest: %s\n", (char *)ft_memmove(s0, s, 7));
// }