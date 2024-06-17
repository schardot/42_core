#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


char *ft_realloc(char *ptr, size_t size)
{
	char *newptr;
	size_t i = 0;

	newptr = (char *)malloc(size);
	if (!newptr)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr)
	{
		while (i < size - 1 && ptr[i] != '\0')
		{
			newptr[i] = ptr[i];
			i++;
		}
		free(ptr);
	}

	return (newptr);
}

char *put_extra(char *line, char **extra, int *linelen)
{
	int i = 0;

	while ((*extra)[i] != '\0')
	{
		line = ft_realloc(line, (*linelen) + 2); // +2 for new char and null-terminator
		line[(*linelen)++] = (*extra)[i];
		if ((*extra)[i] == '\n')
		{
			line[*linelen] = '\0';
			char *new_extra = strdup(&(*extra)[i + 1]);
			free(*extra);
			*extra = new_extra;
			return (line);
		}
		i++;
	}
	free(*extra);
	*extra = NULL;
	return (line);
}

char *put_line(char *buffer, char *line, int bytes_read, int *linelen, char **extra)
{
	int i = 0;

	while (i < bytes_read)
	{
		line = ft_realloc(line, (*linelen) + 2); // +2 for new char and null-terminator
		line[*linelen] = buffer[i];
		if (buffer[i] == '\n')
		{
			line[++(*linelen)] = '\0';
			if (i + 1 < bytes_read)
			{
				*extra = strdup(&buffer[i + 1]);
			}
			return (line);
		}
		(*linelen)++;
		i++;
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char *extra = NULL;
	char *buffer;
	char *line = NULL;
	int bytes_read;
	int linelen = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}

	if (extra)
	{
		line = put_extra(line, &extra, &linelen);
		if (line && line[linelen - 1] == '\n')
		{
			return (line);
		}
	}

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		if (line)
			free(line);
		return (NULL);
	}

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = put_line(buffer, line, bytes_read, &linelen, &extra);
		if (line && line[linelen - 1] == '\n')
		{
			free(buffer);
			return (line);
		}
	}

	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && linelen == 0))
	{
		free(line);
		return (NULL);
	}

	if (line)
	{
		line[linelen] = '\0';
	}
	return (line);
}

// int main(void)
// {
// 	char *r;
// 	int fd;
// 	int i;
// 	int round = 0;
// 	r = "";
// 	fd = open("41_with_nl.txt", O_RDWR);
// 	while (r)
// 	{
// 		i = 42;
// 		round ++;
// 		r = get_next_line(fd);
// 		printf("Round %d, gnl result: %s\n", round, r);
// 		if (round == 1)
// 			i = strcmp(r, "0123456789012345678901234567890123456789\n");
// 		else if (round == 2)
// 			i = strcmp(r, "0");
// 		else if (round == 3)
// 		{
// 			if (r == NULL)
// 			i = 0;
// 		}
// 		printf("Round %d, strcmp: %d\n", round, i);
// 	}
// 	close(fd);
// }