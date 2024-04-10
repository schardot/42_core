#include "libft.h"

int ft_isascii(int c)
{
    return (0 <= c && c <= 127);
}
// #include <stdio.h>
// int main()
// {
//     char ch = 's';

//     if (ft_isascii(ch))
//     {
//         printf("%c is ascii.\n", ch);
//     }
//     else
//     {
//         printf("%c is not ascii.\n", ch);
//     }

//     return 0;
// }