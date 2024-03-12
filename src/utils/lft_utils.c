#include "minirt.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		write (1, &str[i], 1);
}
