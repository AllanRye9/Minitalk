#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

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



int main(int ac, char **av)
{
    int i = 1;
    if (ac > 1){
        while (i < ac){
           printf("words: %s ->length: %d\n", av[i], ft_len(ft_strrev(av[i])));
           i++;
    }
    }
    else
        write (1, "no argument passed\n", 19);
    return 0;
}