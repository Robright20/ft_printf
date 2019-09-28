/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:57:29 by fokrober          #+#    #+#             */
/*   Updated: 2019/09/28 18:48:30 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <strings.h>
# include "libft.h"
# include <stdio.h>
# define ARGS_BUF "cspdiouxXfeg#0-+ llhhlhLbrk'*$"
# define ARGS_SIZE 32
# define CONV_BOUND 12
# define SET_FLAG(flags, pos) flags = (1 << pos) ^ flags
# define SET_FLAG_ON(flags, pos) flags = (1 << pos) | flags
# define RESET_FLAGS(flags) flags = 0
# define IS_FLAG_ON(flags, pos) (((1 << pos) & flags) != 0)

typedef enum	e_flag
{
	CHAR, STRING, POINTER, DEC, IDEC, OCTAL, UINT, HEX, UHEX, FLOAT, EXPO,
	GEXPO, HASH, ZERO, MINUS, PLUS, SPACE, LLONG, HH, LONG, H, L, BIN, R,
	K, QUOTE, STAR, DOLLAR
}				t_flag;
int		ft_strnstr(char *s1, char *s2, int n);
void	save_flag(int *flags, char *format, int argw);
int		first_char_nbr(char *s);
void	save_all_flags(int *flags, char *args);
int		is_conv_spec(char c, char *args);
#endif
