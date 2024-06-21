#include "get_next_line.h"
#include <stdio.h> // apagar

char	*get_next_line(int fd)
{
	static char	*extra;
	char		*line;
	int			linelen;

	linelen = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (extra)
		line = extrainline(&extra, &linelen);
	if (line && line[linelen - 1] == '\n') // nao sei se ta certo esse --
		return (line);
	line = getmyline(line, &extra, fd, &linelen);
	return (line); // tenho que passar o endereco de line?
}

char	*getmyline(char *line, char **extra, int fd, int *linelen)
{
	char	buffer[BUFFER_SIZE + 1];
	int		b;

	while ((b = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[b] = '\0';
		line = append_buffer(buffer, line, linelen, extra);
		if (line && line[*linelen - 1] == '\n') // nao sei se ta certo esse --
			return (line);
	}
	if (b == 0 && *linelen > 0)
		return (line);
	free (line);
	return (NULL);
}

char	*append_buffer(char	*buffer, char *line, int *linelen, char **extra)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		line = ft_realloc(line, (*linelen) + 2);
		line[*linelen] = buffer[i];
		(*linelen)++;
		if (line[*linelen - 1] == '\n')
		{
			if (buffer[i + 1] != '\0')
				writeextra(extra, buffer + i + 1);
			line[*linelen] = '\0';
			return (line);
		}
		i ++;
	}
	line[*linelen] = '\0'; //nao preciso aumentar a len
	return (line);
}

void	writeextra(char **extra, char *buffer) //do i address buffer right?
{
	int	len;
	int	i;

	len = 0;
	while (buffer[len] != '\0')
		len ++;
	*extra = (char *)malloc(len + 1); //so precisa somar um pq ele pega o \0 de buffer.
	if (!extra)
		return;
	i = 0;
	while (i <= len)
	{
		(*extra)[i] = buffer[i];
		i ++;
	}
	//(*extra)[i] = '\0'; nao precisa pq ele copia o \0 de buffer!
}

char	*extrainline(char **xtra, int *ll)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (**xtra != '\0')
	{
		line = ft_realloc(line, i + 2);
		line[i] = (**xtra);
		i ++;
		//(*xtra)++;
		if (line[i - 1] == '\n')
		{
			if ((*xtra)[1] == '\0')
			{
				*ll = i;
				line[i] = '\0';
				*xtra = NULL;
				//free(xtra);
				return (line);
			}
			else if ((*xtra)[1] != '\0')
			{
				*ll = i;
				(*xtra)++;
				line[i] = '\0';
				return (line);
			}
		}
		(*xtra)++;
	}

	*xtra = NULL;
	*ll = i;
	if (line)
		line[i] = '\0';
	return (line);
}
char *ft_realloc(char *ptr, size_t size)
{
	char	*newptr;
	size_t	i;

		newptr = (char *)malloc(size);
	if (!newptr)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr)
	{
		i = 0;
		while (i < size - 1 && ptr[i] != '\0')
		{
			newptr[i] = ptr[i];
			i++;
		}
		free(ptr);
	}
	return (newptr);
}

// int	main(void)
// {
// 	char	*line;
// 	int	fd;

// 	//line = NULL;
// 	fd = open("alternate_line_nl_no_nl.txt", O_RDONLY);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// }