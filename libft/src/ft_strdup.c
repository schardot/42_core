#include "libft.h"

char    *ft_strdup(const char *str)
{
    int len;
    char    *cpy;

    len = ft_strlen(str);
    cpy = (char *)malloc(len);
    if (cpy != NULL)
    {
        ft_strlcpy(cpy, str, len + 1);
        return (cpy);
    }
    else
        return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
//     char arr[] = "oi beleza";

//     printf("%s", ft_strdup(arr));
// }