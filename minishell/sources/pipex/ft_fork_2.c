
#include "../../includes/minishell.h"

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
