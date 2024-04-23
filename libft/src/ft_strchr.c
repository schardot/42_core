#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s ++;
	}
	if (c == '\0')
		return ((char *)s);
	else
		return (NULL);
}
#include <stdio.h>

int	main(void)
{
	char	s[] = "hello";
	printf("%s", ft_strchr(s, 'l'));
}