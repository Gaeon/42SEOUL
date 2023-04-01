
#include "../../includes/minishell.h"

int	ft_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	ft_putendl_fd(str, 1);
	free(str);
	return (0);
}
