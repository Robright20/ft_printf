/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 00:57:56 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/24 02:57:09 by mzaboub          ###   ########.fr       */
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

int main(void)
{
	double nbr = 123456789123456789.123456;
	char    str[500];
//  printf("/--------------------------/\n");
//  printf("nbr == |%lf|\n\n", nbr);
//  printf("/--------------------------/\n");

	//  printf("/==========================/\n");
//	str[0] = ' ';
    print_double(nbr, str);
	printf("nbr  == |%0.100lf|\n", nbr);
	printf("str  == |%s|\n", str);
//  printf("/==========================/\n");
    return (0);
}
