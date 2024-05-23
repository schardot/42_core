#include "libft.h"

void    ft_putaddr(unsigned long long ptr)
{
    int i;
    i = 0;
    if (ptr > 16)
    {
        ft_putaddr(ptr/16)
    }
}