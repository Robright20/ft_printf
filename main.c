/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 00:57:56 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/29 15:52:18 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigInt.h"
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

	long double nb1 = 11.11;
	long double nb2 = 123456789.123456789;
	long double nb3 = 0.123456;
	long double nb4 = 0.0000000000987654321;
	long double nb5 = 112233;
	long double nb6 = DBL_MAX;

	char	buff1[1000];
	char	buff2[1000];
	char	buff3[1000];
	char	buff4[1000];
	char	buff5[1000];
	char	buff6[1000];


	printf("/==========================/\n");
    print_long_double(nb1, buff1, 1000);
	printf("nb1    == |%.100Lf|\n",	nb1);	printf("buff1  == |%s|\n",  	buff1);
	printf("/==========================/\n");
    print_long_double(nb2, buff2, 1000);
	printf("nb2    == |%.100Lf|\n",	nb2);	printf("buff2  == |%s|\n",  	buff2);
	printf("/==========================/\n");
    print_long_double(nb3, buff3, 1000);
	printf("nb3    == |%.100Lf|\n",	nb3);	printf("buff3  == |%s|\n",  	buff3);
	printf("/==========================/\n");
    print_long_double(nb4, buff4, 1000);
	printf("nb4    == |%.100Lf|\n",	nb4);	printf("buff4  == |%s|\n",  	buff4);
	printf("/==========================/\n");
    print_long_double(nb5, buff5, 1000);
	printf("nb5    == |%.100Lf|\n",	nb5);	printf("buff5  == |%s|\n",  	buff5);
	printf("/==========================/\n");
    print_long_double(nb6, buff6, 1000);
	printf("nb6    == |%.100Lf|\n",	nb6);	printf("buff6  == |%s|\n",  	buff6);
	printf("/==========================/\n");
    return (0);

}
