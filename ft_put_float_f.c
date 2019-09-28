/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/09/28 16:48:44 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** ------------------------------------------------
*/

void	get_bits(long long nbr, long long *exp, long long *mantissa)
{
	long long exp_flag;
	long long m_flag;

	exp_flag = 9218868437227405312;  // 01111111 11110000 00000000 00000000 00000000 00000000 00000000 00000000
	m_flag   = 4503599627370495; 	 // 00000000 00001111 11111111 11111111 11111111 11111111 11111111 11111111

	(*exp) = ((nbr) & exp_flag ) >> 52;
	(*mantissa) = (nbr & m_flag);
}


/*
** ------------------------------------------------
*/

/*
** 		** les tach a fire pour le bigint **
**
**	 creat the bigint type 
**	 creat		- bigInt_addition()
** 			 	- bigInt_multiplication()
** 			 	- int_to_bigInt()
** 	calcule of 2^52	and convert this to bigInt type ===> a
** 	calcule of 2^(exp - 1075)  usning bigInt type	===> e
** 	convert the mantissa to bingInt					===> m 
** 	calcule this in big int  (a + m) * e
*/


void	float_conversion(double nbr)
{
	long long	exp = 0;
	long long	 mantissa = 0;
	long long temp;

	ft_memcpy(&temp, &nbr, 8);
	get_bits(temp, &exp, &mantissa);

	t_bigint *atemp = convert(2);
	t_bigint a = bigint_power(*atemp, 52);
	t_bigint m = *convert(mantissa);

	t_bigint e;
	int n;
	int dec_pos = 0;
	t_bigint *temp1;	
	if (exp > 1075)
	{
		temp1 = convert(2);
		e = bigint_power(*temp1, exp - 1075);
		dec_pos = 100;
	}
	else
	{
		n = 1075 - exp;
		e = bigint_power(*convert(5), n);
		dec_pos = 100 - n - 1;
	}
	t_bigint add = *bigint_add(a, m);
	t_bigint result = bigint_mult(add, e);
	printf("nb1 == "); print_bigint(result, dec_pos);
}

/*
** ------------------------------------------------
*/
int	main(void)
{
	double nbr = 12344352545.4654878798345346456645;

	printf("nb  == %.50lf;\n", nbr);
	float_conversion(nbr);

	return (0);
}
