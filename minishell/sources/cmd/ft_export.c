#include "../../includes/minishell.h"

int	ft_export(t_data *data)
{
	int		q[3];
	int		r_n;
	char	**str;

	q[2] = 1;
	str = ((t_cmd *)data->cmds->content)->f_cmd;
	if (ft_n_rows(str) == 1)
		return (ft_cmd_export(data));
	if (ft_n_rows(str) >= 2)
	{
		q[0] = 1;
		while (str[q[0]])
		{
			r_n = ft_env_var(str[q[0]], data->env, q);
			if (r_n == -1 || ft_ch_env_name(str[q[0]]) || ((!r_n || r_n == 1 \
				|| r_n == -2) && ft_exp_error(q, &r_n) >= 2))
				return (1);
			if ((r_n == -2 && !str[++q[0]]) && q[2] >= 1)
				return (0);
			ft_export_2(data, str, q, &r_n);
			q[0]++;
			q[2]++;
		}
	}
	return (0);
}

t_data	*ft_export_2(t_data *data, char **str, int q[3], int *r_n)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (*r_n == 1 || *r_n == -2)
	{
		i = 0;
		while (str[q[0]][i])
			if (str[q[0]][i++] == '=')
				f = 1;
		if (f)
		{
			free(data->env[q[1]]);
			data->env[q[1]] = ft_strdup(str[q[0]]);
		}
		else
			return (data);
	}
	else if (!*r_n)
		data->env = ft_extend_split(data->env, str[q[0]]);
	return (data);
}
