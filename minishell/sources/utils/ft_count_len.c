
#include "../../includes/minishell.h"

int	ft_count_len(char *s1)
{
	int	sq;
	int	dq;
	int	count;
	int	i;

	i = 0;
	sq = 0;
	dq = 0;
	count = 0;
	while (s1 && s1[i])
	{
		sq = (sq + (!dq && s1[i] == '\'')) % 2;
		dq = (dq + (!sq && s1[i] == '\"')) % 2;
		if ((s1[i] == '\"' && !sq) || (s1[i] == '\'' && !dq))
			count++;
		i++;
	}
	if (sq || dq)
		return (-1);
	return (count);
}
