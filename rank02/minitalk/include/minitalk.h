/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:36:59 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/06 14:37:45 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <stdlib.h>

void	signalhandler(int sig, siginfo_t *info, void *ucontext);
void	parsestring(char *str, int serverpid);
void	sendnull(int serverpid);
void	ackreceived(int sig);

#endif