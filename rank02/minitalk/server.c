/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nataliaschardosim <nataliaschardosim@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:11:01 by nataliascha       #+#    #+#             */
/*   Updated: 2024/09/06 14:31:52 by nataliascha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = signalhandler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR1 handler");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &action, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR2 handler");
		exit(EXIT_FAILURE);
	}
	ft_printf("SERVER PID: %d\n", (int)getpid());
	while (1)
		pause();
}

void signalhandler(int signum, siginfo_t *info, void *context)
{
	static int c = 0;
	static int b = 0;

	(void)context;
	(void)info;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		c <<= 1;
		if (signum == SIGUSR2)
			c |= 1;
		b++;
		if (b == 8)
		{
			if (write(1, &c, 1) == -1)
			{
				ft_printf("Error writing to stdout");
				exit(EXIT_FAILURE);
			}
			c = 0;
			b = 0;
		}
	}
}

