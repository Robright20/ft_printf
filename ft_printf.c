/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 14:51:50 by fokrober          #+#    #+#             */
/*   Updated: 2019/09/29 21:39:22 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(int (*router[12])(int, int, int, va_list))
{
	router[0] = ft_putchar;
	router[1] = ft_putstr;
	router[2] = ft_putdnbr;
	router[3] = ft_putdnbr;
	router[4] = ft_putnbr;
	router[5] = ft_putonbr;
	router[6] = ft_putunbr;
	router[7] = ft_putxnbr;
	router[8] = ft_putxnbr;
	router[9] = ft_putfnbr;
	router[10] = ft_putenbr;
	router[11] = ft_putgnbr;
}

int		ft_printf(const char restrict *fmt, ...)
{
	va_list	ap;
	va_list	ap2;
	int		(*router[12])(int, int, int, va_list);
	int		nbr;
	int		flags;
	int		width;
	int		precision;

	nbr = 0;
	init(router);
	va_start(ap, fmt);
	va_copy(ap2, ap);
	while (*fmt)
	{
		fmt += set_color(fmt);
		if ((*fmt == '%' && *(++fmt)) && *fmt == '%')
		{
			va_argnth(ap, fmt);
			while (*fmt && !is_conv_spec(*fmt, FLAG_BUF))
			{
				fmt += save_width(fmt, &width, ap, ap2);
				fmt += save_precision(fmt, &precision, ap, ap2);
				fmt += save_flag(&flags, fmt);
			}
			nbr += router[ft_strnchr(FLAG_BUF, *fmt)](flags, width, precision, ap);
		}
		ft_putchar(*format);
		nbr++;
	}
	return (nbr);
}
