
#include "../../includes/minishell.h"

int	ft_n_rows(char **envp)
{
	int	len;

	len = 0;
	while (envp && envp[len])
		len++;
	return (len);
}
