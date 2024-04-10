#include "libft.h"

void    *memcpy(void *dest, const void *src, size_t n)
{
    while (n > 0)
    {
        dest = src;
        n --;
        dest ++;
        src ++;
    }
    return (dest);
}