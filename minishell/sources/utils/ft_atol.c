#include "../../includes/minishell.h"

long long	ft_atol(char *str, long long *n)
{
	long long	sign;

	sign = 1;
	*n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (-1);
	while (ft_isdigit(*str))
	{
		*n = 10 * (*n) + (*str - '0');
		str++;
	}
	if (*str && !ft_isspace(*str))
		return (-1);
	*n *= sign;
	return (0);
}
