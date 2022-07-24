/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:41:54 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/24 17:32:15 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_input_check(const char *str);
ssize_t	ft_format(const char *str, va_list *ap);
int		ft_printf(const char *str, ...);

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

int		ft_print_c(int c);
int		ft_print_s(char *str);
int		fr_print_diu(int nbr);
ssize_t	ft_print_X(const char c, va_list *ap);

#endif
