#include "libft.h"

size_t  ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (*s != '\0')
	{
		length ++;
		s ++;
	}
	return (length);
}
// #include <stdio.h>

// int main(void)
// {
// 	char    *s = "palavra";
// 	printf("%ld", ft_strlen(s));
// }