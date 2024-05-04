#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    char    *num;

    num = ft_itoa(n);
    ft_putstr_fd(num, fd);
}