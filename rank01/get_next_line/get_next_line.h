#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char *ft_realloc(char *ptr, size_t size);
char *process_extra(char **extra, int *linelen);
char *append_buffer(char *buffer, char *line, int bytes_read, int *linelen, char **extra);
char *get_next_line(int fd);
char *read_and_construct_line(int fd, char **extra, char *line, int *linelen);

#endif