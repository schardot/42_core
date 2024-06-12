#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	static char *extra;
	char *buffer;
	char *line;
	int b;
	int i;
	int linelen;
	int x;
	int flag;

	flag = 0;
	if (fd < 0)
		return (NULL);
	x = 0;
	line = NULL;
	linelen = 0;
	if (extra)
	{
		line = ft_realloc(line, 1 + linelen);
		while (*extra != '\0')
		{
			line[linelen] = *extra;
			if (line[linelen] == '\n' || line[linelen] == EOF)
			{
				extra++;
				return (line);
			}
			linelen++;
			extra++;
		}
		free(extra);
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
	{
		if (line)
			free(line);
		return (NULL);
	}
	while (1)
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b <= 0)
		{
			free(buffer);
			if (flag > 0)
				return (line);
			free (line);
			return (NULL);
		}
		i = 0;
		while (i < b)
		{
			line = ft_realloc(line, 1 + linelen);
			line[linelen] = buffer[i];
			flag ++;
			if (line[linelen] == '\n')
			{
				while (b > i + 1)
				{
					extra = ft_realloc(extra, x);
					extra[x] = buffer[i + 1];
					x ++;
					i ++;
				}
				extra = ft_realloc(extra, x);
				extra[x] = '\0';
				free(buffer);
				return (line);
			}
			i++;
			linelen ++;
		}
		if (i == b && b < BUFFER_SIZE)
		{
			free (buffer);
			return (line);
		}
	}
}

// int main(void)
// {
//     char *r;
//     int fd;
// 	r = "";
// 	fd = open("41_no_nl.txt", O_RDWR);
// 	while (r)
// 	{
// 		r = get_next_line(fd);
// 		printf("%s\n", r);
// 	}
//     close(fd);
// }

void *ft_realloc(void *ptr, size_t size)
{
	if (!ptr)
		return (malloc(size));
	void *newptr;
	newptr = malloc(size);
	if (!newptr)
	{
		free (ptr);
		return (NULL);
	}
	newptr = ft_memcpy(newptr, ptr, size);
	free (ptr);
	return (newptr);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char *d;
	const char *s;
	int i;

	d = dest;
	s = src;
	if (d == NULL && s == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (n > 0)
	{
		d[i] = s[i];
		n--;
		i++;
	}
	return (dest);
}