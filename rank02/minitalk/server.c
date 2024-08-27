#include <signal.h>
#include <unistd.h>

void handle_sigusr(int sig);

int main(void)
{
    ft_printf("%d", (int)getpid());
    signal(SIGUSR1, handle_sigusr);
    signal(SIGUSR2, handle_sigusr);
    while (1)
    {
        sleep(1);
    }

}

void handle_sigusr(int sig)
{
    int num;
    static int bit;

    bit = 0;
    num = 0;
    num = num << 1;
    if (sig = SIGUSR2)
        num = num | 1;
    bit ++;
    if (bit == 8)
    {
        a letra ja ta completa;
        adicionar letra na string;
    }
    se letra for NULL
        imprimir oq tem da string
}