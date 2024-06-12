#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *get_next_line(int fd);
void *ft_realloc(void *ptr, size_t size);
void *ft_memcpy(void *dest, const void *src, size_t n);
char *ft_extra(char *extra, char **line, int *linelen);

#endif