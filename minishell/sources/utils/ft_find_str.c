
#include "../../includes/minishell.h"

char	*ft_find_str(char *str)
{
	int		i;
	char	*r_str;

	i = 0;
	r_str = NULL;
	while (str[i])
	{
		if (str[i] == '=')
		{
			r_str = ft_substr(str, 0, i);
			break ;
		}
		i++;
	}
	return (r_str);
}
