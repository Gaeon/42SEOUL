/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:12:11 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/05 18:14:26 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

//ft_printf.c
int		ft_format(char c, va_list ap);
int		ft_printf(const char *str, ...);
int		ft_print_c(int c);
int		ft_print_s(char *str);
int		ft_print_di(int nbr);

//ft_printf_util.c
size_t	ft_strlen(const char *s);
int		ft_putnbr(int nb);

#endif