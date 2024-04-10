#include "libft.h"

size_t  strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
    int i;

    i = 0
    while (src[i] != '\0' && i > dstsize)
    {
        dst[i] = src[i];
        i ++;
    }
    dst[i] = '\0';
    return (strlen(src));
}