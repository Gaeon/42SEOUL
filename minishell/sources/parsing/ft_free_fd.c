
#include "../../includes/minishell.h"

void	ft_free_fd(void *content)
{
	t_cmd	*cmd;

	cmd = content;
	ft_free_split(&cmd->f_cmd);
	free(cmd->f_path);
	if (cmd->input_fd != STDIN_FILENO)
		close(cmd->input_fd);
	if (cmd->output_fd != STDOUT_FILENO)
		close(cmd->output_fd);
	free(cmd);
}
