
#include "../../includes/minishell.h"

char	**ft_split_cmd(const char *in_cmd, char *c)
{
	char	**str;
	int		w_c;
	int		q[3];
	int		count[2];

	q[0] = 0;
	q[1] = 0;
	q[2] = 0;
	count[0] = 0;
	count[1] = 0;
	if (!in_cmd)
		return (NULL);
	w_c = ft_cmd_count(in_cmd, c, count);
	if (w_c == -1)
		return (NULL);
	str = malloc(sizeof(char *) * (w_c + 1));
	if (!str)
		return (NULL);
	str = ft_fill_cmd_2(str, in_cmd, c, q);
	str[w_c] = 0;
	return (str);
}
