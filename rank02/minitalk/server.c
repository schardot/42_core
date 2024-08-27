#include <signal.h>
#include <unistd.h>

//SIGUSR1 = quando bit for 0
void handle_sigusr1(int sig);
void handle_sigusr2(int sig);

int letter;

letter = 0;
int main(void)
{
    ft_printf("%d", (int)getpid());
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);
    while (1)
    {
        sleep(1);
    }

}

void handle_sigusr1(int sig)
{

}

void handle_sigusr2(int sig)
{
    int y;

    y = 1;
    y << 8 - bit - 1;
    x = x | y;
    bit++;
}