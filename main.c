/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 05:38:31 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/25 18:11:40 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>
#include <locale.h>

/*
int		main(void)
{
	int		ret1;
	int		ret2;

	ret1 = ft_printf("{red}bonjour{eoc} [%+05.3d]\n", 10);
	ret2 = printf("bonjour [%+05.3d]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%+0.3d]\n", 10);
	ret2 = printf("bonjour [%+0.3d]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%0+.3d]\n", 10);
	ret2 = printf("bonjour [%0+.3d]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%0+.3x]\n", 10);
	ret2 = printf("bonjour [%0+.3x]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);
	ret1 = ft_printf("{red}bonjour{eoc} [%#0+.3x]\n", 10);
	ret2 = printf("bonjour [%#0+.3x]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);
	ret1 = ft_printf("{red}bonjour{eoc} [%0+.3X]\n", 10);
	ret2 = printf("bonjour [%0+.3X]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);
	ret1 = ft_printf("{red}bonjour{eoc} [%0'.3u]\n", 10);
	ret2 = printf("bonjour [%0+'.3u]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);
	ret1 = ft_printf("{red}bonjour{eoc} [%0'.3o]\n", 10000);
	ret2 = printf("bonjour [%0+'.3o]\n", 10000);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%#0'.3o]\n", 10000);
	ret2 = printf("bonjour [%#0+'.3o]\n", 10000);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%#010.3o]\n", 10000);
	ret2 = printf("bonjour [%#010.3o]\n", 10000);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%010.3o]\n", 10000);
	ret2 = printf("bonjour [%010.3o]\n", 10000);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%0'10.3o]\n", 10000);
	ret2 = printf("bonjour [%0'10.3o]\n", 10000);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%010d]\n", 10000);
	ret2 = printf("bonjour [%010d]\n", 10000);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%010hd]\n", 10000);
	ret2 = printf("bonjour [%010hd]\n", 10000);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%010hd]\n", 10);
	ret2 = printf("bonjour [%010hd]\n", 10);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);

	ret1 = ft_printf("{red}bonjour{eoc} [%0-'10.3o]\n", 10000);
	ret2 = printf("bonjour [%0-'10.3o]\n", 10000);
	printf("ret1 [%d]\nret2 [%d]\n", ret1, ret2);
	ret2 = 0;
	printbits(&ret2, 4);
	SET_FLAG_ON(ret2, 10);
	SET_FLAG_ON(ret2, 5);
	printbits(&ret2, 4);
	SET_FLAG_OFF(ret2, 5);
	SET_FLAG_OFF(ret2, 5);
	printbits(&ret2, 4);
	setlocale(LC_NUMERIC, "");
	ret1 = ft_printf("{red}bonjour{eoc} [%1$*2$'0d]\n", 12345678, 10);
*/



//	printf("printf    [%010c];\n", 'm');
//	printf("printf    [%.10c];\n", 'm');
//	printf("printf    [%7.3c];\n", 'm');
//	printf("printf    [%-.7c];\n", 'm');
//	printf("printf    [% c];\n", 'm');
//	printf("printf    [%+c];\n", 'm');

//	printf("printf    [%10c];\n", 'm');
// ft_printf("printf    [%10c];\n", 'm');
//    printf("printf    [%-7c];\n", 'm');
// ft_printf("printf    [%-7c];\n", 'm');
//    printf("printf    [%c];\n", 'm');
// ft_printf("printf    [%c];\n", 'm');

/*
int	main()
{

printf("---1--------------\n");
 	printf("printf       [%f];\n", 573.924);
 ft_printf("ft_printf    [%f];\n", 573.924);


printf("---1--------------\n");
 	printf("printf       [%f];\n", -123456789.);
 ft_printf("ft_printf    [%f];\n", -123456789.);

printf("---2--------------\n");
 	printf("printf       [%f];\n", -1234.56789);
 ft_printf("ft_printf    [%f];\n", -1234.56789);

printf("---3--------------\n");
 	printf("printf       [%f];\n", -1234.00);
 ft_printf("ft_printf    [%f];\n", -1234.00);

printf("---4--------------\n");
	printf("printf       [%f];\n", -123000.00);
 ft_printf("ft_printf    [%f];\n", -123000.00);

printf("---5--------------\n");
 	printf("printf       [%f];\n", -120000000000.);
 ft_printf("ft_printf    [%f];\n", -120000000000.);

printf("---6--------------\n");
	printf("printf       [%f];\n", -000000000.);
 ft_printf("ft_printf    [%f];\n", -000000000.);
 
printf("---7--------------\n");
 	printf("printf       [%f];\n", -000.001);
 ft_printf("ft_printf    [%f];\n", -000.001);

printf("---8--------------\n");
	printf("printf       [%f];\n", -123400000.56789);
 ft_printf("ft_printf    [%f];\n", -123400000.56789);

printf("---9--------------\n");
	printf("printf       [%.f];\n", -123400000.00);
 ft_printf("ft_printf    [%.f];\n", -123400000.00);

printf("---10-------------\n");
	printf("printf       [%.f];\n", -00000.00);
 ft_printf("ft_printf    [%.f];\n", -00000.00);

printf("---11-------------\n");
	printf("printf       [%#.f];\n", 1234.00);
 ft_printf("ft_printf    [%#.f];\n", 1234.00);

printf("---12-------------\n");
	printf("printf       [%#.0f];\n", 1234.00);
 ft_printf("ft_printf    [%#.0f];\n", 1234.00);

printf("---13-------------\n");
	printf("printf       [%9.-5f];\n", 1234.00);
 ft_printf("ft_printf    [%9.-5f];\n", 1234.00);

printf("---14-------------\n");
	printf("printf       [%9.*f];\n", 13, 1234.00);
 ft_printf("ft_printf    [%9.*f];\n", 13, 1234.00);

printf("---15-------------\n");
	printf("printf       [%20f];\n", 1234.00);
 ft_printf("ft_printf    [%20f];\n", 1234.00);

printf("---16-------------\n");
	printf("printf       [%012f];\n", 1234.00);
 ft_printf("ft_printf    [%012f];\n", 1234.00);

printf("---17-------------\n");
	printf("printf       [%-012f];\n", 1234.00);
 ft_printf("ft_printf    [%-012f];\n", 1234.00);

printf("---18-------------\n");
	printf("printf       [%- 013f];\n", 1234.00);
 ft_printf("ft_printf    [%- 013f];\n", 1234.00);

printf("---19-------------\n");
	printf("printf       [%+ 20f];\n", 1234.00);
 ft_printf("ft_printf    [%+ 20f];\n", 1234.00);

printf("---20-------------\n");
	printf("printf       [%9.*f];\n", 13, 1234.00);
 ft_printf("ft_printf    [%9.*f];\n", 13, 1234.00);

printf("---21-------------\n");
	printf("printf       [%*f];\n", 13, 1234.00);
 ft_printf("ft_printf    [%*f];\n", 13, 1234.00);

printf("---22-------------\n");
	printf("printf       [%*.*f];\n", 13, 9, 1234.00);
 ft_printf("ft_printf    [%*.*f];\n", 13, 9, 1234.00);

printf("---23-------------\n");
	printf("printf       [%9.f];\n", 1234.00);
 ft_printf("ft_printf    [%9.f];\n", 1234.00);

printf("---24-------------\n");
	printf("printf       [%9.*f];\n", -20, 1234.00);
 ft_printf("ft_printf    [%9.*f];\n", -20, 1234.00);
printf("-----------------\n");
*/
/*
printf("/--------1---------/\n");

 	printf("printf    [hello [%e];\n", -123456789.);
 ft_printf("printf    [hello [%e];\n", -123456789.);
printf("---------2--------\n");
 	printf("printf    [hello [%.e];\n", -123456789.);
 ft_printf("printf    [hello [%.e];\n", -123456789.);
printf("---------3--------\n");
 	printf("printf    [hello [%20e];\n", -123456789.);
 ft_printf("printf    [hello [%20e];\n", -123456789.);
printf("---------4--------\n");
 	printf("printf    [hello [%.13e];\n", -123456789.);
 ft_printf("printf    [hello [%.13e];\n", -123456789.);
printf("---------5--------\n");
 	printf("printf    [hello [%.e];\n", -1234.56789);
 ft_printf("printf    [hello [%.e];\n", -1234.56789);
printf("---------6--------\n");
 	printf("printf    [hello [%e];\n", 0.);
 ft_printf("printf    [hello [%e];\n", 0.);
printf("---------7--------\n");
 	printf("printf    [hello [%030e];\n", 0.);
 ft_printf("printf    [hello [%030e];\n", 0.);
 
printf("---------8--------\n");
 	printf("printf       [hello [%20e];\n", 0.);
 ft_printf("ft_printf    [hello [%20e];\n", 0.);
printf("---------9--------\n");
 	printf("printf       [hello [%-030e];\n", 111999.666);
 ft_printf("ft_printf    [hello [%-030e];\n", 111999.666);

printf("---------10--------\n");
 	printf("printf       [hello [%- 30e];\n", 111999.666);
 ft_printf("ft_printf    [hello [%- 30e];\n", 111999.666);
printf("----------11-------\n");
 	printf("printf       [hello [%+30.e];\n", 111999.666);
 ft_printf("ft_printf    [hello [%+30.e];\n", 111999.666);

printf("-----------12------\n");
 	printf("printf       [hello [%30.1e];\n", 111999.666);
 ft_printf("ft_printf    [hello [%30.1e];\n", 111999.666);

printf("-----------13------\n");
 	printf("printf       [hello [%+7.*e];\n", -15, 123.5);
 ft_printf("ft_printf    [hello [%+7.*e];\n", -15, 123.5);
 	printf("ft_printf    [hello [%+7.*d];\n", -15, 123);
 ft_printf("ft_printf    [hello [%+7.*d];\n", -15, 123);

printf("-----------14------\n");
 	printf("printf       [hello [%+7.*e];\n", 15, 123.5);
 ft_printf("ft_printf    [hello [%+7.*e];\n", 15, 123.5);

printf("----------15-------\n");
 	printf("printf       [hello [% -10.*e];\n", -15, 111999.666);
 ft_printf("ft_printf    [hello [% -10.*e];\n", -15, 111999.666);

printf("----------16-------\n");
 	printf("printf       [hello [%023.1e];\n", 111999.666);
 ft_printf("ft_printf    [hello [%023.1e];\n", 111999.666);

printf("----------17-------\n");
 	printf("printf       [hello [%.8e];\n", 111999.666);
 ft_printf("ft_printf    [hello [%.8e];\n", 111999.666);

printf("----------18-------\n");
 	printf("printf       [hello [%e];\n", 0./0);
 ft_printf("ft_printf    [hello [%e];\n", 0./0);
	printf("/-----------------/\n");

printf("----------19-------\n");
 	printf("printf       [hello [%e];\n", 10./0);
 ft_printf("ft_printf    [hello [%e];\n", 10./0);

printf("----------20-------\n");
 	printf("printf       [hello [%0.8e];\n", 10./0);
 ft_printf("ft_printf    [hello [%0.8e];\n", 10./0);

printf("----------20-------\n");
 	printf("printf       [hello [%09e];\n", 10./0);
 ft_printf("ft_printf    [hello [%09e];\n", 10./0);

printf("----------20-------\n");
 	printf("printf       [hello [%10.8e];\n", 10./0);
 ft_printf("ft_printf    [hello [%10.8e];\n", 10./0);

printf("----------21-------\n");
 	printf("printf       [hello [%0.8e];\n", 0./0);
 ft_printf("ft_printf    [hello [%0.8e];\n", 0./0);

printf("----------22-------\n");
 	printf("printf       [hello [%09e];\n", 0./0);
 ft_printf("ft_printf    [hello [%09e];\n", 0./0);

printf("----------23-------\n");
 	printf("printf       [hello [%10.8e];\n", 0./0);
 ft_printf("ft_printf    [hello [%10.8e];\n", 0./0);


printf("/-----------------/\n");

	return (0);
}
*/
/*
int		main()
{
 	printf("printf       [hello [% 05.0f];\n", 7.3);
 ft_printf("ft_printf    [hello [% 05.0f];\n", 7.3);

 	printf("printf       [hello [% 05.0f];\n", -7.3);
 ft_printf("ft_printf    [hello [% 05.0f];\n", -7.3);
printf("-------------------------- \n");
 	printf("printf       [hello [% 05.1f];\n", 7.3);
 ft_printf("ft_printf    [hello [% 05.1f];\n", 7.3);

 	printf("printf       [hello [% 05.1f];\n", -7.3);
 ft_printf("ft_printf    [hello [% 05.1f];\n", -7.3);
}
*/
/*
int		main(void)
{

printf("-------------------------- \n");
 	printf("printf       [%s];\n", "bla bla");
 ft_printf("ft_printf    [%s];\n", "bla bla");

printf("-------------------------- \n");
 	printf("printf       [%s];\n", NULL);
 ft_printf("ft_printf    [%s];\n", NULL);

printf("-------------------------- \n");
 	printf("printf       [%10s];\n", NULL);
 ft_printf("ft_printf    [%10s];\n", NULL);

printf("-------------------------- \n");
 	printf("printf       [%.3s];\n", NULL);
 ft_printf("ft_printf    [%.3s];\n", NULL);

printf("-------------------------- \n");
 	printf("printf       [%.5s];\n", "bla bla");
 ft_printf("ft_printf    [%.5s];\n", "bla bla");

printf("-------------------------- \n");
 	printf("printf       [% .1s];\n", "bla bla");
 ft_printf("ft_printf    [% .1s];\n", "bla bla");

printf("-------------------------- \n");
 	printf("printf       [% 010.0s];\n", "bla bla");
 ft_printf("ft_printf    [% 010.0s];\n", "bla bla");

printf("-------------------------- \n");
 	printf("printf       [% 0.0s];\n", "bla bla");
 ft_printf("ft_printf    [% 0.0s];\n", "bla bla");

printf("-------------------------- \n");
 	printf("printf       [%02.2s];\n", "-100");
 ft_printf("ft_printf    [%02.2s];\n", "-100");
printf("-------------------------- \n");
	return (0);
}
*/
/*
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
*/
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

/*
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
*/
/*
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
*/
/*
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
*/
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
