#include "libft.h"

int ft_isprint(int c)
{
    return (32 <= c && c < 127);
}
// #include <stdio.h>

// int main(void)
// {
//     int c;

//     c = 127;
//     if (ft_isprint(c))
//         printf("yes its printabke");
//     else
//         printf("no it is not printable");
// }
