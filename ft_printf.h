/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:57:29 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/02 22:28:27 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <strings.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "bigint.h"
# define ARGS_BUF "cspdiouxXfeg#0-+ llhhlhLbrk'*$"
# define ARGS_SIZE 32
# define CONV_BOUND 12
# define SET_FLAG(flags, pos) flags = (1 << pos) ^ flags
# define SET_FLAG_ON(flags, pos) flags = (1 << pos) | flags
# define RESET_FLAGS(flags) flags = 0
# define IS_FLAG_ON(flags, pos) (((1 << pos) & flags) != 0)

/*
** char			*add_padding(char *str, t_fwp flg, long long sigr);
** char			*precision(t_bigint *bb, int dec_pos, long long sign,\
**														t_fwp flg);
** void			print_bigint(t_bigint bb, int dec_pos, long long sign,\
**														t_fwp flg);
** void			add_pad_neg(char *buff, t_fwp flg, char *str, int len);
** void			add_pad_pos(char *buff, t_fwp flg, char *str, int len);
** void			rounding(t_bigint *bb, int i);
*/

/*
** ---------------------------------------------------------------------------
** rober branch, hexa_optimisation clone
*/

typedef enum	e_flag
{
	CHAR, STRING, POINTER, DEC, IDEC, OCTAL, UINT, HEX, UHEX, FLOAT, EXPO,
	GEXPO, HASH, ZERO, MINUS, PLUS, SPACE, LLONG, HH, LONG, H, L, BIN,\
	R, K, QUOTE, STAR, DOLLAR
}				t_flag;

/*
** ---------------------------------------------------------------------------
** 							function headers
*/

int		ft_strnstr(char *s1, char *s2, int n);
void	save_flag(int *flags, char *format, int argw);
int		first_char_nbr(char *s);
void	save_all_flags(int *flags, char *args);
int		is_conv_spec(char c, char *args);
void	printbits(void *p, int i);
int		ft_putfnbr(t_fwp flags, double nbr);
void	last_flags(char **str, t_fwp flg);

#endif
