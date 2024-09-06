/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:10:58 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/06 14:17:16 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	parsestring(argv[2], pid);
	while (1)
	{
		usleep(100);
	}
}

void	parsestring(char *str, int serverpid)
{
	static char	ch;
	static int	i;
	static int	b;

	i = 0;
	while (str[i] != '\0')
	{
		b = 7;
		ch = str[i];
		while (b >= 0)
		{
			if ((ch >> b) & 1)
				kill(serverpid, SIGUSR2);
			else
				kill(serverpid, SIGUSR1);
			b --;
			usleep(100);
		}
		i ++;
	}
	sendnull(serverpid);
	exit(1);
}

void	sendnull(int serverpid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(serverpid, SIGUSR1);
		i ++;
		usleep(100);
		signal(SIGUSR1, ackreceived);
	}
}

void	ackreceived(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Received acknowledgement from server\n", 39);
}
