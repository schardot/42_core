#include <stdio.h>
#include <unistd.h>
#include <signal.h>
<<<<<<< HEAD
#include <string.h>
=======
>>>>>>> 4ef74fdbce5d4a99e612b486aa81b393151a2b3f
#include <stdlib.h>

volatile sig_atomic_t flag = -1;

void signalhandler(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR1)
        flag = 0;
    if (signum == SIGUSR2)
        flag = 1;
    kill(info->si_pid, SIGUSR1);
}

int main(int argc, char *argv[])
{
    char c;
    int b;
    struct sigaction action;

    action.sa_sigaction = signalhandler;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);
    b = 0;
    c = 0;
    printf("SERVER PID: %d\n", (int)getpid());
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (1)
    {
        if (flag == 0 || flag == 1)
        {
            c <<= 1;
            if (flag == 1)
                c |= 1;
            flag = -1;
            b ++;
        }
        if (b == 8)
        {
            write(1, &c, 1);
            c = 0;
            b = 0;
        }
    }
}

<<<<<<< HEAD
void signalhandler(int sig, siginfo_t *info, void *ucontext)
{
    static char n = 0;
    static int b = 0;
    static char *string = NULL;
    char *dest;

    n <<= 1;
    if (sig == SIGUSR2)
    {
        n &= 1;
    }
    else
    b ++;
    if (b == 8)
    {
        // printf("%c\n", n);
        dest = (char *)malloc(strlen(dest) + 2);
        strcat(dest, &n);
        b = 0;
        n = 0;
    }
    printf("%s", string);
    kill(info->si_pid, SIGUSR1);
}
=======
>>>>>>> 4ef74fdbce5d4a99e612b486aa81b393151a2b3f











// #include <signal.h>
// #include <unistd.h>
// #include "include/minitalk.h"
// #include "libft/libft.h"
// #include "libft/ft_printf/ft_printf.h"

// void handle_sigusr(int sig);
// char *ft_stradd_back(char c, char *str);

// int main(void)
// {
// 	struct sigaction action;

// 	action.sa_handler = handle_sigusr;
// 	sigemptyset(&action.sa_mask);
// 	action.sa_flags = SA_RESTART;
// 	sigaction(SIGUSR1, &action, NULL);
// 	sigaction(SIGUSR2, &action, NULL);

// 	ft_printf("%d\n", (int)getpid());
//         while (1)
//     {
//         sleep(1);
//     }

// }

// void    handle_sigusr(int sig)
// {
//     static int num = 0;
//     static int bit = 0;
//     static char *str = NULL;

//     num = num << 1;
//     if (sig == SIGUSR2)
//         num |= 1;
//     bit ++;
//     if (bit == 8)
//     {
//         str = ft_stradd_back((char)num, str);
//         if (!str)
//         {
//             ft_printf("Error allocating memory.\n");
//             exit(1);
//         }
//         if (num == 0)
//         {
//             ft_printf("%s\n", str);
//             free(str);
//             str = NULL;
//         }
//         bit = 0;
//         num = 0;
//     }
// }

// char    *ft_stradd_back(char c, char *str)
// {
//     char    *newstr;
//     size_t  strlen;

//     strlen = ft_strlen(str);
//     newstr = (char *)malloc(strlen + 2);
//     if (!newstr)
//         return (NULL);
//     if (str)
//         ft_strlcpy(newstr, str, strlen + 2);
//     newstr[strlen] = c;
//     newstr[strlen + 1] = '\0';
//     free (str);
//     return (newstr);
// }
