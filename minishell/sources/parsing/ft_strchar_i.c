
#include "../../includes/minishell.h"

int	ft_strchar_i(char *in_cmd, char *set)
{
	int	i;

	i = 0;
	if (!in_cmd)
		return (-1);
	while (in_cmd[i])
	{
		if (ft_strchr(set, in_cmd[i]))
			return (i);
		i++;
	}
	return (-1);
}
