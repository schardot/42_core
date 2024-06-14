#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h> //pra usar strcmp, dps apagar

char	*get_next_line(int fd)
{
	static char	*extra;
	char	*buffer;
	char	*line;
	int	b;
	int	i;
	int	linelen;
	int	x;
	int	flag;

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
				linelen++;
				line[linelen] = '\0';
				return (line);
			}
			linelen++;
			extra++;
		}
		// free(extra);
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
			{
				// linelen++;
				line[linelen] = '\0';
				return (line);
			}
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
				free(buffer);
				linelen++;
				line[linelen] = '\0';
				return (line);
			}
			i++;
			linelen ++;
		}
		if (i == b && b < BUFFER_SIZE)
		{
			free (buffer);
			//linelen++;
			line[linelen] = '\0';
			return (line);
		}
	}
}

// int	main(void)
// {
//     char	*r;
//     int	fd;
// 	int i;
// 	int round = 0;

// 	r = "";
// 	fd = open("41_no_nl.txt", O_RDWR);
// 	while (r)
// 	{
// 		round ++;
// 		r = get_next_line(fd);
// 		printf("Round %d, gnl result: %s\n", round, r);
// 		i = strcmp(r, "01234567890123456789012345678901234567890");
// 		printf("Round %d, strcmp: %d\n", round, i);
// 	}
//     close(fd);
// }

char	*ft_realloc(char *ptr, size_t size)
{
	char	*newptr;
	size_t	i;

	if (!ptr)
		return ((char *)malloc(size));
	newptr = (char *)malloc(size + 1);
	if (!newptr)
	{
		free (ptr);
		return (NULL);
	}
	i = 0;
	while (i < size - 1 && ptr[i] != '\0')
	{
		newptr[i] = ptr[i];
		i++;
	}
	//newptr[i] = '\0';
	free (ptr);
	return (newptr);
}

