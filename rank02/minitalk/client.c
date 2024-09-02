#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signalhandler(int sig);
void parsestring(char *str, int serverpid);

volatile sig_atomic_t flag = 0;

int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
        return(1);

    pid = atoi(argv[1]);
    signal(SIGUSR1, signalhandler);
    if (flag == -1)
    {
        while (flag != 7)
        {
            kill(pid, SIGUSR2);
            flag ++;
        }
    }
    parsestring(argv[2], pid);
    while (1)
        pause();

}

void signalhandler(int sig)
{
    flag = 1;
}

void    parsestring(char *str, int serverpid)
{
    static char ch;
    static int i;
    static int b;

    i = 0;
    while (str[i] != '\0')
    {
        b = 7;
        ch = str[i];
        while (b >= 0 && flag == 1)
        {
            if ((ch >> b) & 1)
                kill(serverpid, SIGUSR2);
            else
                kill(serverpid, SIGUSR1);
            b --;
            flag = 0;
            pause();
        }
        i ++;
    }
    flag = -1; // Sending all bits as 0 (SIGUSR1) for a NULL character
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
