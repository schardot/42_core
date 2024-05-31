#include "get_next_line.h"

void *ft_realloc(void *ptr, size_t size)
{
    void *newptr;
    newptr = malloc(size);
    if (!newptr)
        return (NULL);
    newptr = ft_memcpy(newptr, ptr, size);
    return (newptr);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char *d;
    const char *s;

    d = dest;
    s = src;
    if (d == NULL && s == NULL)
    {
        return (NULL);
    }
    while (n > 0)
    {
        *d++ = *s++;
        n--;
    }
    return (dest);
}