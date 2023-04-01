#include "../../includes/minishell.h"

int	ft_built_in(t_data *data, t_list *cmd, int *exit_n, int n)
{
	char	**str;

	while (cmd)
	{
		str = ((t_cmd *)cmd->content)->f_cmd;
		n = 0;
		if (str)
			n = ft_strlen(*str);
		if (str && !ft_strncmp(*str, "exit", n) && n == 4)
			g_status_number = ft_exit(cmd, exit_n);
		g_status_number = ft_built_in_2(data, cmd, str, n);
		cmd = cmd->next;
	}
	return (g_status_number);
}
