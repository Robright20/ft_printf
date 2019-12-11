/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 00:57:56 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/11 23:44:29 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "ft_printf.h"

#include <float.h>
/*
int	main(void)
{
	return (0);
}
*/

/*
** to test the compare function ;
**
** int		main(void)
** {
** 	t_uint32	nb1 = 0XFFFFFF;
** 	t_uint64	nb2 = 0XFFFFFFFFFFFFFFFF;
** 	t_uint64	nb3 = 0XFFFFFFFFFFFFFFF0;
** 
** 	t_bigint	n1;
**    	ft_uint32_to_bigint(nb1, &n1);
** 	t_bigint	n2;
**    	ft_uint64_to_bigint(nb2, &n2);
** 	t_bigint	n3;
**    	ft_uint64_to_bigint(nb3, &n3);
** 	
** 	printf("is nb1 > nb2 ?  : |%d|\n", ft_bigint_compare(n1, n2));
** 	printf("is nb2 > nb1 ?  : |%d|\n", ft_bigint_compare(n2, n1));
** 	printf("is nb2 == nb2 ? : |%d|\n", ft_bigint_compare(n2, n2));
** 	printf("is nb2 > nb3 ?  : |%d|\n", ft_bigint_compare(n2, n3));
** 	
** 	return (0);
** }
*/

/*
** main to check te creation of the big int;
**
** int main(void)
** {
** 	unsigned long long  nbr = (t_uint64)UINT_MAX + (t_uint64)UINT_MAX;
** 	t_bigint nb1;
** 
** 	nb1.tab[0] = 0;
** 	ft_uint64_to_bigint(nbr, &nb1);
** 
** 	printf("nbr == \n");
** 	printbits(&nbr, 8);
** 	
** 	printf("\nnb1 == \n");
** 	printbits(&nb1.tab[1], 4);
** 	printbits(&nb1.tab[0], 4);
** 
** 	return (0);
** }
*/

/*
**  main to test ft_bigint_shiftleft 
**
** int				main(void)
** {
** 	t_uint64	nbr1 = 0XFFFFFF;
** 	t_bigint	nb;
** 
** 	ft_uint64_to_bigint(nbr1, &nb);
** 	printf("before shift;\tnb->length == |%d|\n", nb.length);
** 	printbits(nb.tab, 8);
** 	ft_bigint_shiftleft(&nb, 2);
** 	printf("after shift;\tnb->length == |%d|\n", nb.length);
** 	printbits(nb.tab, 8);
** 	return (0);
** }
*/


/*
** main to test bigint divid ;
** 32900120560 / 10000000000
** 0x5E6A375 / 0X989680
** 
** 
** int						main(void)
** {
** 	t_uint64	bast = 0x5E6A375;
** 	t_uint64	maqam = 0x989680;
** 	t_uint64	newbast;
** 	t_bigint	nb1;
** 	t_bigint	nb2;
** 	t_bigint	dividend;
** 	t_bigint	divisor;
** 
** 	dividend.tab[1] = 0;
** 	dividend.tab[0] = 0;
** 	ft_uint64_to_bigint(bast, &nb1);
** 	ft_uint64_to_bigint(bast, &dividend);
** 	ft_uint64_to_bigint(maqam, &nb2);
** 	ft_uint64_to_bigint(maqam, &divisor);
** 
** 	
** 	t_uint32	q = ft_bigint_divid(&dividend, &divisor);
** 	t_uint32	qq = BigInt_DivideWithRemainder_MaxQuotient9(&nb1, &nb2);
** 
** 
** 	printf ("--------------------------------------------------------------------------\n");
** 	printf("main q == |%d|\tqq == |%d|\tbast/maqam == |%llu|\n", q, qq, bast/maqam); 
** 	printf("dividend->len == |%u|\tnb1->len == |%u|\n", dividend.length, nb1.length);
** 	printf ("--------------------------------------------------------------------------\n");
** 
** 	printf("old bast     == |%llu|\t", bast);
** 	printbits(&bast, 8);
** 
** 	printf("old maqam    == |%llu|\t", maqam);
** 	printbits(&maqam, 8);
** 
** 	newbast = bast - (maqam * q);
** 	printf("new bast     == |%llu|\t", newbast);
** 	printbits(&newbast, 8);
** 
** 	printf("new nb1      == |%llu|\t", ((t_uint64)nb1.tab[1] << 32) | (t_uint64)nb1.tab[0]); 
** 	printbits(&nb1, 8);
** 
** 	printf("new dividend == |%llu|\t", ((t_uint64)dividend.tab[1] << 32) | (t_uint64)dividend.tab[0]);
** 	printbits(&dividend, 8);
** 	printf ("--------------------------------------------------------------------------\n");
** 	return (0);
** }
*/
void	ft_print(char *str, int n)
{
	int i = 0;
	write(1, "{", 1);
	while (i < n)
		write(1, str + i++, 1);
	write(1, "}", 1);
	write(1, "\n", 1);
}

int main(void)
{
//	double nbr = 17976931.3486231570814527423731704356798078632766878171540458953514382464234321326889464;
/*	double nbr1 = -123456;
	double nbr2 = -123.456;
	double nbr3 = -122.5;
	double nbr4 = -4234321326889464.123456789;

	double nbr5 = 0.123;
	double nbr6 = 0.00123;
	double nbr7 = 0.0000000000123;
	double nbr8 = -DBL_MAX;
//	int		w = 67;
	char    str1[500];
	char    str2[500];
	char    str3[500];
	char    str4[500];
	char    str5[500];
	char    str6[500];
	char    str7[500];
	char    str8[500];
//  printf("/--------------------------/\n");
//  printf("nbr == |%lf|\n\n", nbr);
//  printf("/--------------------------/\n");

	//  printf("/==========================/\n");
//	str[0] = ' ';
	printf("/==========================/\n");
	printf("/==========================/\n");
    print_double(nbr1, str1, 500);
	printf("nbr1  == |%.100lf|\n",	nbr1);	printf("str1  == |%s|\n",  		str1);
	printf("/==========================/\n");
    print_double(nbr2, str2, 500);
	printf("nbr2  == |%.100lf|\n",	nbr2);	printf("str2  == |%s|\n",  		str2);
	printf("/==========================/\n");
    print_double(nbr3, str3, 500);
	printf("nbr3  == |%.100lf|\n",	nbr3);	printf("str3  == |%s|\n",  		str3);
	printf("/==========================/\n");
    print_double(nbr4, str4, 500);
	printf("nbr4  == |%.100lf|\n",	nbr4);	printf("str4  == |%s|\n",  		str4);
	printf("/==========================/\n");
	printf("/==========================/\n");
    print_double(nbr5, str5, 500);
	printf("nbr5  == |%.100lf|\n",	nbr5);	printf("str5  == |%s|\n",  		str5);
	printf("/==========================/\n");
    print_double(nbr6, str6, 500);
	printf("nbr6  == |%.100lf|\n",	nbr6);	printf("str6  == |%s|\n",  		str6);
	printf("/==========================/\n");
    print_double(nbr7, str7, 500);
	printf("nbr7  == |%.100lf|\n",	nbr7);	printf("str7  == |%s|\n",  		str7);
	printf("/==========================/\n");
    print_double(nbr8, str8, 500);
	printf("nbr8  == |%.100lf|\n",	nbr8);	printf("str8  == |%s|\n",  		str8);
*/
/*
	long double nb1 = 11.11;
	long double nb2 = 123456789.123456789;
	long double nb3 = 0.123456;
	long double nb4 = 0.0000000000987654321;
	long double nb5 = 112233;
//	long double nb6 = DBL_MIN;

	char	*buff1 = malloc(sizeof(char) * 16390);
	char	*buff2 = malloc(sizeof(char) * 16390);
	char	*buff3 = malloc(sizeof(char) * 16390);
	char	*buff4 = malloc(sizeof(char) * 16390);
	char	*buff5 = malloc(sizeof(char) * 16390);
//	char	*buff6 = malloc(sizeof(char) * 16390);

	printf("/==========================/\n");
    print_long_double(nb1, buff1, 1000);
	printf("nb1    == |%.100Lf|\n",	nb1);	printf("buff1  == |%s|\n",  	buff1);
	free(buff1);

	printf("/==========================/\n");
    print_long_double(nb2, buff2, 1000);
	printf("nb2    == |%.100Lf|\n",	nb2);	printf("buff2  == |%s|\n",  	buff2);
	free(buff2);

	printf("/==========================/\n");
    print_long_double(nb3, buff3, 1000);
	printf("nb3    == |%.100Lf|\n",	nb3);	printf("buff3  == |%s|\n",  	buff3);
	free(buff3);

	printf("/==========================/\n");
    print_long_double(nb4, buff4, 1000);
	printf("nb4    == |%.100Lf|\n",	nb4);	printf("buff4  == |%s|\n",  	buff4);
	free(buff4);

	printf("/==========================/\n");
    print_long_double(nb5, buff5, 1000);
	printf("nb5    == |%.100Lf|\n",	nb5);	printf("buff5  == |%s|\n",  	buff5);
	free(buff5);

	printf("/==========================/\n");
    print_long_double(nb6, buff6, 16390);
	printf("nb6    == |%.16385Lf|\n",	nb6);
	printf("buff6  == |%s|\n",  	buff6);
	free(buff6);
*/
	printf("/==========================/\n");

	long double nbr1 = 11.11;
	long double nbr2 = 123456789.123456789;
	long double nbr3 = 0.123456;
	long double nbr4 = 0.0000000000987654321;
//	long double nbr5 = LDBL_MIN;
//	long double nbr6 = LDBL_MAX;

	t_buffer	buffer1;
	t_buffer	buffer2;
	t_buffer	buffer3;
	t_buffer	buffer4;
//	t_buffer	buffer5;
//	t_buffer	buffer6;

	buffer1.buff = malloc(sizeof(char) * 16390);
	buffer2.buff = malloc(sizeof(char) * 16390);	
	buffer3.buff = malloc(sizeof(char) * 16390);
	buffer4.buff = malloc(sizeof(char) * 16390);
//	buffer5.buff = malloc(sizeof(char) * 16390);
//	buffer6.buff = malloc(sizeof(char) * 16390);	
	
 	printf("/==========================/\n");
 	buffer1.max_len = 16389;
 	buffer1.precision = 100;
 	buffer1.width = 120;
 	buffer1.flags = 1;
	//printf("[buffer1->precision 1 = %d]\n", buffer1.precision);
    print_long_double(nbr1, &buffer1);
	printf("nb1    == |%120.100Lf|\n",	nbr1);	printf("buff1  == |%s|\n",  	buffer1.buff);
	free(buffer1.buff);

	printf("/==========================/\n");
	buffer2.max_len = 16389;
	buffer2.precision = 100;
	buffer2.width = 120;
	buffer2.flags = 1;
//	printf("[buffer1->precision 1 = %d]\n", buffer2.precision);
    print_long_double(nbr2, &buffer2);
	printf("nb2    == |%120.100Lf|\n",	nbr2);	printf("buff2  == |%s|\n",  	buffer2.buff);
	free(buffer2.buff);

	printf("/==========================/\n");
	buffer3.max_len = 16389;
	buffer3.precision = 100;
	buffer3.width = 120;
	buffer3.flags = 1;
    print_long_double(nbr3, &buffer3);
	printf("nb3    == |%120.100Lf|\n",	nbr3);	printf("buff3  == |%s|\n",  	buffer3.buff);
	free(buffer3.buff);

	printf("/==========================/\n");
	buffer4.max_len = 16389;
	buffer4.precision = 100;
	buffer4.width = 120;
	buffer4.flags = 1;
    print_long_double(nbr4, &buffer4);
	printf("nb4    == |%120.100Lf|\n",	nbr4);	printf("buff4  == |%s|\n",  	buffer4.buff);
	free(buffer4.buff);

//	printf("/==========================/\n");
//	buffer5.max_len = 16389;
//	buffer5.precision = 16385;
//	buffer5.width = 0;
//	buffer5.flags = 1;
//  print_long_double(nbr5, &buffer5);
//	printf("nb5    == |%.16385Lf|\n",	nbr5);	printf("buff5  == |%s|\n",  	buffer5.buff);
//	free(buffer5.buff);

//	printf("/==========================/\n");
//	buffer6.max_len = 16389;
//	buffer6.precision = 16385;
//	buffer6.width = 0;
//	buffer6.flags = 1;
//	print_long_double(nbr6, &buffer6);
//	printf("nb6    == |%.16385Lf|\n",	nbr6);	printf("buff6  == |%s|\n",  	buffer6.buff);
//	free(buffer6.buff);

	printf("/==========================/\n\n\n\n");

	double nb1 = 11.11;
	double nb2 = 123456789.123456789;
	double nb3 = 0.123456;
	double nb4 = 0.0000000000987654321;
//	double nb5 = DBL_MIN;
//	double nb6 = DBL_MAX;

	t_buffer	buff1;
	t_buffer	buff2;
	t_buffer	buff3;
	t_buffer	buff4;
//	t_buffer	buff5;
//	t_buffer	buff6;

	buff1.buff = malloc(sizeof(char) * 1500);
	buff2.buff = malloc(sizeof(char) * 1500);
	buff3.buff = malloc(sizeof(char) * 1500);
	buff4.buff = malloc(sizeof(char) * 1500);
//	buff5.buff = malloc(sizeof(char) * 1500);
//	buff6.buff = malloc(sizeof(char) * 1500);

	printf("/==========================/\n");
	buff1.max_len = 1499;
	buff1.precision = 100;
	buff1.width = 120;
	buff1.flags = 1;
	SET_FLAG_ON(buff1.flags, MINUS);
    print_double(nb1, &buff1);
	printf("nb1    == |%-120.100f|\n",	nb1);	printf("buff1  == |%s|\n",  	buff1.buff);
	free(buff1.buff);

	printf("/==========================/\n");
	buff2.max_len = 1499;
	buff2.precision = 100;
	buff2.width = 120;
	buff2.flags = 1;
	SET_FLAG_ON(buff2.flags, MINUS);
    print_double(nb2, &buff2);
	printf("nb2    == |%-120.100f|\n",	nb2);	printf("buff2  == |%s|\n",  	buff2.buff);
	free(buff2.buff);

	printf("/==========================/\n");
	buff3.max_len = 1499;
	buff3.precision = 100;
	buff3.width = 120;
	buff3.flags = 1;
	SET_FLAG_ON(buff3.flags, MINUS);
	 print_double(nb3, &buff3);
	printf("nb3    == |%-120.100f|\n",	nb3);	printf("buff3  == |%s|\n",  	buff3.buff);
	free(buff3.buff);

	printf("/==========================/\n");
	buff4.max_len = 1499;
	buff4.precision = 100;
	buff4.width = 120;
	buff4.flags = 1;
	SET_FLAG_ON(buff4.flags, MINUS);
    print_double(nb4, &buff4);
	printf("nb4    == |%-120.100f|\n",	nb4);	printf("buff4  == |%s|\n",  	buff4.buff);
	free(buff4.buff);

//	printf("/==========================/\n");
//	buff5.max_len = 1499;
//	buff5.precision = 1500;
//	buff5.width = 0;
//	buff5.flags = 1;
//  print_double(nb5, &buff5);
//	printf("nb5    == |%.1500f|\n",	nb5);	printf("buff5  == |%s|\n",  	buff5.buff);
//	free(buff5.buff);

//	printf("/==========================/\n");
//	buff6.max_len = 1499;
//	buff6.precision = 1500;
//	buff6.width = 0;
//	buff6.flags = 1;
//	print_double(nb6, &buff6);
//	printf("nb6    == |%.1500f|\n",	nb6);	printf("buff6  == |%s|\n",  	buff6.buff);
//	free(buff6.buff);
/*
	printf("\n-------1--------\n");
	printf("this inf   == [%f]\n", 10./0);
	printf("this - inf == [%f]\n", -10./0);
	printf("this nan   == [%f]\n", 0./0);
	printf("this - nan == [%f]\n", -0./0);


	printf("\n-------2--------\n");
	printf("this inf   == [%10f]\n", 10./0);
	printf("this - inf == [%10f]\n", -10./0);
	printf("this nan   == [%10f]\n", 0./0);
	printf("this - nan == [%10f]\n", -0./0);

	printf("\n-------3--------\n");
	printf("this inf   == [%0+10f]\n", 10./0);
	printf("this - inf == [%0+10f]\n", -10./0);
	printf("this nan   == [%0+10f]\n", 0./0);
	printf("this - nan == [%0+10f]\n", -0./0);

	printf("\n-------4--------\n");
	printf("this inf   == [%-10f]\n", 10./0);
	printf("this - inf == [%-10f]\n", -10./0);
	printf("this nan   == [%-10f]\n", 0./0);
	printf("this - nan == [%-10f]\n", -0./0);

	printf("\n-------5--------\n");
	printf("this inf   == [%.10f]\n", 10./0);
	printf("this - inf == [%.10f]\n", -10./0);
	printf("this nan   == [%.10f]\n", 0./0);
	printf("this - nan == [%.10f]\n", -0./0);

	printf("\n-------6--------\n");
	printf("this inf   == [%+f]\n", 10./0);
	printf("this - inf == [%+f]\n", -10./0);
	printf("this nan   == [%+f]\n", 0./0);
	printf("this - nan == [%+f]\n", -0./0);

	printf("\n-------7--------\n");
	printf("this inf   == [%#f]\n", 10./0);
	printf("this - inf == [%#f]\n", -10./0);
	printf("this nan   == [%#f]\n", 0./0);
	printf("this - nan == [%#f]\n", -0./0);
*/
	printf("\n\n----------------\n");
	printf("\n------- inf --------\n");
	printf("\n-------1--------\n");
	t_buffer	tab1;
	tab1.buff = malloc(100);
	tab1.max_len = 99;
	tab1.precision = 7;
	tab1.width = 10;
	tab1.flags = 0;
	SET_FLAG_ON(tab1.flags, MINUS);
	print_double(10./0, &tab1);
	printf("[10./0 = [%-10.7f]\n", 10./0);
	printf("[tab1  = [%s]\n", tab1.buff);

	printf("\n-------2--------\n");
	t_buffer	tab2;
	tab2.buff = malloc(100);
	tab2.max_len = 99;
	tab2.precision = 7;
	tab2.width = 10;
	tab2.flags = 0;
	SET_FLAG_ON(tab2.flags, MINUS);
	print_double(-10./0, &tab2);
	printf("[0./0 = [%-10.7f]\n", -10./0);
	printf("[tab2 = [%s]\n", tab2.buff);

	printf("\n-------3--------\n");
	t_buffer	tab3;
	tab3.buff = malloc(100);
	tab3.max_len = 99;
	tab3.precision = 7;
	tab3.width = 10;
	tab3.flags = 0;
	print_double(10./0, &tab3);
	printf("[10./0 = [%10.7f]\n", 10./0);
	printf("[tab1  = [%s]\n", tab3.buff);

	printf("\n-------4--------\n");
	t_buffer	tab4;
	tab4.buff = malloc(100);
	tab4.max_len = 99;
	tab4.precision = 7;
	tab4.width = 10;
	tab4.flags = 0;
	print_double(-10./0, &tab4);
	printf("[0./0 = [%10.7f]\n", -10./0);
	printf("[tab2 = [%s]\n", tab4.buff);


	printf("\n------- nan --------\n");
	printf("\n-------1--------\n");
	t_buffer	tab11;
	tab11.buff = malloc(100);
	tab11.max_len = 99;
	tab11.precision = 7;
	tab11.width = 10;
	tab11.flags = 0;
	SET_FLAG_ON(tab11.flags, MINUS);
	print_double(0./0, &tab11);
	printf("[10./0 = [%-10.7f]\n", 0./0);
	printf("[tab1  = [%s]\n", tab11.buff);

	printf("\n-------2--------\n");
	t_buffer	tab22;
	tab22.buff = malloc(100);
	tab22.max_len = 99;
	tab22.precision = 7;
	tab22.width = 10;
	tab22.flags = 0;
	SET_FLAG_ON(tab22.flags, MINUS);
	print_double(-0./0, &tab22);
	printf("[0./0 = [%-10.7f]\n", -0./0);
	printf("[tab2 = [%s]\n", tab22.buff);

	printf("\n-------3--------\n");
	t_buffer	tab33;
	tab33.buff = malloc(100);
	tab33.max_len = 99;
	tab33.precision = 7;
	tab33.width = 10;
	tab33.flags = 0;
	print_double(0./0, &tab33);
	printf("[10./0 = [%10.7f]\n", 0./0);
	printf("[tab1  = [%s]\n", tab33.buff);

	printf("\n-------4--------\n");
	t_buffer	tab44;
	tab44.buff = malloc(100);
	tab44.max_len = 99;
	tab44.precision = 7;
	tab44.width = 10;
	tab44.flags = 0;
	print_double(-0./0, &tab44);
	printf("[0./0 = [%10.7f]\n", -0./0);
	printf("[tab2 = [%s]\n", tab44.buff);
    return (0);

}
