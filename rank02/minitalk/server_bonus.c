/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:11:01 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/18 16:37:59 by nleite-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "include/minitalk.h"

void	signalhandler(int signum, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	b = 0;

	(void)context;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		c <<= 1;
		if (signum == SIGUSR2)
			c |= 1;
		b ++;
		if (b == 8)
		{
			write(1, &c, 1);
			if (c == 0)
				write(1, "\n", 1);
			c = 0;
			b = 0;
		}
		if (kill(info->si_pid, SIGUSR1) == -1)
		{
			perror("Error sending acknowledgment signal to client");
		}
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = signalhandler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	ft_printf("SERVER PID: %d\n", (int)getpid());
	if (sigaction(SIGUSR1, &action, NULL) == -1)
	{
		perror("Error setting up SIGUSR1 handler");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &action, NULL) == -1)
	{
		perror("Error setting up SIGUSR2 handler");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		//kill(info->si_pid, SIGUSR1);
		pause();
	}
}
