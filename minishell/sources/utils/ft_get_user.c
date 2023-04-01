
#include "../../includes/minishell.h"

char	*ft_get_user(t_data data)
{
	char	**user;
	char	*tmp;
	char	*tmp2;

	user = NULL;
	tmp2 = NULL;
	ft_search_user(&user, "/usr/bin/whoami", "whoami", data.env);
	tmp2 = ft_strjoin(NULL, GREEN);
	tmp = ft_strjoin(tmp2, *user);
	free(tmp2);
	ft_free_split(&user);
	return (tmp);
}
