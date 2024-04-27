#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *substr;

    substr = (char *)malloc(len + 1);
    if (substr != NULL)
    {
        ft_strlcpy(substr, s + start, len + 1);
        return (substr);
    }
    else
        return (NULL);
}
// #include <stdio.h>

// int main(void)
// {
//     printf("%s", ft_substr("oi beleza", 3, 4));
// }
