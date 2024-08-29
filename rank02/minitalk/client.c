#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signalhandler(int sig, siginfo_t *info, void *ucontext);

int main(int argc, char **argv)
{
    int pid;
    struct sigaction action;

    action.sa_sigaction = signalhandler;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);
    pid = atoi(argv[1]);
    sigaction(SIGUSR1, &action, NULL);
    kill(pid, SIGUSR1);
    while (1)
        pause();
}

void signalhandler(int sig, siginfo_t *info, void *ucontext)
{
    printf("CLIENT: recebi o sinal %d do processo %d.\n", sig, info->si_pid);
}

// #include "include/minitalk.h"
// #include "libft/libft.h"
// #include "libft/ft_printf/ft_printf.h"
// #include <signal.h>
// #include <unistd.h>

// int main(int argc, char *argv[])
// {
//     if (argc != 3)
//     {
//         ft_printf("Usage: %s <PID> <message>\n", argv[0]);
//         return (1);
//     }

//     int pid = ft_atoi(argv[1]);
//     if (pid <= 0)
//     {
//         ft_printf("Invalid PID.\n");
//         return (1);
//     }

//     int i = 0;
//     while (argv[2][i] != '\0')
//     {
//         int b = 7;
//         int letter = argv[2][i];
//         while (b >= 0)
//         {
//             if ((letter & (1 << b)) != 0)
//             {
//                 if (kill(pid, SIGUSR2) == -1)
//                 {
//                     ft_printf("Failed to send SIGUSR2.\n");
//                     return (1);
//                 }
//             }
//             else
//             {
//                 if (kill(pid, SIGUSR1) == -1)
//                 {
//                     ft_printf("Failed to send SIGUSR1.\n");
//                     return (1);
//                 }
//             }
//             b--;
//             usleep(100); // Short delay to ensure the signal is processed correctly
//         }
//         i++;
//     }

//     return 0;
// }
