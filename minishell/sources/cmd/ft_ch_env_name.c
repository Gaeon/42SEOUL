#include "../../includes/minishell.h"

int	ft_ch_env_name(char *str)
{
	int		i[2];
	char	*s_str;

	i[0] = 0;
	i[1] = 0;
	s_str = "~@#%^-+:i.,\0";
	while (str[i[0]])
	{
		i[1] = 0;
		if (str[i[0]] == '=')
			break ;
		while (s_str[i[1]])
		{
			if (str[i[0]] == s_str[i[1]])
			{
				printf("-bash: export: not valid in this context\n");
				return (1);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}
