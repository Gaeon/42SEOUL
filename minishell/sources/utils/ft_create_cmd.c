
#include "../../includes/minishell.h"

t_cmd	*ft_create_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->f_cmd = NULL;
	cmd->f_path = NULL;
	cmd->input_fd = STDIN_FILENO;
	cmd->output_fd = STDOUT_FILENO;
	return (cmd);
}
