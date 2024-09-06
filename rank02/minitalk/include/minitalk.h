#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include <stdlib.h>

void signalhandler(int sig, siginfo_t *info, void *ucontext);
void parsestring(char *str, int serverpid);
void sendnull(int serverpid);
void ackreceived(int sig);

#endif