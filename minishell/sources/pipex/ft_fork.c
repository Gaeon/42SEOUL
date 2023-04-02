
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

void	ft_fork_2(t_data *data, t_list *cmd, int fd[2])
{
	t_cmd	*cmd_c;
	int		len;

	cmd_c = cmd->content;
	len = 0;
	if (cmd_c->f_cmd)
		len = ft_strlen(*cmd_c->f_cmd);
	ft_fork_3(cmd, fd);
	close(fd[READ_END]);
	ft_fork_4(data, cmd_c, len, cmd);
	ft_lstclear(&data->cmds, ft_free_fd);
	exit(g_status_number);
}

void	*ft_fork_3(t_list *cmd, int fd[2])
{
	t_cmd	*cmd_c;

	cmd_c = cmd->content;
	if (cmd_c->input_fd != STDIN_FILENO)
	{
		if (dup2(cmd_c->input_fd, STDIN_FILENO) == -1)
			return (ft_perror(DUPERR, NULL, 1));
		close(cmd_c->input_fd);
	}
	if (cmd_c->output_fd != STDOUT_FILENO)
	{
		if (dup2(cmd_c->output_fd, STDOUT_FILENO) == -1)
			return (ft_perror(DUPERR, NULL, 1));
		close(cmd_c->output_fd);
	}
	else if (cmd->next && dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
		return (ft_perror(DUPERR, NULL, 1));
	close(fd[WRITE_END]);
	return ("");
}

void	ft_fork_4(t_data *data, t_cmd *cmd_c, int len, t_list *cmd)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!ft_built(cmd_c) && cmd_c->f_cmd)
		execve(cmd_c->f_path, cmd_c->f_cmd, data->env);
	else if (cmd_c->f_cmd && !ft_strncmp(*cmd_c->f_cmd, "pwd", len)
		&& len == 3)
		g_status_number = ft_pwd();
	else if (cmd_c->f_cmd && ft_built(cmd_c)
		&& !ft_strncmp(*cmd_c->f_cmd, "echo", len) && len == 4)
		g_status_number = ft_echo(cmd);
	else if (cmd_c->f_cmd && ft_built(cmd_c)
		&& !ft_strncmp(*cmd_c->f_cmd, "env", len) && len == 3)
	{
		ft_cmd_env(data->env, 1, 1);
		g_status_number = 0;
	}
}

