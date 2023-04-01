#include "../../includes/minishell.h"

int	ft_check_dir(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "&*()|;/><";
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
