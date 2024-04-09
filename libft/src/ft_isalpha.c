#include "libft.h"

int ft_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
// #include <stdio.h>
// int main()
// {
//     char ch = 'a';

//     if (ft_isalpha(ch))
//     {
//         printf("%c is an alphabetic character.\n", ch);
//     }
//     else
//     {
//         printf("%c is not an alphabetic character.\n", ch);
//     }

//     return 0;
// }