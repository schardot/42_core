#include "libft.h"

int ft_printf(const char *s, ...)
{
    char *aux;

    aux = s;

    while (*aux ++ != '%' && *aux ++ != '\0')
        write(1, aux, 1);
    if (*aux == %)
    {
        aux ++;
        
    }
}
