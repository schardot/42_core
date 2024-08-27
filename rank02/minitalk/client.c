#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pid;
    int i;

    if (argc != 3)
    {
        ft_printf("Error, wrong arguments.");
        return (1);
    }
    int b;
    int letter;

    pid = atoi(argv[1]);
    i = 0;
    while (argv[2][i] != '\0')
    {
        b = 7;
        while (b >= 0)
        {
            letter = argv[2][i];
            letter = letter >> b;
            if ((letter & 1) == 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            b--;
            usleep(100);
        }
        i ++;
    }
}
