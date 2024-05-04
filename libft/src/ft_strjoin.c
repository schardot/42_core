#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *big;
    int len1;
    int len2;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    big = (char *)ft_calloc(len1 + len2, 1);
    if (big != NULL)
    {
        ft_strlcat(big, s1, len1 + len2);
        ft_strlcat(big, s2, len1 + len2);
        return (big);
    }
    else
        return (NULL);
}
// #include <stdio.h>
// int main(void)
// {
//     printf("%s\n", ft_strjoin("oi ", "blz"));
// }
