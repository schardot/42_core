#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	aux[len];
	char	*d;

	d = dst;
	ft_bzero(aux,  sizeof(char) * len);
	ft_memcpy(aux, src, sizeof(char) * len);
	while (len > 0)
	{
		*d = *aux;
		len --;
	}
	return (&d[0]);
}

//  #include <stdio.h>

// int	main(void)
// {
// 	char	dest[] = "Hello";
// 	char	src[] = "abc";

// 	printf("Before memmove, dest: %s\n", dest);
// 	printf("After memmove, dest: %s\n", (char *)ft_memmove(dest, src, ft_strlen(dest)));
// }