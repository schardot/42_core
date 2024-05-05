#include "libft.h"

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (*big && len >= little_len)
	{
		i = 0;
		while (big[i] == little[i])
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			i ++;
		}
		big ++;
		len --;
	}
	return (NULL);
}

	// char	*ft_strnstr(const char *big, const char *little, size_t len)
	// {
	// 	size_t	l;
	// 	size_t	i;
	// 	// char	*foundit;

	// 	l = 0;
	// 	i = 0;
	// 	while (big[i] != '\0')
	// 	{
	// 		if (big[i] == little[l])
	// 		{
	// 			foundit = &big[i];
	// 			while (big[i] == little[l] && little[l] != '\0')
	// 			{
	// 				l ++;
	// 				i ++;
	// 			}
	// 			if (little[l] != '\0')
	// 			{
	// 				l = 0;
	// 				foundit = NULL;
	// 			}
	// 			else
	// 				return (foundit);
	// 		}
	// 		i ++;
	// 	}
	// 	return (NULL);
	// }
