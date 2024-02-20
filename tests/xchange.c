#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int ft_len(char *str){
    int i = 0;
    while(str[i]!= '\0'){
        i++;
    }
    return i;
}

char *ft_strrev(char *str){
    int i = 0;
    int j = ft_len(str) -1;
    while(i < j){
        str[i] = str[j];
        str[j] = str[i];
        i++;
        j--;
    }
    return str;
}

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