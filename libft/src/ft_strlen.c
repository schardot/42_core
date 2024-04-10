#include "libft.h"

size_t  ft_strlen(const char *s)
{
    size_t length;
    while (*s != '\0')
    {
        length ++;
        s ++;
    }
    return (length);
}
