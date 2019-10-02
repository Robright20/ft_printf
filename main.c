/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 23:00:13 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/02 02:24:47 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		test(char *fmt, ...)
{
	va_list	ap;
	va_list ap2;
	int		precision;
//	int		width;

	precision = 0;
	va_start(ap, fmt);
	va_copy(ap2, ap);
	printf("retour %d\n", save_precision(fmt, &precision, ap, ap2));
	printf("precision = %d\n", precision);
	va_end(ap);
	return (0);
}

int		main(void)
{
	test(".*0", 10);
	printf("%.2*d", 4, 3);
	return (0);
}
