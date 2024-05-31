#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
void *ft_realloc(void *ptr, size_t size);
void *ft_memcpy(void *dest, const void *src, size_t n);

#endif