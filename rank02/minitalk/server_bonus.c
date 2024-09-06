/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:11:01 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/06 11:03:25 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	signalhandler(int signum, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	b = 0;

	(void)context;
	(void)info;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		c <<= 1;
		if (signum == SIGUSR2)
			c |= 1;
		b ++;
		if (b == 8)
		{
			write(1, &c, 1);
			c = 0;
			b = 0;
			kill(info->si_pid, SIGUSR1);
		}
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = signalhandler;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	printf("SERVER PID: %d\n", (int)getpid());
	while (1)
	{
		if (sigaction(SIGUSR1, &action, NULL) == -1)
		{
			perror("sigaction");
			exit(EXIT_FAILURE);
		}
		if (sigaction(SIGUSR2, &action, NULL) == -1)
		{
			perror("sigaction");
			exit(EXIT_FAILURE);
		}
		pause();
	}
}
