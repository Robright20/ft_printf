/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 00:57:56 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/20 09:33:38 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigInt.h"

int	main(void)
{
	return (0);
}


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
