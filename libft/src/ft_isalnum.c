#include "libft.h"

int ft_isalnum(int c)
{
    return (ft_isalpha(c) || ft_isdigit(c));
}

// #include <stdio.h>

// int main(void)
// {
//     int c;

//     c = 48;
//     if (ft_isalnum(c))
//         printf("yes its alphanumeric");
//     else
//         printf("no it is not alphanum");
// }