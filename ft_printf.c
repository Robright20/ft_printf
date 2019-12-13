/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 14:51:50 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/13 06:01:40 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		va_argnth(va_list ap, char *fmt)
{
	int		i;
	int		nbr;

	i = 0;
	while ((fmt[i] && ft_isdigit(fmt[i])))
		i++;
	if (i != 0 && fmt[i] == '$')
	{
		nbr = ft_atoi(fmt);
		while (nbr && --nbr)
			va_arg(ap, void *);
		return (++i);
	}
	return (0);
}

char	*flag_scope(int *nbr, char *fmt, va_list ap)
{
	int		flags;
	int		pw[2];
	int		pos;

	flags = 0;
	fmt += va_argnth(ap, fmt);
	ft_bzero(pw, sizeof(pw));
	while (*fmt && is_conv_spec(*fmt, FLAGS_BUF) == -1)
	{
		pos = 0;
		pos += save_width(fmt, &pw[1], ap);
		(void)(fmt[pos] == '.' && (SET_FLAG_ON(flags, POINT)));
		pos += save_precision(fmt + pos, &pw[0], ap);
		pos += save_flag(&flags, fmt + pos);
		if (!pos)
			break ;
		fmt += pos;
	}
	if (((pos = find_flag(FLAGS_BUF, fmt, 1)) != -1) && fmt++)
		*nbr += g_router[pos](ap, flags, pw[0], pw[1]);
	if (*fmt == '%' || *fmt == '{')
		return (flag_scope(nbr, fmt + 1, ap));
	return (fmt);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		nbr;
	char	*fmt;
	char	*fmt_cpy;

	nbr = 0;
	va_start(ap, format);
	fmt = ft_strdup(format);
	fmt_cpy = fmt;
	while (*fmt)
	{
		fmt += set_color(fmt);
		if ((*fmt == '%' && *(++fmt)) && *fmt != '%')
			fmt = flag_scope(&nbr, fmt, ap);
		if (*fmt)
			nbr += write(1, fmt++, 1);
	}
	ft_strdel(&fmt_cpy);
	va_end(ap);
	return (nbr);
}

int (*g_router[12])(va_list, int, int, int) =
{
	ft_putc, \
	ft_puts, \
	ft_putptr, \
	ft_putdnbr, \
	ft_putdnbr, \
	ft_putonbr, \
	ft_putunbr, \
	ft_putxnbr, \
	ft_putbxnbr, \
	ft_putfnbr, \
	ft_putenbr, \
	ft_putgnbr, \
};
