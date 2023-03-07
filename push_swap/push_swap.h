/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:19 by marvin            #+#    #+#             */
/*   Updated: 2023/03/07 14:55:23 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "ft_printf/ft_printf.h"

typedef struct s_argument{
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_argument;

typedef struct s_stack{
	int	*arr;
	int	size;
}	t_stack;

typedef struct s_info{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		pivot1;
	int		pivot2;
}	t_info;

//operation_sx
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
//operation_px
void	push_front(t_stack *stack);
void	push_back(t_stack *stack);
void	pa(t_info *info);
void	pb(t_info *info);
//operation_rx
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
//operation_rrx
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

// parsing/setting
void	duplicate_check(t_info *info, int num);
void	set_stack(int argc, char *argv[], t_info *info);
void	init_stack(int argc, char *argv[], t_info *info);
// parsing/util_split
int		ft_word_cnt(char const *s, char c);
char	**ft_split(char const *s, char c);
// parsing/util_atoi
int		ft_atoi_check(const char *str, t_info *info);

// algorithm/sort_under_5
void	ft_sort_three_element_a(t_info *info);
void	ft_sort_five_element_a(t_info *info, int size);
void	ft_sort_a(t_info *info, int size);
void	ft_sort_b(t_info *info, int size);
// algorithm/sorting
void	element_under_5(t_info *info, int flag, int size);
void	ft_sort(t_info *info);
// algorithm/util
int		is_stack_sorted(t_info *info, int flag, int size);
void	sort_duplicate_stack(int *array, int size);
int		*duplicate_stack(t_info *info, int flag, int size);
// algorithm/recursive
void	push_to_a(t_info *info, int size);
void	push_to_b(t_info *info, int size);

// push_swap
int		print_error(int type, t_info *info);
void	ft_free(char **str);

#endif
