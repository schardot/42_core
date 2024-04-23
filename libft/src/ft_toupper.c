#include "libft.h"

int ft_toupper(int c)
{
	if (ft_isalpha(c) && (c >= 'a' && c <= 'z'))
		return (c -= 32);   
	return (c);
}
#include <stdio.h>
int	main(void)
{
	//char a = 'a'; - should upper
	//char a = 'A'; - should leave it alone
	char a = '0'; // - should leave it alone
	a = ft_toupper(a);
	printf("%c", a);
}