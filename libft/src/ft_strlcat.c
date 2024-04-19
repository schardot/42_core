#include "libft.h"

#include <stddef.h>

size_t	ft_strlen(const char *s);

void	ft_bzero(void *s, size_t n);

void	*ft_memset(void *b, int c, size_t len);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
		size_t dstlen;
		size_t i;

		ft_bzero(dst, size);
		dstlen = ft_strlen(dst);
		i = dstlen;
		src += dstlen;
		while (*src != '\0' && dst[i] != '\0' && i < size)
		{
				*dst = *src;
				src ++;
				i ++;
		}
		*dst = '\0';
		return (dstlen + ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (*s != '\0')
	{
		length ++;
		s ++;
	}
	return (length);
}

#include <stdio.h>

int	main(void)
{
		char dst[3];
		printf("the return value is %ld", ft_strlcat(dst, "hello", 3));
		printf("this is dst: %s", dst);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
