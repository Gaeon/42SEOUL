
#include "../../includes/minishell.h"

void	ft_getpid(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_perror(FORKERR, NULL, 1);
		ft_free_split(&data->env);
		exit(1);
	}
	if (!pid)
	{
		ft_free_split(&data->env);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	data->pid = pid;
}
