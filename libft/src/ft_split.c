#include "libft.h"

char **ft_split(char const *s, char c)
{
    int i;
    char    **test = (char **)malloc(2 * (sizeof(char *)));

    i = 0;
    while (s[i] != c)
        i ++;
    if ((test[0] = ft_substr(s, 0, i)) == NULL)
        return (NULL);
    if ((test[1] = ft_substr(s, i + 1, ft_strlen(s) - i - 1)) == NULL)
        return (NULL);
    return (test);
}
// #include <stdio.h>
// int main(void)
// {
//     char **bbig = ft_split(",blz", ',');
//     printf("s1: %s\n", bbig[0]);
//     printf("s2: %s\n", bbig[1]);
// }