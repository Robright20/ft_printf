/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 05:38:31 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/13 06:19:03 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putc(va_list ap, int flags, int precision, int width)
{
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putchar\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	(void)ap;
	return (0);
}
int		ft_putptr(va_list ap, int flags, int precision, int width)
{
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putptr\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	(void)ap;
	return (0);
}


int		ft_puts(va_list ap, int flags, int precision, int width)
{
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putstr\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	(void)ap;
	return (0);
}

int		ft_putfnbr(va_list ap, int flags, int precision, int width)
{
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putfnbr\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	(void)ap;
	return (0);
}

int		ft_putenbr(va_list ap, int flags, int precision, int width)
{
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putenbr\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	(void)ap;
	return (0);
}

int		ft_putgnbr(va_list ap, int flags, int precision, int width)
{
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putgnbr\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	(void)ap;
	return (0);
}

int		main(void)
{
	int		ret1;
	int		ret2;
/*
	ret1 = ft_printf("{red}bonjour{eoc} [%+05.3d]\n", 10);
	ret2 = printf("bonjour [%+05.3d]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%+0.3d]\n", 10);
	ret2 = printf("bonjour [%+0.3d]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%0+.3d]\n", 10);
	ret2 = printf("bonjour [%0+.3d]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);*/

	ret1 = ft_printf("{red}bonjour{eoc} [%0+.3x]\n", 10);
	ret2 = printf("bonjour [%0+.3x]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);
	return (0);
}
