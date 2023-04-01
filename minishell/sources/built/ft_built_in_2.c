#include "../../includes/minishell.h"

int	ft_built_in_2(t_data *data, t_list *cmd, char **str, int n)
{
	if (str && !cmd->next && !ft_strncmp(*str, "export", n) && n == 6)
		g_status_number = ft_export(data);
	else if (str && !cmd->next && !ft_strncmp(*str, "unset", n) && n == 5)
		g_status_number = ft_unset(data);
	else if (str && !cmd->next && !ft_strncmp(*str, "cd", n) && n == 2)
		g_status_number = ft_cd(data);
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, ft_sig_q);
		ft_run_cmd(data, cmd);
	}
	return (g_status_number);
}
