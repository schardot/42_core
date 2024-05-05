#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t  i;
	unsigned char	*one;
	unsigned char	*two;

	one = (unsigned char *) s1;
	two = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*one != *two)
		{
			return (*one - *two);
		}
		one ++;
		two ++;
		i ++;
	}
	return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char s1[] = "abc";
// 	char s2[] = "abb";
// 	printf("%d", ft_memcmp(s1, s2, 3));
// }