/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:05:25 by nleite-s          #+#    #+#             */
/*   Updated: 2024/09/17 12:05:29 by nleite-s         ###   ########.fr       */
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
		usleep(100);
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
			usleep(300);
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
	}
}
