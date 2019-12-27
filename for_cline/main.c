/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 05:38:31 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/26 19:04:07 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>
#include <locale.h>



int	main(void)
{

//
	printf("-----------------\n");

	printf("/--------1---------/\n");
//	printf("printf    [hello [%e];\n", -123456789.);
	ft_printf("printf    [hello [%e];\n", -123456789.);

	printf("---------2--------\n");
//	printf("printf    [hello [%.e];\n", -123456789.);
	ft_printf("printf    [hello [%.e];\n", -123456789.);

	printf("---------3--------\n");
//	printf("printf    [hello [%20e];\n", -123456789.);
	ft_printf("printf    [hello [%20e];\n", -123456789.);

	printf("---------4--------\n");
//	printf("printf    [hello [%.13e];\n", -123456789.);
	ft_printf("printf    [hello [%.13e];\n", -123456789.);

	printf("---------5--------\n");
//	printf("printf    [hello [%.e];\n", -1234.56789);
	ft_printf("printf    [hello [%.e];\n", -1234.56789);

	printf("---------6--------\n");
//	printf("printf    [hello [%e];\n", 0.);
	ft_printf("printf    [hello [%e];\n", 0.);

	printf("---------7--------\n");
//	printf("printf    [hello [%030e];\n", 0.);
	ft_printf("printf    [hello [%030e];\n", 0.);

	printf("---------8--------\n");
//	printf("printf       [hello [%20e];\n", 0.);
	ft_printf("ft_printf    [hello [%20e];\n", 0.);

	printf("---------9--------\n");
//	printf("printf       [hello [%-030e];\n", 111999.666);
	ft_printf("ft_printf    [hello [%-030e];\n", 111999.666);

	printf("---------10--------\n");
//	printf("printf       [hello [%- 30e];\n", 111999.666);
	ft_printf("ft_printf    [hello [%- 30e];\n", 111999.666);

	printf("----------11-------\n");
//	printf("printf       [hello [%+30.e];\n", 111999.666);
	ft_printf("ft_printf    [hello [%+30.e];\n", 111999.666);

	printf("-----------12------\n");
//	printf("printf       [hello [%30.1e];\n", 111999.666);
	ft_printf("ft_printf    [hello [%30.1e];\n", 111999.666);

	printf("-----------13------\n");
//	printf("printf       [hello [%+7.*e];\n", -15, 123.5);
	ft_printf("ft_printf    [hello [%+7.*e];\n", -15, 123.5);

	printf("-----------14------\n");
//	printf("printf       [hello [%+7.*e];\n", 15, 123.5);
	ft_printf("ft_printf    [hello [%+7.*e];\n", 15, 123.5);

	printf("----------15-------\n");
//	printf("printf       [hello [% -10.*e];\n", -15, 111999.666);
	ft_printf("ft_printf    [hello [% -10.*e];\n", -15, 111999.666);

	printf("----------16-------\n");
//	printf("printf       [hello [%023.1e];\n", 111999.666);
	ft_printf("ft_printf    [hello [%023.1e];\n", 111999.666);

	printf("----------17-------\n");
//	printf("printf       [hello [%.8e];\n", 111999.666);
	ft_printf("ft_printf    [hello [%.8e];\n", 111999.666);

	printf("----------18-------\n");
//	printf("printf       [hello [%e];\n", 0./0);
	ft_printf("ft_printf    [hello [%e];\n", 0./0);
	printf("/-----------------/\n");

	printf("----------19-------\n");
//	printf("printf       [hello [%e];\n", 10./0);
	ft_printf("ft_printf    [hello [%e];\n", 10./0);

	printf("----------20-------\n");
//	printf("printf       [hello [%0.8e];\n", 10./0);
	ft_printf("ft_printf    [hello [%0.8e];\n", 10./0);

	printf("----------20-1------\n");
//	printf("printf       [hello [%09e];\n", 10./0);
	ft_printf("ft_printf    [hello [%09e];\n", 10./0);

	printf("----------20-2------\n");
//	printf("printf       [hello [%10.8e];\n", 10./0);
	ft_printf("ft_printf    [hello [%10.8e];\n", 10./0);

	printf("----------21-------\n");
//	printf("printf       [hello [%0.8e];\n", 0./0);
	ft_printf("ft_printf    [hello [%0.8e];\n", 0./0);

	printf("----------22-------\n");
//	printf("printf       [hello [%09e];\n", 0./0);
	ft_printf("ft_printf    [hello [%09e];\n", 0./0);

	printf("----------23-------\n");
//	printf("printf       [hello [%10.8e];\n", 0./0);
	ft_printf("ft_printf    [hello [%10.8e];\n", 0./0);

	printf("----------24-------\n");
//	printf("printf       [hello [%10.8Le];\n", 458.456);
	ft_printf("ft_printf    [hello [%10.8Le];\n", 458.456);

	printf("----------25-------\n");
//	printf("printf       [hello [%10.0Le];\n", 0.00001);
	ft_printf("ft_printf    [hello [%10.0Le];\n", 0.00001);

	printf("----------26-------\n");
	//printf("printf       [hello [%.8Le];\n", LDBL_MAX);
	ft_printf("ft_printf    [hello [%.8Le];\n", LDBL_MAX);

	printf("----------27-------\n");
	//printf("printf       [hello [%#-10Le];\n", 456.13);
	ft_printf("ft_printf    [hello [%#-10Le];\n", 456.13);

	printf("----------28-------\n");
	//printf("printf       [hello [%-019.4Le];\n", 456.13);
	ft_printf("ft_printf    [hello [%-019.4Le];\n", 456.13);

	printf("----------29-------\n");
//	printf("printf       [hello [%'- 8Le];\n", 456.13);
	ft_printf("ft_printf    [hello [%'- 8Le];\n", 456.13);

	printf("----------30-------\n");
//	printf("printf       [hello [%.Le];\n", 456.13);
	ft_printf("ft_printf    [hello [%.Le];\n", 456.13);


	printf("/-----------------/\n");

	return (0);
}

int     ft_putptr(va_list ap, int flags, int precision, int width)
{
	SET_FLAG_ON(flags, POINTER);
	SET_FLAG_ON(flags, HASH);
	SET_FLAG_ON(flags, LLONG);

	return (ft_putxnbr(ap, flags, precision, width));
}
int     ft_putgnbr(va_list ap, int flags, int precision, int width)
{
	/*
	 *     ft_putstr("-------------------------\n");
	 *         ft_putstr("ft_putgnbr\n");
	 *             ft_putstr("-------------------------\n");
	 *                 ft_putstr("flags status\n");
	 *                     printbits(&flags, 4);
	 *                         printf("width %d\tprecision %d\n", width, precision);
	 *                             */
	write(1, "[ggg]", 5);
	va_arg(ap, void *);
	return (0);
}
