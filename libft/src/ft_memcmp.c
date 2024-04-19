#include "libft.h"

int	memcmp(const void *s1, const void *s2, size_t n)
{
	size_t  i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		i ++;
	}
}