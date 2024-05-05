#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
		size_t dstlen;
		size_t srclen;
		size_t i;

		srclen = ft_strlen(src); //AAAAAAA... 10
		dstlen = ft_strlen(dst); //B000000... 30
		//printf("%zu %zu\n", dstlen, srclen);
		int j = 0;
		i = dstlen;
		if (size <= dstlen)
			return (srclen + size);
		while (i < size - 1)
		{
			dst[i] = src[j];
			i ++;
			j++;
		}
		dst[i + 1] = '\0';
		return (dstlen + srclen);
}

// #include <stdio.h>

// int	main(void)
// {
// 		char	dst[8] = "oi";
// 		printf("the return value is %ld\n", ft_strlcat(dst, "hello", 8));
// 		printf("this is dst: %s", dst);
// }
