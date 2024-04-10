#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr = (unsigned char *)b;
    while (len > 0)
    {
        *ptr = (unsigned char)c;
        len --;
        ptr ++;
    }
    return (b);
}