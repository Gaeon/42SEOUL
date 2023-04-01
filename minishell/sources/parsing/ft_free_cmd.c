
#include "../../includes/minishell.h"

t_list	*ft_free_cmd(t_list *cmds, char **in_cmd, char **tmp)
{
	ft_lstclear(&cmds, ft_free_fd);
	ft_free_split(&in_cmd);
	ft_free_split(&tmp);
	return (NULL);
}
