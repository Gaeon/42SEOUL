#include "../../includes/minishell.h"

int	ft_cd(t_data *data)
{
	char	**str[2];
	char	*tmp;

	g_status_number = 0;
	str[0] = ((t_cmd *)data->cmds->content)->f_cmd;
	tmp = ft_get_envalue("HOME", data->env, 4);
	if (!tmp)
		tmp = ft_strdup("");
	str[1] = ft_extend_split(NULL, tmp);
	free(tmp);
	tmp = getcwd(NULL, 0);
	str[1] = ft_extend_split(str[1], tmp);
	free(tmp);
	ft_cd_error(str);
	if (!g_status_number)
		data->env = ft_search_env("OLDPWD", str[1][1], data->env, 6);
	tmp = getcwd(NULL, 0);
	if (!tmp)
		tmp = ft_strdup("");
	str[1] = ft_extend_split(str[1], tmp);
	free(tmp);
	data->env = ft_search_env("PWD", str[1][2], data->env, 3);
	ft_free_split(&str[1]);
	return (g_status_number);
}

void	ft_cd_error(char **str[2])
{
	DIR	*dir;

	dir = NULL;
	if (str[0][1])
		dir = opendir(str[0][1]);
	if (!str[0][1] && str[1][0] && !str[1][0][0])
	{
		g_status_number = 1;
		ft_putstr_fd("bash: HOME not set\n", 2);
	}
	if (str[1][0] && !str[0][1])
		g_status_number = chdir(str[1][0]) == -1;
	if (str[0][1] && dir && access(str[0][1], F_OK) != -1)
		chdir(str[0][1]);
	else if (str[0][1] && access(str[0][1], F_OK) == -1)
		ft_perror(NDIR, str[0][1], 1);
	else if (str[0][1])
		ft_perror(NOT_DIR, str[0][1], 1);
	if (str[0][1] && dir)
		closedir(dir);
}
