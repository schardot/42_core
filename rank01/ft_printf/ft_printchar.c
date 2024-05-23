#include "printf.h"
#include "libft/libft.h"

int ft_printchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_printstr(char *s)
{
    int i;
    
    i = 0;
	while (s[i] != '\0')
	{
		ft_printchar(s[i]);
		i ++;
	}
}

