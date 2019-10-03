/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 14:51:50 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/03 17:36:47 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(int (*router[11])(int, int, int, va_list))
{
	router[0] = ft_putc;
	router[1] = ft_puts;
	router[2] = ft_putdnbr;
	router[3] = ft_putdnbr;
	router[4] = ft_putonbr;
	router[5] = ft_putunbr;
	router[6] = ft_putxnbr;
	router[7] = ft_putxnbr;
	router[8] = ft_putfnbr;
	router[9] = ft_putenbr;
	router[10] = ft_putgnbr;
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
		while (--nbr)
			va_arg(ap, void *);
		return (++i);
	}
	return (0);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	va_list	ap2;
	int		(*router[11])(int, int, int, va_list);
	int		nbr;
	int		flags;
	int		width;
	int		precision;
	char	*fmt;
	char	*fmt_cpy;
	int		pos;

	nbr = 0;
	init(router);
	va_start(ap, format);
	va_copy(ap2, ap);
	fmt = ft_strdup(format);
	fmt_cpy = fmt;
	while (*fmt)
	{
		fmt += set_color(fmt);
		if ((*fmt == '%' && *(++fmt)) && *fmt != '%')
		{
			nbr += va_argnth(ap, fmt);
			while (*fmt && is_conv_spec(*fmt, FLAGS_BUF) == -1)
			{
				fmt += save_width(fmt, &width, ap, ap2);
				fmt += save_precision(fmt, &precision, ap, ap2);
				fmt += save_flag(&flags, fmt);
			}
			if ((pos = find_flag(FLAGS_BUF, fmt, 1)) != -1)
				(void)((nbr += router[pos](flags, width, precision, ap)) && fmt++);
		}
		if (*fmt)
			nbr += write(1, fmt++, 1);
	}
	free(fmt_cpy);
	return (nbr);
}
