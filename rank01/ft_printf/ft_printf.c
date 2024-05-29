#include "ft_printf.h"

int main(void)
{
    int my;
    int real;
    // printf("Test for 'c'\n");
    // printf("Test 5:\n");
    // my = ft_printf("ft_printf: %c %c %c \n", '0', 0, '1');
    // real = printf("___printf: %c %c %c \n", '0', 0, '1');
    // printf("My function returns %d, and the real function returns %d", my, real);

    // printf("Test 7:\n");
    // my = ft_printf("ft_printf: %c %c %c \n", '1', '2', '3');
    // real = printf("___printf: %c %c %c \n", '1', '2', '3');
    // printf("My function returns %d, and the real function returns %d", my, real);

    // printf("Test 8:\n");
    // my = ft_printf("ft_printf: %c %c %c \n", '2', '1', 0);
    // real = printf("___printf: %c %c %c \n", '2', '1', 0);
    // printf("My function returns %d, and the real function returns %d", my, real);

    //problema do %c encontrado, va_args nunca atualiza a lista e sempre imprime o primeiro char

    printf("Test for 's'\n");
    printf("Test 2:\n");
    my = ft_printf("ft_printf: %s", "");
    real = printf("___printf: %s", "");
    printf("My function returns %d, and the real function returns %d\n", my, real);

    // 28 : TEST(2, print(" %s", ""));
    // 29 : TEST(3, print("%s ", ""));
    // 30 : TEST(4, print(" %s ", ""));
    // 31 : TEST(5, print(" %s ", "-"));
    // 32 : TEST(6, print(" %s %s ", "", "-"));
    // 33 : TEST(7, print(" %s %s ", " - ", ""));
    // 34 : TEST(8, print(" %s %s %s %s %s", " - ", "", "4", "", s2));
    // 35 : TEST(9, print(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
    // 36 : TEST(10, print(" NULL %s NULL ", NULL));
}

int ft_printf(const char *s, ...)
{
    va_list args;
    char *aux;
    int len;
    int i;

    i = 0;
    len = 0;
    va_start(args, s);
    aux = (char *)s;
    if (!s)
        return (-1);
    while (aux[i] != '\0')
    {
        if (aux[i] == '%' && ft_strchr("cspdiuxX%", aux[i + 1]))
        {
            i++;
            len += ft_format(aux[i], &args);
        }
        else
        {
            ft_printchar(aux[i]);
            len++;
        }
        i++;
    }
    va_end(args);
    return (len);
}

int ft_format(int c, va_list *args)
{
    int len;
    va_list aux;

    va_copy(aux, *args);
    len = 0;
    if (c == 'c')
        len += ft_printchar(va_arg(aux, int));
    else if (c == 's')
        len += ft_printstr(va_arg(aux, char *));
    else if (c == 'p')
        len += ft_printaddr(va_arg(aux, void *), "0123456789abcdef");
    else if (c == 'd' || c == 'i')
        len += ft_printnbr(va_arg(aux, int));
    else if (c == 'u')
        len += ft_printnbr_unsigned(va_arg(aux, unsigned int));
    else if (c == 'x')
        len = ft_putnbr_base(va_arg(aux, unsigned int), "0123456789abcdef");
    else if (c == 'X')
        len = ft_putnbr_base(va_arg(aux, unsigned int), "0123456789ABCDEF");
    else if (c == '%')
        len = ft_printchar('%');
    va_end(aux);
    return (len);
}
int ft_printchar(int c)
{
    char ch = (char)c;
    write(1, &ch, 1);
    return (1);
}

int ft_printstr(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        ft_printchar(s[i]);
        i ++;
    }
    return (i);
}

int ft_printaddr(void *ptr, char *base)
{
    unsigned long addr;
    unsigned long baselen;
    int len;

    len = 0;
    baselen = (unsigned long)ft_strlen(base);
    addr = (long long)ptr;
    len += ft_printstr("0x");
    if (addr == 0)
        len += ft_printchar(base[0]);
    else
    {
        if (addr >= baselen)
            len += ft_printaddr((void *)(addr / baselen), base);
        len += ft_printchar(base[addr % baselen]);
    }
    return (len);
}

int ft_printnbr(int nb)
{
    int len = 0;

    if (nb == INT_MIN)
    {
        len += ft_printstr("-2147483648");
        return len;
    }
    if (nb < 0)
    {
        nb = -nb;
        len += ft_printchar('-');
    }
    if (nb < 10)
        len += ft_printchar('0' + nb);
    else
    {
        len += ft_printnbr(nb / 10);
        len += ft_printnbr(nb % 10);
    }
    return (len);
}

int ft_printnbr_unsigned(unsigned int nb)
{
    int len = 0;
    if (nb < 10)
    {
        len += ft_printchar('0' + nb);
    }
    else
    {
        len += ft_printnbr_unsigned(nb / 10);
        len += ft_printnbr_unsigned(nb % 10);
    }
    return len;
}

int ft_putnbr_base(unsigned int nbr, const char *base)
{
    int len = 0;
    unsigned int base_len = ft_strlen(base);

    if (nbr < base_len)
    {
        len += ft_printchar(base[nbr]);
    }
    else
    {
        len += ft_putnbr_base(nbr / base_len, base);
        len += ft_putnbr_base(nbr % base_len, base);
    }
    return len;
}

char *ft_strchr(const char *s, int c)
{
    size_t i;
    char temp_c;

    i = 0;
    temp_c = (char)c;
    while (s[i] != '\0')
    {
        if (s[i] == temp_c)
            return ((char *)&s[i]);
        i++;
    }
    if (s[i] == temp_c)
        return ((char *)&s[i]);
    else
        return (NULL);
}

size_t ft_strlen(const char *s)
{
    size_t length;
    int i;

    i = 0;
    length = 0;
    while (s[i] != '\0')
    {
        length++;
        i++;
    }
    return (length);
}