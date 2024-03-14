#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void error(char *str)
{
    if (str)
        free(str);
    ft_printf("error!");
    exit(1);
}

int checker(int pid, char *str)
{
    static int i = 0;

    if (i++ != 8)
    {
        if (kill(pid, SIGUSR1) == -1)
            error(str);
        return (0);
    }
    return (1);
}

int send_bits(int pid, char *str)
{
    static char *message = 0;
    static int s_pid = 0;
    static int bits = -1;

    if (str)
        message = ft_strdup(str);
    if (!message)
        error(0);
    if (pid)
        s_pid = pid;
    if (message[++bits / 8])
    {
        if (message[bits / 8] & (0x80 >> (bits % 8)))
        {
            if (kill(s_pid, SIGUSR1) == -1)
                error(message);
        }
        else if (kill(s_pid, SIGUSR2) == -1)
            error(message);
        return (0);
    }
    if (!checker(s_pid, message))
        return (0);
    free(message);
    return (1);
}

void signal_handler(int signum)
{
    int end;

    end = 0;
    if (signum == SIGUSR1)
        end = send_bits(0, 0);
    else if(signum == SIGUSR2)
        exit(1);
    else
        exit(0);
}

int main(int ac, char **av)
{
    if(ac != 3)
    {
        ft_printf("invalid arguments");
        exit(1);
    }
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    send_bits(ft_atoi(av[1]), av[2]);
    while(1)
        pause();
}