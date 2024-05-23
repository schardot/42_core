#include "ft_printf.h"
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

	if (*aux == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*aux == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*aux == 'p')
		ft_putaddr((long long)va_arg(args, void *), "0123456789abcdef");
	else if (*aux == 'd' || *aux == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*aux == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (*aux == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*aux == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*aux == '%')
		ft_putchar_fd('%', 1);
	else
		return 0;

	*aux_ptr = aux + 1; // Update the pointer to move past the format specifier
	return 1; // Returning 1 to advance past the '%' and the specifier
}


