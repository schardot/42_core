#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t  b;
	size_t	l;
	size_t	i;
	char	*foundit;

	b = 0;
	l = 0;
	i = 0;
	while (i < len)
	{
		if (big[b] == little[l])
		{
			foundit = (char *)big + b;
			while (big[b] == little[l] && little[l] != '\0' && i < len)
			{
				b ++;
				l ++;
				i ++;
			}
			if (little[l] != '\0')
			{
				l = 0;
				foundit = NULL;
			}
			else
				return (foundit);
		}
		big ++;
		i ++;
	}
	return (NULL);
}
