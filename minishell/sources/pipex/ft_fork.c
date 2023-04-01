
#include "../../includes/minishell.h"

void	ft_fork(t_data *data, t_list *cmd, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		ft_perror(FORKERR, NULL, 1);
	}
	else if (!pid)
		ft_fork_2(data, cmd, fd);
}
