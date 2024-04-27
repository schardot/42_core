#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	arr = malloc(count * size);
	if (arr != NULL)
		ft_bzero(arr, count * size);
	return (arr);
}


// #include <stdio.h>

// int main(void)
// {
// 	int	*arr;

// 	arr = (int	*)ft_calloc(5, sizeof(int));
// 	printf("%d", *arr);
// }