#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
	void *arr;

	if (count == 0 && size != 0)
	{
		arr = malloc(size);
		if (arr != NULL)
			ft_bzero(arr, size);
	}
	else
	{
		if (count == 0 || size == 0 || (SIZE_MAX / count) < size)
			return (NULL);
		arr = malloc(count * size);
		if (arr != NULL)
			ft_bzero(arr, count * size);
	}
	return (arr);
}

// #include <stdio.h>

// int main(void)
// {
// 	int	*arr;

// 	arr = (int	*)ft_calloc(5, sizeof(int));
// 	printf("%d", *arr);
// }