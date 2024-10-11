/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:23:04 by nataliascha       #+#    #+#             */
/*   Updated: 2024/10/11 09:26:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	char	ch;

	ch = (char)c;
	write(1, &ch, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		i += ft_printstr("(null)");
	else
	{
		while (s[i] != '\0')
			i += ft_printchar(s[i]);
	}
	return (i);
}

int	ft_printaddr(void *ptr, char *base, bool first)
{
	unsigned long	addr;
	unsigned long	baselen;
	int				len;

	len = 0;
	baselen = (unsigned long)pft_strlen(base);
	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		len += ft_printf("%s", "(nil)");
		return (len);
	}
	else if (first)
		len += ft_printstr("0x");
	if (addr == 0)
		len += ft_printchar(base[0]);
	else
	{
		if (addr >= baselen)
			len += ft_printaddr((void *)(addr / baselen), base, false);
		len += ft_printchar(base[addr % baselen]);
	}
	return (len);
}
