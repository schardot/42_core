/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:10:58 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/18 16:49:19 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "include/minitalk.h"

volatile sig_atomic_t	flag = 0;

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
	int	i;
	int	b;

	signal(SIGUSR1, ackreceived);
	i = 0;
	while (str[i])
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
			while(!flag)
				pause();
			flag = 0;
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
		kill(serverpid, SIGUSR1);
		i ++;
		while (!flag)
			pause();
		flag = 0;
	}
}

void	ackreceived(int sig)
{
	if (sig == SIGUSR1)
		flag = 1;
}
