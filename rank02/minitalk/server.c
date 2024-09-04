#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>


void signalhandler(int signum, siginfo_t *info, void *context)
{
    static int c;
    static int b;
    (void)info;
    (void)context;
    if (signum == SIGUSR1 || signum == SIGUSR2)
    {
        c <<= 1;
        if (signum == SIGUSR2)
            c |= 1;
        b++;
    }
    if (b == 8)
    {
        write(1, &c, 1);
        c = 0;
        b = 0;
    }
}

int main(void)
{
    struct sigaction action;

    action.sa_sigaction = signalhandler;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);
    printf("SERVER PID: %d\n", (int)getpid());
    while (1)
    {
        sigaction(SIGUSR1, &action, NULL);
        sigaction(SIGUSR2, &action, NULL);
        pause();
    }
}