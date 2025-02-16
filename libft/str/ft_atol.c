#include "libft.h"

int	ft_atol(const char *nptr)
{
	int		i;
	short	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str_space(&nptr[i]))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		++i;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

