#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_realloc(char *ptr, size_t size)
{
	char	*newptr = (char *)malloc(size);
	if (!newptr)
	{
		free(ptr);
		return NULL;
	}

	if (ptr)
	{
		size_t i = 0;
		while (i < size - 1 && ptr[i] != '\0')
		{
			newptr[i] = ptr[i];
			i++;
		}
		free(ptr);
	}

	return newptr;
}

char	*get_next_line(int fd)
{
	static char	*extra;
	char	*line;
	int	linelen;

	extra = NULL;
	line = NULL;
	linelen = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	if (extra)
	{
		line = process_extra(&extra, &linelen);
		if (line && line[linelen - 1] == '\n')
			return (line);
	}

	return (read_and_construct_line(fd, &extra, line, &linelen));
}

char *read_and_construct_line(int fd, char **extra, char *line, int *linelen)
{
	char buffer[BUFFER_SIZE + 1];
	int bytes_read;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = append_buffer(buffer, line, bytes_read, linelen, extra);
		if (line && line[*linelen - 1] == '\n')
			return line;
	}

	if (bytes_read < 0 || (bytes_read == 0 && *linelen == 0))
	{
		free(line);
		return NULL;
	}

	if (line)
		line[*linelen] = '\0';
	return line;
}

char *process_extra(char **extra, int *linelen)
{
	char *line = NULL;
	int i = 0;

	while ((*extra)[i] != '\0')
	{
		line = ft_realloc(line, (*linelen) + 2); // +2 for new char and null-terminator
		line[*linelen] = (*extra)[i];
		if ((*extra)[i] == '\n')
		{
			line[++(*linelen)] = '\0';
			char *new_extra = strdup(&(*extra)[i + 1]);
			free(*extra);
			*extra = new_extra;
			return line;
		}
		(*linelen)++;
		i++;
	}
	free(*extra);
	*extra = NULL;
	return line;
}
char *append_buffer(char *buffer, char *line, int bytes_read, int *linelen, char **extra)
{
	int i = 0;

	while (i < bytes_read)
	{
		line = ft_realloc(line, (*linelen) + 2); // +2 for new char and null-terminator
		line[*linelen] = buffer[i];
		if (buffer[i] == '\n')
		{
			if (i + 1 < bytes_read)
			{
				*extra = strdup(&buffer[i + 1]);
			}
			line[++(*linelen)] = '\0';
			return line;
		}
		(*linelen)++;
		i++;
	}
	return line;
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