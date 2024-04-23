#include "libft.h"

int ft_tolower(int c)
{
	if (ft_isalpha(c) && (c >= 'A' && c <= 'Z'))
	{
		return (c += 32);
	}
	return (c);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char a = 'a';// - should leave it alone
// 	//char a = 'A'; //- should lower
// 	//char a = '0'; // - should leave it alone
// 	a = ft_tolower(a);
// 	printf("%c", a);
// }