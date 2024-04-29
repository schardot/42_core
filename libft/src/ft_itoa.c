#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

size_t intlen(long n);

char *ft_itoa(int n)
{
    char    *result;
    int i;
    size_t len;
    long    longn;

    longn = n;
    len = intlen(longn);
    result = (char *)malloc(len + 1);
    i = 0;
    if (result == NULL)
        return (NULL);
    if (longn < 0)
    {
        result[0] = '-';
        longn *= -1;
    }
    while (longn > 0)
    {
        result[(len - 1) - i] = (longn % 10) + '0';
        longn /= 10;
        i ++;
    }
    result[len] = '\0';
    return (result);
}

size_t intlen(long  n)
{
    size_t len;

    len = 0;
    if (n < 0) //se for negativo alocar espaco pro sinal
    {
        len ++;
        n *= -1;
    }
    while (n > 9)
    {
        n /= 10;
        len ++;
    }
    len ++;
    return (len);
}

int main(void)
{
    printf("%s\n", ft_itoa(INT_MIN));
}
