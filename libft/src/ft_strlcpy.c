#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    if (dstsize == 0)
        return (ft_strlen(src));
    ft_memcpy(dst, src, dstsize - 1);
    dst[dstsize - 1] = '\0';
    return (ft_strlen(src));
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