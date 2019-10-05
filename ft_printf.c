/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 14:51:50 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/05 13:19:18 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(int (*router[12])(int, int, int, va_list))
{
	router[0] = ft_putc;
	router[1] = ft_puts;
	router[2] = ft_putptr;
	router[3] = ft_putdnbr;
	router[4] = ft_putdnbr;
	router[5] = ft_putonbr;
	router[6] = ft_putunbr;
	router[7] = ft_putxnbr;
	router[8] = ft_putxnbr;
	router[9] = ft_putfnbr;
	router[10] = ft_putenbr;
	router[11] = ft_putgnbr;
}

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
	int		(*router[12])(int, int, int, va_list);
	int		flags;
	int		pw[2];
	int		pos;

	*nbr += va_argnth(ap, fmt);
	init(router);
	flags = 0;
	while (*fmt && is_conv_spec(*fmt, FLAGS_BUF) == -1)
	{
		pos = 0;
		pos += save_width(fmt, &pw[1], ap);
		pos += save_precision(fmt, &pw[0], ap);
		pos += save_flag(&flags, fmt);
		if (!pos)
			break ;
		fmt += pos;
	}
	if ((pos = find_flag(FLAGS_BUF, fmt, 1)) != -1)
		(void)((*nbr += router[pos](flags, pw[1], pw[0], ap)) && fmt++);
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
