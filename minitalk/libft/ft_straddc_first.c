#include "libft.h"

char	*ft_straddc_first(char c)
{
	char	*add;

	add = (char *)malloc(sizeof(char) * 2);
	if (!add)
		return (0);
	add[0] = c;
	add[1] = '\0';
	return (add);
}


