#include "libft.h"

int strncmp(const char *str1, const char *str2, size_t n)
{
    unsigned int i;

    i = 0;
    while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (0);
}