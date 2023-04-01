#include "../../includes/minishell.h"

int	ft_cmd_env(char **env, int new_line, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (env && env[i])
	{
		if (new_line)
			count += ft_putendl_fd(env[i], fd);
		else
			count += ft_putstr_fd(env[i], fd);
		i++;
	}
	return (count);
}
