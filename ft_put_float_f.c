/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/21 18:50:25 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "bigInt.h"
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
	(*exp) = (t_uint32)((nbr) & exp_flag ) >> 52;
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
	long long	mantissa = 0;
	long long 	temp;
	long long 	sign;
	int n;
	int dec_pos = 0;
	t_bigint temp1;	
	t_bigint a;
	t_bigint m;
	t_bigint e;

	ft_memcpy(&temp, &nbr, 8);
	get_bits(temp, &exp, &mantissa, &sign);

	ft_uint32_to_bigint(1, &a);
	ft_bigint_shiftleft(a, 52);
	ft_uint64_to_bigint(mantissa, &m);

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
			// e = 2^(exp - 1075)
			ft_uint32_to_bigint(2, &e);
			ft_bigint_shiftleft(e, exp - 1075);
			dec_pos = 100;
		}
		else if (exp < 1075)
		{
			n = 1075 - exp;
			ft_uint32_to_bigint(&e, 5);
			ft_bigint_shiftleft(&e, n);
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
	//	long double nbr = 0.0000125;
	//	printf("nbr == %.5Lf;\n", nbr);
	//	double nb = 0.12346034;
	//	printf("nb  == %.5lf;\n", nb);
	//	t_fwp	flg;
	//	char *args;

	//	flg.width = 6;
	//	flg.precision = 30;

	//	args = "";
	//	save_all_flags(&flg.flags, args);

	printf("/--------------------------/\n");
	//	ft_putfnbr(flg, nbr);
	//	printf("printf      :\t%020.3lf;\n", nbr)
	printf("LLDB == |%llf|\nLLDB == |%lle|\n", LDBL_MAX, LDBL_MAX);
	printf("/--------------------------/\n");
	//ft_putfnbr(flg, nb);
	//	printf("printf      :\t%0#10.40000f;\n", nb);	

	return (0);
}


void		print_float(double nbr)
{
	t_int32		temp_exp = 0;
	t_int64		temp_mantissa = 0;
	t_int64 	int_nbr;
	t_int64 	sign;
	t_bigint	c1;
	t_uint32	c2;
	t_bigint	mantissa;
	t_bigint	m;
	t_bigint	e;
	t_bigint	result;
	char		*print;


	ft_memcpy(&int_nbr, &nbr, 8);
	get_bits(int_nbr, &temp_exp, &temp_mantissa, &sign);

	ft_uint32_to_bigint(&c1, 2);
	ft_bigint_shiftleft(&c1, 52);
	c2 = 1075;

	ft_bigint_add(&m, c1, mantissa);
	if (exp < 1075)
	{
		exp = 1075 - exp;
		ft_uint32_to_bigint(5, &e);
		ft_bigint_shiftleft(&e, n);
		dec_pos = 310 - n;
	}
	else 
	{
		ft_uint32_to_bigint(2, &e);
		ft_bigint_shiftleft(&e, temp_exp - c2);
		dec_pos = 309;
	}
	
	ft_bigint_mult(&result, m, e);
	ft_bigint_to_ascii(result, print);
	printf("|%s|\n", print);
}
