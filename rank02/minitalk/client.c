#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void parsestring(char *str, int serverpid);


int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
        return(1);

    pid = atoi(argv[1]);

    parsestring(argv[2], pid);
    while (1)
        usleep(100);
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
        while (b >= 0)
        {
            if ((ch >> b) & 1)
                kill(serverpid, SIGUSR2);
            else
                kill(serverpid, SIGUSR1);
            b --;
            usleep(100);
        }
        i ++;
    }
    for (int j = 0; j < 8; j++)
    {
        kill(serverpid, SIGUSR1);
        usleep(100);
    }
    exit(1);
}
