/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:08:26 by gaeokim           #+#    #+#             */
/*   Updated: 2022/10/31 16:16:01 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_info {
	int	cnt;
	int	c;
}	t_info;

//server.c
void	ft_handler(int signum);

// client.c
void	client(pid_t pid, char *str);

// util.c
int		ft_atoi(const char *str);

//ft_printf.c
int		ft_input_check(const char *str);
int		ft_format(char c, va_list ap);
int		ft_printf(const char *str, ...);

//ft_printf_format.c
int		ft_print_c(int c);
int		ft_print_s(char *str);
int		ft_print_di(int nbr);
int		ft_print_p(unsigned long long nbr);
int		ft_print_ux(char c, unsigned int nbr);

//ft_printf_util.c
int		ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int nb);
int		ft_putnbr_ux(const char *base, unsigned int nb);
int		ft_putnbr_p(unsigned long long nb);

#endif
