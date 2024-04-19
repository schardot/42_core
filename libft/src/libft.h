#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
void    *ft_memset(void *b, int c, size_t len);
void    *memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
void    ft_bzero(void *s, size_t n);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
size_t  strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
size_t  ft_strlen(const char *s);
char    *strnstr(const char *big, const char *little, size_t len);
char    *ft_strrchr(const char *s, int c);
int tolower(int c);
int toupper(int c);

#endif