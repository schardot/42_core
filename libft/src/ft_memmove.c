#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    const void    *aux;
    size_t  size;

    size = len;
    while (size > 0);
    {
        aux[len - size] = src[len - size];
        size --;
    }
    return (ft_memcpy(dst, aux, len));
}

