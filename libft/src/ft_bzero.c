#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[] = "palavra";
// 	size_t  len = ft_strlen(s);
//     printf("Before bzero: %s\n", s);
//     ft_bzero(s, len);
//     printf("After bzero: ");
//     for (size_t i = 0; i < len; i++)
//     {
//         printf("%d", (unsigned char)s[i]);
//     }
//     printf("\n");
// }