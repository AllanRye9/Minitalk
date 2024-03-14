#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void error(int pid, char *str)
{
    if(str)
        free(str);
    ft_printf("unexpected error!");
    kill(pid, SIGUSR2);
    exit(1);
}

char *print_string(char *message)
{
    ft_putstr_fd(message, 1);
    free(message);
    return (NULL);
}

void signal_handler(int signum, siginfo_t *info, void *context)
{
    static char c = 0xFF;
    static int  bits = 0;
    static int  pid = 0;
    static char *message = 0;

    (void)context;
    if(info->si_pid)
        pid = info->si_pid;
    if(signum == SIGUSR1)
        c ^= 0x80 >> bits;
    else if(signum == SIGUSR2)
        c |= 0x80 >> bits;
    if (++bits == 8)
    {
        if(c)
            message = ft_straddc(message, c);
        else
            message = print_string(message);
        bits = 0;
        c = 0xFF;
    }
    if (kill(pid, SIGUSR1) == -1)
        error(pid, message);
}


int main()
{
    struct sigaction    sa_signal;
    sigset_t            block_mask;

    sigemptyset(&block_mask);
    sigaddset(&block_mask, SIGINT);
    sigaddset(&block_mask, SIGQUIT);
    sa_signal.sa_handler = 0;
    sa_signal.sa_flags = SA_SIGINFO;
    sa_signal.sa_mask = block_mask;
    sa_signal.sa_sigaction = signal_handler;
    sigaction(SIGUSR1, &sa_signal, NULL);
    sigaction(SIGUSR2, &sa_signal, NULL);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n", 1);
    while(1)
        pause();
}