#include "libft.h"

int tolower(int c)
{
	if (isalpha(c) && (c >= 'A' && c <= 'Z'))
	{
		c += 32;
		return (0);
	}
	return (1);
}
