/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:57:29 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/01 22:56:58 by fokrober         ###   ########.fr       */
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
void	save_flag(int *flags, char *format, int argw);
int		first_char_nbr(char *s);
int		is_conv_spec(char c, char *args);
int		va_argnth(va_list ap, char *fmt);
void	init(int (*router[12])(int, int, int, va_list));
int		first_char_nbr(char *s);
int		find_flag(char *s, char *format);
int		save_width(char *fmt, int *width, va_list ap, va_list ap2);
int		save_precision(char *fmt, int *precision, va_list ap, va_list ap2);
int		find_color(char *color);
void	set(int color_id);
int		set_color(char *fmt);
char	*ft_downcase(char *fmt);
#endif
