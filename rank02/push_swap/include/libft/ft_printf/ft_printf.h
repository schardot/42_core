/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:23:32 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/19 14:39:52 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>

int		ft_printf(const char *s, ...);
int		ft_format(int c, va_list *args);
int		ft_printchar(int c);
int		ft_printstr(char *s);
int		ft_printaddr(void *ptr, char *base, bool first);
int		ft_printnbr(int nb);
int		ft_printnbr_unsigned(unsigned int nb);
int		ft_putnbr_base(unsigned int nbr, const char *base);
char	*printfft_strchr(const char *s, int c);
size_t	printfft_strlen(const char *s);

#endif
