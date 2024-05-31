#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char    *get_next_line(int fd)
{
    char    byte;
    char    *line;
    int len;
    int b;

    len = 1;
    b = read(fd, &byte, 1);
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	*line = byte;
    while (byte != '\n')
    {
        line = (char *)ft_realloc(line, len + 1 * sizeof(char));
        read(fd, &byte, 1);
		line[len] = byte;
        len ++;
    }
    return (line);
}

int main(void)
{
    char *r;
    int fd;

    fd = open("test.txt", O_RDONLY);
    r = get_next_line(fd);
    printf("%s", r);
    close(fd);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*newptr;
	newptr = malloc(size);
	if (!newptr)
		return (NULL);
	newptr = ft_memcpy(newptr, ptr, size);
	return (newptr);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char *d;
	const char *s;

	d = dest;
	s = src;
	if (d == NULL && s == NULL)
	{
		return (NULL);
	}
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}

