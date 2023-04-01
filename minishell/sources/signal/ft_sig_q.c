
#include "../../includes/minishell.h"

void	ft_sig_q(int sig)
{
	if (sig == SIGQUIT)
	{
		g_status_number = 131;
		rl_redisplay();
		write(2, "  ", 2);
		write(2, "\b\b", 2);
	}
}
