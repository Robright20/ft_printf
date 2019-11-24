/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/24 02:57:06 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigInt.h"
#include "header.h"
#include "ft_printf.h"
#include <float.h>

/*
** ------------------------------------------------
*/

typedef union s_floatunion
{
	double		fltnbr;
	t_uint64	nbr;
}				t_floatunion;

typedef struct s_bigints_compound
{
	t_bigint	v_num;
	t_bigint	v_dom;
	t_bigint	temp2;
	t_bigint	temp1;
	t_int32		bigbit;
}				t_bigint_compound;
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

/*
** ---------------------------------------------------------------------------
**	buff << functions << v_num and v_dom
**
**	 struct compound {
**		bigint	v_num
**		bigint	v_dom
**		bigint 	temp1
**		bigint	temp2
**		t_int32	bigbit
**		}
*/	

int mini_dragon4(t_bigint_compound *compound, t_int32 exponent, char *buff)
{
	t_bigint	temp1;
	t_bigint	temp2;
	t_int32		digit;
	char		*buff_cur;
	double 		log10_2 = 0.30102999566398119521373889472449;

	ft_bigint_copy(&compound->v_num, &compound->temp1);
	if (exponent > 0)
	{
		// e = 2^(exp - 1075)
		ft_bigint_shiftleft(&compound->v_num, exponent);
		ft_uint32_to_bigint(1, &compound->v_dom);
		//dec_pos = 100;
	}
	else if (exponent < 0)
	{
		//n = 1075 - exp;
		ft_uint32_to_bigint(1, &compound->v_dom);
		ft_bigint_shiftleft(&compound->v_dom, -exponent);
		//dec_pos = 310 - n;
	}

	digit = (t_int32)((double)(compound->bigbit + exponent) * log10_2 - 0.69) + 2;
	printf("digit == %d\n", digit);

	if (digit > 0)
	{
		// v_dom = v_dom * 10^digit
		ft_bigint_power10(&compound->v_dom, digit);
	}
	else if (digit < 0)
	{
		//vn = vn * 1^-digit
		ft_uint32_to_bigint(1, &temp1);
		ft_bigint_shiftleft(&temp1, -digit);
		ft_bigint_copy(&temp2, &compound->v_num);
		ft_bigint_mult(&compound->v_dom, temp1, temp2);
	}


	t_uint32	hibloc = compound->v_dom.tab[compound->v_dom.length - 1];
	if (hibloc < 8 || hibloc > 429496729)
	{
		t_uint32 hibloc_log2, shift;

		hibloc_log2 = logbase2_32(hibloc);
		shift = (32 + 27 - hibloc_log2) % 32;
		ft_bigint_shiftleft(&compound->v_num, shift);
		ft_bigint_shiftleft(&compound->v_dom, shift);
	}

	buff_cur = buff;
	t_bigint	temp;

	t_uint32	out_number;

	while (1)
	{
		digit = digit - 1;
		out_number = ft_bigint_divid(&compound->v_num, &compound->v_dom);
		*buff_cur = out_number + '0';
		buff_cur++;
		if (compound->v_num.length == 0)
			break;
		ft_bigint_copy(&temp, &compound->v_num);
		ft_bigint_mult_int(&compound->v_num, temp, 10);
	}

	*buff_cur = '\0';
	printf("buff == |%s|\n", buff);
	return (buff_cur - buff);

	return (0);

}


/*
**----------------------------------------------------------------------------
** help functions of bellow code;
*/

void	ft_get_values(double nbr, t_bigint_compound *head, t_int32 *exponent, t_int32 *sign)
{
	t_floatunion	cast;
	t_uint64		mantissa;

	cast.fltnbr = nbr;
	mantissa = (1ull << 52) | (cast.nbr & 0XFFFFFFFFFFFFF);
	ft_uint64_to_bigint(mantissa, &head->temp1);
	*exponent = ((cast.nbr >> 52) & 0X7FF) - 1075;
	*sign = (cast.nbr >> 63);
	head->bigbit = 52;
}

/*
**----------------------------------------------------------------------------
** here is the start;
*/

void		print_double(double nbr, char *buff)
{
	t_int32				exponent;
	t_int32				sign;
	t_bigint_compound	compound;
	
	ft_get_values(nbr, &compound, &exponent, &sign);
	mini_dragon4(&compound, exponent, buff);

//	ft_calcule_bigint(bigmantissa, exponent, bigbit, sign, char *buff);	
}

typedef union	s_longdobleunion
{
	long double dbl;
	t_uint64	nbr[2];
}				t_longdouble_union;
/*
void		print_long_double(double nbr, char *buff)
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
	ft_uint64_to_bigint(mantissa, &big_mantissa);
	mini_dragon4(big_mantissa, exponent, bigbit, buff);
}
*/
