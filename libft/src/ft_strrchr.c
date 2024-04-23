#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[len - 1]);
	while (len > 0)
	{
		if (s[len - 1] == c)
			return ((char *)&s[len - 1]);
		len --;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[] = "hello";
// 	printf("%s", ft_strrchr(s, 'l'));
// }