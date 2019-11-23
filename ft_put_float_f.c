/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/23 05:51:46 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigInt.h"
#include "header.h"
#include "ft_printf.h"

/*
 ** ------------------------------------------------
 */
/*
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
*/

/*
 ** ------------------------------------------------
 */

/*
 ** 		** les tach a fire pour le bigint **
 **
 **	 creat the bigint type 
 **	 creat		- bigInt_addition()
 ** 			- bigInt_multiplication()
 ** 			- int_to_bigInt()
 ** 	calcule of 2^52	and convert this to bigInt type ===> a
 ** 	calcule of 2^(exp - 1075)  usning bigInt type	===> e
 ** 	convert the mantissa to bingInt					===> m 
 ** 	calcule this in big int  (a + m) * e
 */

int mini_dragon4(t_bigint mantissa, t_int32 exponent, t_uint32 bigbit, char *buff)
{
	t_bigint	v_num;
	t_bigint	v_dom;
	t_bigint	temp1;
	t_bigint	temp2;
	t_int32		digit;
	char		*buff_cur;
	double 		log10_2 = 0.30102999566398119521373889472449;

	ft_bigint_copy(&v_num, &mantissa);
	if (exponent > 0)
	{
		// e = 2^(exp - 1075)
		ft_bigint_shiftleft(&v_num, exponent);
		ft_uint32_to_bigint(&v_dom, 1);
		//dec_pos = 100;
	}
	else if (exponent < 0)
	{
		//n = 1075 - exp;
		ft_bigint_shift_left(&v_dom, -exponent);
		//dec_pos = 310 - n;
	}

	digit = (t_int32)((double)(bigbit + exponent) * log10_2 - 0.69) + 2;
	if (digit > 0)
	{
		// v_dom = v_dom * 10^digit
		ft_uint32_to_bigint(10, &temp1);
		ft_shiftleft(&temp1, digit);
		ft_bigint_copy(&temp2, v_dom);
		ft_bigint_mult(&v_dom, temp1, temp2);
	}
	else if (digit < 0)
	{
		//vn = vn * 10^-digit
		ft_uint32_to_bigint(10, &temp1);
		ft_shiftleft(&temp1, -digit);
		ft_bigint_copy(&temp2, v_num);
		ft_bigint_mult(&v_dom, temp1, temp2);
	}

	t_uint32	hibloc = v_dom.tab[v_dom.length];
	if (hibloc < 8 || hibloc > 429496729)
	{
		t__uint32 hibloc_log2, shift;

		hibloc_log2 = logbase2_32(hibloc);
		shift = (32 + 27 - hibloc_log2) % 32;
		ft_bigint_shiftleft(v_num, shift);
		ft_bigint_shiftleft(v_dom, shift);
	}

	buff_cur++;

	while (true)
	{
		digit = digit - 1;
		out_number = ft_bigint_divide(v_num, v_dom);
		if (v_num.length == 0)
			break;
		*buff_cur = out_number + '0';
		buff_cur++;
		ft_bigint_copy(&temp, &v_num);
		ft_bigint_mult_int(&v_num, temp, 10);
	}

	*buff_cur = '\0';
	return (buff_cur - buff);
	
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

typedef struct s_floatunion
{
	double fltnbr;
	t_uint nbr;
}				t_floatunion;

void		print_double(double nbr, char *buff)
{
	t_uint64	demi_mantissa;
	t_uint64	mantissa;
	t_int32		demi_exponent;
	t_int32		exponent;
	t_int32		sign;
	t_uint32	bigbit;
	t_floatunion	cast;
	
	cast.fltnbr = nbr;
	demi_mantissa = (cast.nbr & 0XFFFFFFFFFFFFF);
	demi_exponent = ((cast.nbr >> 52) & 0X7FF);
	sign = (cast.nbr >> 63);

	mantissa = (1ull << 52) | demi_mantissa;
	exponent = demi_exponent - 1075;
	bigbit = 52;

	t_bigint big_mantissa;
	ft_uint64_to_bigint(big_mantissa, &mantissa);
	ft_calcule_bigint(bigmantissa, exponent, bigbit, sign, char *buff);	
}

void	ft_calcule_bigint(t_bigint mantissa, t_int32 exponent, t_int32 bigbit, t_int32 sign, char *buff)
{
	t_uint32 buff_len;

	buff_len = mini_dragon4(mantissa, exponent, bigmantissabit, buff);	
	printf("|%s|\n", buff);
}


void		ft_get_bigint(t_bigint vn, t_int32 exp, t_bigint vd)
{
	if (exp > 0)
	{
		ft_bigint_mult_int(vn, exp);
		ft_uint32_to_bigint(1, vd);
	}
	else
	{
		ft_uint32_to_bigint(1, vd);
		ft_bigint_mult_int(vn, -exp);
	}
}

