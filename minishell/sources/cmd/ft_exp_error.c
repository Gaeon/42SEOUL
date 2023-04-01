#include "../../includes/minishell.h"

int	ft_exp_error(int q[3], int *r_n)
{
	if (q[2] >= 2 && *r_n == -2)
	{
		printf("bash: export: not valid in this context\n");
		return (2);
	}
	else
	{
		q[2] = 1;
		return (1);
	}
}
