#include "printf.h"
#include "libft/libft.h"

int ft_format(const char **aux_ptr, va_list args);

int ft_printf(const char *s, ...)
{
	va_list	args;
	const char	*aux;
	int	count = 0;

	aux = s;
	if (!s)
		return (-1);

	va_start(args, s);
	while (*aux != '\0')
	{
		if (*aux == '%' && ft_strchr("cspdiuxX%", aux[1]))
		{
			count += ft_format(&aux, args);
		}
		else
		{
			write(1, aux, 1);
			aux++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

int ft_format(const char **aux_ptr, va_list args)
{
	const char *aux = *aux_ptr;
	aux++; // Move past '%'
	int	len;

	len = 0;
	if (*aux == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (*aux == 's')
		len = ft_printstr(va_arg(args, char *);
	else if (*aux == 'p')
		len = ft_putaddr((long long)va_arg(args, void *), "0123456789abcdef");
	else if (*aux == 'd' || *aux == 'i')
		len = ft_printnbr(va_arg(args, int));
	//else if (*aux == 'u')
		//len = ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (*aux == 'x')
		len = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*aux == 'X')
		len = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*aux == '%')
		len = ft_printchar('%');

	*aux_ptr = aux + 1; // Update the pointer to move past the format specifier
	return (len);
}


