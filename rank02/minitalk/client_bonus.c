/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:11:02 by nleite-s          #+#    #+#             */
/*   Updated: 2024/09/18 17:11:05 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

volatile sig_atomic_t	g_flag = 0;

void	sendsig(int serverpid, int sig);
void	parsestring(char *str, int serverpid);
void	sendnull(int serverpid);
void	ackreceived(int sig);

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	parsestring(argv[2], pid);
}

void	parsestring(char *str, int serverpid)
{
	char	ch;
	int		i;
	int		b;

	signal(SIGUSR1, ackreceived);
	i = 0;
	while (str[i])
	{
		b = 7;
		ch = str[i];
		while (b >= 0)
		{
			if ((ch >> b) & 1)
				sendsig(serverpid, SIGUSR2);
			else
				sendsig(serverpid, SIGUSR1);
			b --;
			while (!g_flag)
				pause();
			g_flag = 0;
		}
		i ++;
	}
	sendnull(serverpid);
	exit(0);
}

void	sendnull(int serverpid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		sendsig(serverpid, SIGUSR1);
		i ++;
		while (!g_flag)
			pause();
		g_flag = 0;
	}
}

void	ackreceived(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 1;
}

void	sendsig(int serverpid, int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Sending SIGUSR1 (0) to server\n");
	else if (sig == SIGUSR2)
		ft_printf("Sending SIGUSR2 (1) to server\n");
	kill(serverpid, sig);
}
