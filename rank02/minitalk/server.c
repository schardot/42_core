#include <signal.h>
#include <unistd.h>
#include "include/minitalk.h"
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

void handle_sigusr(int sig);
char *ft_stradd_back(char c, char *str);

int main(void)
{
    ft_printf("%d\n", (int)getpid());
    signal(SIGUSR1, handle_sigusr);
    signal(SIGUSR2, handle_sigusr);
    while (1)
    {
        sleep(1);
    }

}

void    handle_sigusr(int sig)
{
    static int num = 0;
    static int bit = 0;
    static char *str = NULL;

    num = num << 1;
    if (sig == SIGUSR2)
        num |= 1;
    bit ++;
    if (bit == 8)
    {
        str = ft_stradd_back((char)num, str);
        if (!str)
        {
            ft_printf("Error allocating memory.\n");
            exit(1);
        }
        if (num == 0)
        {
            ft_printf("%s\n", str);
            free(str);
            str = NULL;
        }
        bit = 0;
        num = 0;
    }
}

char    *ft_stradd_back(char c, char *str)
{
    char    *newstr;
    size_t  strlen;

    strlen = ft_strlen(str);
    newstr = (char *)malloc(strlen + 2);
    if (!newstr)
        return (NULL);
    if (str)
        ft_strlcpy(newstr, str, strlen + 2);
    newstr[strlen] = c;
    newstr[strlen + 1] = '\0';
    free (str);
    return (newstr);
}