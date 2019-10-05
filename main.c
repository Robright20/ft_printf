/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 23:00:13 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/05 18:08:14 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putc(int flags, int width, int precision, va_list ap)
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
int		ft_putptr(int flags, int width, int precision, va_list ap)
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


int		ft_puts(int flags, int width, int precision, va_list ap)
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

int		ft_putdnbr(int flags, int width, int precision, va_list ap)
{
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putdnbr\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	(void)ap;
	return (0);
}

int		ft_putonbr(int flags, int width, int precision, va_list ap)
{
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putonbr\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	(void)ap;
	return (0);
}

int		ft_putunbr(int flags, int width, int precision, va_list ap)
{
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putunbr\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	(void)ap;
	return (0);
}

int		ft_putxnbr(int flags, int width, int precision, va_list ap)
{
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putxnbr\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	(void)ap;
	return (0);
}

int		ft_putfnbr(int flags, int width, int precision, va_list ap)
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

int		ft_putenbr(int flags, int width, int precision, va_list ap)
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

int		ft_putgnbr(int flags, int width, int precision, va_list ap)
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

int		save_precision_test(char *fmt, ...)
{
	va_list	ap;
	va_list ap2;
	int		precision;
//	int		width;

	precision = 0;
	va_start(ap, fmt);
	va_copy(ap2, ap);
	printf("retour %d\n", save_precision(fmt, &precision, ap));
	printf("precision = %d\n", precision);
	printf("va apres %d\n", va_arg(ap, int));
	va_end(ap);
	return (0);
}

int		save_width_test(char *fmt, ...)
{
	va_list	ap;
	va_list ap2;
	int		width;

	width = 0;
	va_start(ap, fmt);
	va_copy(ap2, ap);
	printf("retour %d\n", save_width(fmt, &width, ap));
	printf("width = %d\n", width);
	printf("va apres %d\n", va_arg(ap, int));
	va_end(ap);
	return (0);
}

int		save_flag_test(char *fmt)
{
	int		flags;
	printf("sflagtest ret %d", save_flag(&flags, fmt));
	printf("\tsflagtest flags %d\n", flags);
	return (0);
}

int		init_test(char *fmt, ...)
{
	va_list ap;
	int		(*router[12])(int, int, int, va_list);
	
	va_start(ap, fmt);
	init(router);
	router[0](0, 1, 2, ap);
	va_end(ap);
	return (0);
}

int		main(void)
{
	/* precision test
	save_precision_test(".10", 10, 4);
	printf("printf %.*2$d\n", 10, 4);
	save_precision_test(".*0$", 10, 5);
	printf("printf bihavior : %.*0$f;\n", 2, 9.54321);*/
	save_precision_test(".*3$", 2, 9.54321);
	printf("printf bihavior : %.*3$f;\n", 2, 9.54321);
	printf("7 precision should be : 6 (the default value)\n------------\n");
	/* width test
	 *
	 * printf("ret %d\n", save_width_test("*0$", 4));
	 * printf("ret %d\n", printf("width expect %*0$ %d\n", 4, 6));
	 */

	/* find flag test
	 * printf("fflag ret %d\n", find_flag(FLAGS_BUF, "hh", 2));
	 */

	/*save_flag test
	 * save_flag_test("hh");
	int		flags = 0;
	printf("%d\n", find_flag(FLAGS_BUF, "$", 1));
	SET_FLAG_ON(flags, 27);
	printbits(&flags, 4);
	flags = 0;
	printf("%d\n", find_flag(FLAGS_BUF, "-", 1));
	SET_FLAG_ON(flags, 14);
	printbits(&flags, 4);*/

	/*set_color test
	 * printf("set color test\nret %d\n", set_color("{red}"));
	 * printf("set color test\nret %d\n", set_color("{eoc}"));
	 * printf("set color test\nret %d\n", set_color("{eoc"));*/

	/* init test
	init_test("bonjour", 1, 3);*/

	/*backbone test
	 * 
	printf("ret %d\n", ft_printf("bonjour \n%10td\t", 244));
	printf("ret %d\n", ft_printf("bonjour \n%10hhhd\t", 244));
	printf("ret %d\n", ft_printf("bonjour \n%10hhd\t", 244));
	printf("ret %d\n", ft_printf("bonjour \n%10hhu\t", 244));
	printf("ret %hhhd\n", 2);
	printf("ret %d\n", ft_printf("salut {red"));
	printf("ret %d\n", ft_printf("salut {redi"));
	printf("ret %d\n", ft_printf("salut {redi}"));
	printf("ret %d\n", ft_printf("width test %*0$ %d\n", 4, 6));
	printf("ret %d\n", printf("width expect %*0$ %d\n", 4, 6));
	printf("ret %d\n", ft_printf("prec test %.*0$ %d\n", 4, 6));
	printf("ret %d\n", printf("prec %.*0$ %d\n", 4, 6));
	printf("ret %d\n", ft_printf("acc test %0$ %d\n", 4, 6));
	printf("ret %d\n", printf("acc %0$ %d\n", 4, 6));
	printf("ret %d\n", ft_printf("neg prec test %-1$.-10d\n", 4, 6));
	printf("ret %d\n", printf("neg prec %-1$.-10d\n", 4, 6));
	printf("ret %d\n", printf("neg prec %.-10d\n", 244));
	printf("ret %d\n", ft_printf("neg prec test %.-10d\n", 244));
	printf("ret %d\n", printf("neg prec [%.-10d]\n", 244));
	printf("ret %d\n", ft_printf("neg prec test %.-10d\n", 244));
	printf("ret %d\n", printf("neg prec [%1$%.-10d]\n", 5));
	printf("ret %d\n", ft_printf("neg prec test %1$%.-10d\n", 5));
	printf("ret %d\n", printf("neg prec [%1$.-10d]\n", 5));
	printf("ret %d\n", ft_printf("neg prec test %1$.-10d\n", 5));
	printf("ret %d\n", printf("after? %d%d\n", 5, 4));
	printf("ret %d\n", ft_printf("after? test %d%d\n", 5, 4));
	printf("ret %d\n", ft_printf("bonjour +\n%+++++++++.------10d+\t", 244));
	printf("ret %d\n", ft_printf("bonjour %.d", 244));*/
	return (0);
}
