/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:40:06 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/25 10:40:07 by nataliascha      ###   ########.fr       */
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
	baselen = (unsigned long)printfft_strlen(base);
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
