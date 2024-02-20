#include "libft/libft.h"
#include <signal.h>

void	killing_func(int pid, unsigned char octet)
{
	int				i;
	unsigned char	octet_tmp;

	octet_tmp = octet;
	i = 8;
	while (i-- > 0)
	{
		octet_tmp = octet >> i;
		if (octet_tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		client_id;
	char	*buf;
	int		i;

	if (ac < 3)
	{
		ft_printf("failed!\n");
		return (0);
	}
	client_id = ft_atoi(av[1]);
	buf = (void *)malloc(ft_strlen(av[2]) + 1);
	buf = av[2];
	i = 0;
	while (buf[i])
	{
		killing_func(client_id, buf[i]);
		i++;
	}
	ft_printf("counted %i characters \n", i);
	free(buf);
	return (0);
}
