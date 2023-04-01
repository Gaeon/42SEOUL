#include "../../includes/minishell.h"

int	ft_cmd_export(t_data *data)
{
	char	**str[2];
	int		i;

	i = 0;
	str[0] = ((t_cmd *)data->cmds->content)->f_cmd;
	while (data->env[i])
		printf("declare -x %s\n", data->env[i++]);
	return (0);
}
