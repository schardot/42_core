#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *result;
    unsigned int i;

    i = 0;
    result = (char *)malloc(ft_strlen(s + 1));
    if (result == NULL)
        return (NULL);
    while (s[i] != '\0')
    {
        result[i] = f(i, s[i]);
        i ++;
    }
    result[i] = '\0';
    return (result);
}
