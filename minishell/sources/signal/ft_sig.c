
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

void	ft_sig_c(int sig)
{
	if (sig == SIGINT)
	{
		g_status_number = 1;
		rl_on_new_line();
		rl_redisplay();
		write(2, "  ", 2);
		write(2, "\b\b", 2);
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
