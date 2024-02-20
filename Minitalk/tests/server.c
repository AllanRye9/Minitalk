#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/libft.h"
#include <signal.h>
// ◦ write
// ◦ ft_printf and any equivalent YOU coded
// ◦ signal
// ◦ sigemptyset
// ◦ sigaddset
// ◦ sigaction
// ◦ kill
// ◦ getpid
// ◦ malloc
// ◦ free
// ◦ pause
// ◦ sleep
// ◦ usleep
// ◦ exit
// int ft_server(char *str)
// {
//     int PID;
//     while (ft_strncmp(str, "server", ft_strlen(str)) == 0)
//         PID = getpid();
//     return (PID);
// }

// int main(int ac, char **av)
// {
//     int i = 0;
//     if (ac == 1){
//     while (av[i] != NULL){
//         if (ft_server(av[i]) != 0);
//             printf("%d\n", ft_server(av[i]));
//             break;
//     }
//     }
//     else
//         write (1, "no argument passed\n", 19);
//     return 0;
// }

int main(int ac, char **av)
{
    ft_printf("PID: %d\n", getpid());
    return 0;
}