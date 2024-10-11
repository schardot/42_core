/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:31:26 by nleite-s          #+#    #+#             */
/*   Updated: 2024/10/11 09:26:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && pft_strchr("cspdiuxX%", s[i + 1]))
		{
			len += ft_format(s[i + 1], &args);
			i ++;
		}
		else
		{
			ft_printchar(s[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_format(int c, va_list *args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_printchar(va_arg(*args, int));
	else if (c == 's')
		len += ft_printstr(va_arg(*args, char *));
	else if (c == 'p')
		len += ft_printaddr(va_arg(*args, void *), "0123456789abcdef", true);
	else if (c == 'd' || c == 'i')
		len += ft_printnbr(va_arg(*args, int));
	else if (c == 'u')
		len += ft_printnbr_unsigned(va_arg(*args, unsigned int));
	else if (c == 'x')
		len = ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len = ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len = ft_printchar('%');
	return (len);
}

char	*pft_strchr(const char *s, int c)
{
	size_t	i;
	char	temp_c;

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

size_t	pft_strlen(const char *s)
{
	size_t	length;
	int		i;

	i = 0;
	length = 0;
	while (s[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}
