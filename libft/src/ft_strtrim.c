#include "libft.h"
//#include <stdio.h>

char    *ft_strtrim(char const *s1, char const *set)
{
    int start;
    int end;
    int i;
    const char    *s2;

    i = ft_strlen(s1) - 1;
    s2 = s1;
    start = 0;
    end = 0;
    while (ft_strchr(set, *s2) != NULL)
    {
        s2 ++;
        start ++;
    }
    while (ft_strchr(set, s1[i]) != NULL)
    {
        // printf(("%c", s2));
        i --;
        end++;
    }
    //printf("start: %d, end: %d, strlen: %ld\n", start, end, ft_strlen(s1));
    return (ft_substr(s1, start, (ft_strlen(s1) - start - end)));
}
//#include <stdio.h>

int main(void)
{
    printf("%s\n", ft_strtrim(",    hello, sdsds,    ", "s ,"));
    // printf("%s\n", ft_strtrim(",    hello, sdsds,     ", "s ,"));
}
