#include "libft.h"

int toupper(int c)
{
	if (isalpha(c) && (c >= 'a' && c <= 'z'))
	{
		c -= 32;
		return (0);   
	}
	return (1);
}
