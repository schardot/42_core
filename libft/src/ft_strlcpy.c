#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t    len;
    size_t  clen;

    if (!src || !dst)
        return (0);
    len = ft_strlen(src);
    if (dstsize <= 0)
        return (len);
    if (len < dstsize - 1)
        clen = len;
    else
        clen = dstsize - 1;
    ft_memcpy(dst, src, clen);
    dst[clen] = '\0';
    return (len);
}

// int main(void)
// {
//     char    dst[] = "hi";
//     char    src[] = "oaaaaaa";

//     printf("dst before strlcpy: %s\n", dst);
//     ft_strlcpy(dst, src, sizeof(char) * 3);
//     printf("dst after strlcpy: %s\n", dst);
//     printf("the return value for ft_strlcpy is: %ld\n", ft_strlcpy(dst, src, sizeof(char) * 3));
//     printf("and the return value for THE REAL strlcpy is: %d\n", strlcpy(dst, src, sizeof(char) * 3));
// }