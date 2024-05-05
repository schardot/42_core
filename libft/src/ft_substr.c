#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *substr;

    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    if (start >= ft_strlen(s))
    {
        substr = (char *)malloc(1);
        if (substr != NULL)
            substr[0] = '\0';
        return (substr);
    }
    substr = (char *)malloc(len + 1);
    if (substr == NULL)
        return (NULL);
    ft_strlcpy(substr, s + start, len + 1);
    return (substr);
}
// #include <stdio.h>

// int main(void)
// {
//     printf("%s", ft_substr("oi beleza", 3, 4));
// }
