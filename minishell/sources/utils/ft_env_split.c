
#include "../../includes/minishell.h"

char	**ft_env_split(char **envp)
{
	char	**env_split;
	int		i;
	int		n_rows;

	i = 0;
	n_rows = ft_n_rows(envp);
	env_split = malloc(sizeof(char *) * (n_rows + 1));
	if (!env_split)
		return (NULL);
	while (envp[i])
	{
		env_split[i] = ft_strdup(envp[i]);
		if (!env_split[i])
		{
			ft_free_split(&env_split);
			return (NULL);
		}
		i++;
	}
	env_split[i] = NULL;
	return (env_split);
}
