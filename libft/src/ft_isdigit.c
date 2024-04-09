#include "libft.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
// #include <stdio.h>
// int main()
// {
//     char ch = '8';

//     if (ft_isdigit(ch))
//     {
//         printf("%c is a digit.\n", ch);
//     }
//     else
//     {
//         printf("%c is not a digit.\n", ch);
//     }

//     return 0;
// }