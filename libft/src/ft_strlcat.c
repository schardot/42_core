#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
		size_t dstlen;
		size_t srclen;
		size_t i;

		srclen = ft_strlen(src);
		dstlen = ft_strlen(dst);
		i = dstlen;
		dst += dstlen;
		while (*src != '\0' && i < size)
		{
			*dst ++ = *src ++;
			i ++;
		}
		*dst = '\0';
		dst -= (dstlen + srclen);
		return (dstlen + srclen);
}

// #include <stdio.h>

// int	main(void)
// {
// 		char	dst[8] = "oi";
// 		printf("the return value is %ld\n", ft_strlcat(dst, "hello", 8));
// 		printf("this is dst: %s", dst);
// }
