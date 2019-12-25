/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 05:38:31 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/25 22:50:18 by mzaboub          ###   ########.fr       */
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
   int		main()
   {
   static unsigned int		mx_u = 235;
   static long double			mx_Lf = 0.375l;
   static double				mx_f = 0.625;
   static long				mx_li =  4223372036854775800;
   static long long			mx_lli = 3223372036654775200;
   static char				mx_c = 'G';
   static short				mx_hi = -3244;
   static char				mx_hhi = 'F';
   static char			   *mx_s = "Hello, World!";
   static int					mx_i = 42;

   printf("  %Lf    %p    %i    %li    %lli    %s  ", mx_Lf, &mx_i, mx_i, mx_li, mx_lli, mx_s);
   printf("\n==============================\n");
   ft_printf("[%p]\n", &mx_i);
   ft_printf("  %Lf   %i    %li    %lli    %s  ", mx_Lf, mx_i, mx_li, mx_lli, mx_s);
   printf("==============================\n");
   ft_printf("  %Lf    %p    %i    %li    %lli    %s  ", mx_Lf, &mx_i, mx_i, mx_li, mx_lli, mx_s);
   return (0);
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
   static unsigned long		ul_pos_1 = 22337203685477;
   static long		l_pos_1 = 22337203685477;
   static unsigned int		ui_pos_1 = 878023;
   static unsigned short		ush_pos_1 = 3047;
   static long long	 ll_neg_1 = -22337203685477;
   static short		sh_pos_1 = 3047, sh_neg_1 = -8875;
   static unsigned long long	ull_pos_1 = 22337203685477;


   printf("%s%hihello%-17.14llu%lli%08hu%s%17ssomestuff%s%hi%i%.24lu%llu%u%.2s%li","abc",sh_neg_1, ull_pos_1,ll_neg_1,ush_pos_1,"wassup","nope","",(short)32767,0,ul_pos_1,0ull,ui_pos_1,"notall",l_pos_1);
   printf("\n");
   ft_printf("%s%hihello%-17.14llu%lli%08hu%s%17ssomestuff%s%hi%i%.24lu%llu%u%.2s%li","abc",sh_neg_1, ull_pos_1,ll_neg_1,ush_pos_1,"wassup","nope","",(short)32767,0,ul_pos_1,0ull,ui_pos_1,"notall",l_pos_1);
   printf("\n-------------------------- \n");
   printf("[%17ssomestuff]\n", "nope");
   ft_printf("[%17ssomestuff]\n", "nope");

   printf("\n-------------------------- \n");
   printf("[%17stsomestuff]\n", "nope");
   ft_printf("[%17stsomestuff]\n", "nope");

   printf("\n-------------------------- \n");
   printf("[%17ss]\n", "nope");
   ft_printf("[%17ss]\n", "nope");
   printf("\n-------------------------- \n");
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
	SET_FLAG_ON(flags, POINTER);
	SET_FLAG_ON(flags, HASH);
	SET_FLAG_ON(flags, LLONG);

	return (ft_putxnbr(ap, flags, precision, width));
}
/*
int		main(void)
{
	printf("[%%]\n");
 ft_printf("[%%]\n");
	printf("[%5%]\n");
 ft_printf("[%5%]\n");
	return (0);
}
*/
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
	/*
	ft_putstr("-------------------------\n");
	ft_putstr("ft_putgnbr\n");
	ft_putstr("-------------------------\n");
	ft_putstr("flags status\n");
	printbits(&flags, 4);
	printf("width %d\tprecision %d\n", width, precision);
	*/
	write(1, "[ggg]", 5);
	va_arg(ap, void *);
	return (0);
}
