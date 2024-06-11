#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10000000
#endif

char *get_next_line(int fd);
size_t ft_strlcat(char *dst, const char *src, size_t size);
char *check_buffer(char *buffer);
size_t ft_strlen(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);
void *ft_memset(void *b, int c, size_t len);
char *ft_strchr(const char *s, int c);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
void *ft_memcpy(void *dest, const void *src, size_t n);
char *ft_strdup(const char *str);

#endif