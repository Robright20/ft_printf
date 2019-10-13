/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:57:29 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/13 04:54:05 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <strings.h>
# include "libft.h"
# include <stdio.h>
# include <locale.h>
# define FLAGS_BUF "cspdiouxXfeg#0-+ llhhlhLbrk'*$."
# define FLAGS_SIZE 32
# define CONV_BOUND 12
# define SET_FLAG(flags, pos) flags = (1 << pos) | flags
# define SET_FLAG_ON(flags, pos) flags = (1 << pos) | flags
# define SET_FLAG_OFF(flags, pos) flags = (1 << pos) ^ flags
# define RESET_FLAGS(flags) flags = 0
# define IS_ON(flags, pos) (((1 << pos) & flags) != 0)

typedef enum	e_flag
{
	CHAR, STRING, POINTER, DEC, IDEC, OCTAL, UINT, HEX, BHEX, FLOAT, EXPO,
	GEXPO, HASH, ZERO, MINUS, PLUS, SPACE, LLONG, HHALF, LONG, HALF, BLONG,
	BIN, RSTRING, KDATE, QUOTE, STAR, DOLLAR, PRECISION
}				t_flag;
typedef struct lconv t_lconv;
long long	(*g_fetch_by_sizem[4])(va_list ap, int bsigned);
int			ft_putc(va_list ap, int flags, int width, int precision);
int			ft_puts(va_list ap, int flags, int width, int precision);
int			ft_putptr(va_list ap, int flags, int width, int precision);
int			ft_putdnbr(va_list ap, int flags, int width, int precision);
int			ft_putonbr(va_list ap, int flags, int width, int precision);
int			ft_putunbr(va_list ap, int flags, int width, int precision);
int			ft_putxnbr(va_list ap, int flags, int width, int precision);
int			ft_putfnbr(va_list ap, int flags, int width, int precision);
int			ft_putenbr(va_list ap, int flags, int width, int precision);
int			ft_putgnbr(va_list ap, int flags, int width, int precision);
int			save_flag(int *flags, char *format);
int			first_char_count(char *s);
int			is_conv_spec(char c, char *args);
int			va_argnth(va_list ap, char *fmt);
void		init(int (*router[12])(int, int, int, va_list));
int			first_char_count(char *s);
int			find_flag(char *flag_lst, char *format, int flagw);
int			save_width(char *fmt, int *width, va_list ap);
int			save_precision(char *fmt, int *precision, va_list ap);
int			find_color(char *color);
void		set(int color_id);
int			set_color(char *fmt);
char		*ft_downcase(char *fmt);
void		printbits(void *p, int i);
int			ft_printf(const char *restrict fmt, ...);
long long	fetch_by_sizem_h(va_list ap, int bsigned);
long long	fetch_by_sizem_ll(va_list ap, int bsigned);
long long	fetch_by_sizem_l(va_list ap, int bsigned);
long long	fetch_by_sizem_hh(va_list ap, int bsigned);
char		*place_before(char *result, char *prefix);
char		*place_at_lastsp(char *new_result, int sign);
int			flag_lookup(int flags, int pos, int bound);
ssize_t		ft_putxstr(char *s);
char		*build_result(int flags, char *ret, int precision, int width);
char		*apply_precision(int *flags, char *ret, int conv, int precision);
char		*apply_width(int *flags, char *result, int conv, int width);
char		*apply_hash(int *flags, char *result, int conv, int diff);
char		*apply_signs(int *flags, char *result, int conv, int diff);
char		*apply_quote(int *flags, char *result, int conv, int width);
#endif
