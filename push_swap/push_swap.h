/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:19 by marvin            #+#    #+#             */
/*   Updated: 2023/01/15 18:44:30 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_node{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_info{
	int		size_a;
	int		size_b;
	t_node	*top_a;
	t_node	*bottom_a;
	t_node	*top_b;
	t_node	*bottom_b;
}	t_info;

//ft_printf.c
int		ft_input_check(const char *str);
int		ft_format(char c, va_list ap);
int		ft_printf(const char *str, ...);

//operation.c
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);

void	pa(t_info *info);
void	pb(t_info *info);

void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);

void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

#endif
