/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:57:29 by fokrober          #+#    #+#             */
/*   Updated: 2019/09/23 00:44:41 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <strings.h>
# include <stdio.h>
# define ARGS_BUF "cspdiouxXfeg#0-+ llhhlhLbrk'*$"
# define ARGS_SIZE 32
# define set_flag(flags, pos) flags = (1 << pos) ^ flags
# define set_flag_on(flags, pos) flags = (1 << pos) | flags
# define reset_flags(flags) flags = 0
# define is_flag_on(flags, pos) (((1 << pos) & flags) != 0)

int		ft_strnstr(char *s1, char *s2, int n);
void	save_flag(int *flags, char *format, int argw);
int		first_char_nbr(char *s);
void	save_all_flags(int *flags, char *args);
#endif
