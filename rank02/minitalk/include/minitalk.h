#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

void handle_sigusr(int sig);
void signalhandler(int sig, siginfo_t *info, void *ucontext);
void parsestring(char *str, int serverpid);

#endif