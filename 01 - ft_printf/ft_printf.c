#include "ft_printf.h"
#include "libft/libft.h"

int ft_format(char *aux, va_list args);

int ft_printf(const char *s, ...)
{
    va_list args;
    char    *aux;
    int i;

    aux = s;
    if (!s)
        return (-1);
    else if (!ft_strchr(aux, '%'))
        ft_putstr_fd(s, 1);
    else //ou seja, tem porcento na frase
    {
        va_start(args, s);
        i = 0;
        while (aux[i] != '\0')
        {
            write(1, &aux[i], 1);
            if (aux[i] == '%' && ft_strchr("cspdiuxX%", aux[i+1]))
                ft_format(aux, args);
        }
    }
    return (0);
}


int ft_format(char *aux, va_list args)
{
    aux ++;
    if (*aux == 'c')
        ft_putchar_fd(va_arg(args, char), 1);
    else if (*aux == 's')
        ft_putstr_fd(va_arg(args, char *), 1);
    // else if (*aux == 'p')
    //     ft_FAZERRRRR;
    else if (*aux == 'd' || *aux == 'i')
        ft_putnbr_fd(va_arg(args, int), 1);
    // else if (*aux == 'u')
    //     ft_FAZERRRRR;
    else if (*aux == 'x')
        ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
    else if (*aux == 'X')
        ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
    else if (*aux == '%')
        ft_putchar_fd('%', 1);
    else
        return (0);
    return (1);
}

