/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/10/03 17:12:16 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "ft_printf.h"

/*
** ------------------------------------------------
*/

void	get_bits(long long nbr, long long *exp, long long *mantissa, long long *sign)
{
	long long exp_flag;
	long long m_flag;
	long long sign_flag;

	exp_flag = 9218868437227405312;  // 01111111 11110000 00000000 00000000 00000000 00000000 00000000 00000000
	m_flag   = 4503599627370495; 	 // 00000000 00001111 11111111 11111111 11111111 11111111 11111111 11111111
	sign_flag = -11111111;		// nbr aleatoir negatif
	(*exp) = ((nbr) & exp_flag ) >> 52;
	(*mantissa) = (nbr & m_flag);
	(*sign) = ((nbr & sign_flag) >> 63);
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

int ft_putfnbr(t_fwp flags, double nbr)
{
	long long	exp = 0;
	long long	 mantissa = 0;
	long long 	temp;
	long long 	sign;

	ft_memcpy(&temp, &nbr, 8);
	get_bits(temp, &exp, &mantissa, &sign);

	t_bigint atemp = convert(2);
	t_bigint a = bigint_power(atemp, 52);
	t_bigint m = convert(mantissa);

	t_bigint e;
	int n;
	int dec_pos = 0;
	t_bigint temp1;	
	if (exp == 2047)
	{
		if (mantissa == 0)
			(sign == -1) ? write(1, "-inf", 4) : write(1, "inf", 3);
		else
			write(1, "nan", 3);
	}
	else
	{
	if (exp > 1075)
	{
		temp1 = convert(2);
		e = bigint_power(temp1, exp - 1075);
		dec_pos = 100;
	}
	else if (exp < 1075)
	{
		n = 1075 - exp;
		e = bigint_power(convert(5), n);
		dec_pos = 310 - n;
	}
	else 
	{
		e = bigint_power(convert(2), 1074);
		dec_pos = 309;
	}
	t_bigint *add = bigint_add(a, m);
	print_bigint(m, 400, sign, flags);
	print_bigint(*add, 400, sign, flags);
	t_bigint result = bigint_mult(*add, e);
	free(add);
	print_bigint(result, dec_pos, sign, flags);
	}
	return (0);
}

/*
** ------------------------------------------------
*/ 
int	main(void)
{
	long double nbr = 0.0000125;
//	printf("nbr == %.5Lf;\n", nbr);
//	double nb = 0.12346034;
//	printf("nb  == %.5lf;\n", nb);
	t_fwp	flg;
	char *args;

	flg.width = 6;
	flg.precision = 30;

	args = "";
	save_all_flags(&flg.flags, args);

	printf("/--------------------------/\n");
	ft_putfnbr(flg, nbr);
//	printf("printf      :\t%020.3lf;\n", nbr);	
	printf("/--------------------------/\n");
	//ft_putfnbr(flg, nb);
//	printf("printf      :\t%0#10.40000f;\n", nb);	

	return (0);
}
