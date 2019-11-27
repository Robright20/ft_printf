/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/27 02:28:04 by mzaboub          ###   ########.fr       */
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

t_int32		ft_round_thatshit(t_bigint_compound *compound, char *buff, char *buff_cur, t_uint32 out_number)
{
	t_int32	value;

	ft_bigint_shiftleft(&compound->v_num, 1);
	value = ft_bigint_compare(compound->v_num, compound->v_dom);
	if (value == 0)
		value = ((out_number & 1) == 1);
	if (value > 0)
	{
		if (out_number == 9)
			while (TRUE)
			{
				if (buff == buff_cur)
				{
					*buff_cur = '1';
					return (1);
				}
				buff_cur--;
				if (*buff_cur != '9')
					break;
			}
		*buff_cur = (out_number + 1 + '0');
	}
	else
		*buff_cur = (out_number + '0');
	return (0);
}

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

t_int32	ft_is_zero(t_bigint nbr)
{
	if (nbr.length != 0)	
		return (FALSE);
	return (TRUE);
}

int mini_dragon4(t_bigint_compound *compound, t_int32 exponent, char *buff, t_uint32 max_len, t_int32 *print_expo, t_int32 cuttoff_num)
{
	t_int32		digit;
	char		*buff_cur;
	double 		log10_2 = 0.30102999566398119521373889472449;
	t_int32	cuttoff_expo;
	t_uint64	adam;

	*print_expo = 0;
	/*-------------------------------------------------*/
	if (ft_is_zero(compound->temp1) == TRUE)
	{
		buff[0] = '0';
		return (0);
	}
	/*-------------------------------------------------*/
	// initialize v_num and v_dom
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
	}
	/*-------------------------------------------------*/
	digit = (t_int32)((double)(compound->bigbit + exponent) * log10_2 - 0.69) + 1;
	if (cuttoff_num >= 0 && digit <= -cuttoff_num)
		digit = -cuttoff_num + 1;
	/*-------------------------------------------------*/
		// v_dom = v_dom * 10^digit or v_num = v_num*10^-digit
	if (digit > 0)
		ft_bigint_power10(&compound->v_dom, digit);
	else if (digit < 0)
		ft_bigint_power10(&compound->v_num, -digit);
	/*-------------------------------------------------*/
	if (ft_bigint_compare(compound->v_num, compound->v_dom) >= 0)
		digit++;
	else
		ft_bigint_power10(&compound->v_num, 1);
	/* ------------------------------------------------- */
	cuttoff_expo = digit - max_len;
	if ((cuttoff_num >= 0) && (-cuttoff_num > cuttoff_expo))
			cuttoff_expo = -cuttoff_num;
	//exit(0);
	*print_expo = digit - 1;
	/*-------------------------------------------------*/
	t_uint32	hibloc = compound->v_dom.tab[compound->v_dom.length - 1];
	if (hibloc < 8 || hibloc > 429496729)
	{
		t_uint32 hibloc_log2, shift;
		hibloc_log2 = logbase2_32(hibloc);
		shift = (32 + 27 - hibloc_log2) % 32;
		ft_bigint_shiftleft(&compound->v_num, shift);
		ft_bigint_shiftleft(&compound->v_dom, shift);
	}
	/*-------------------------------------------------*/
	buff_cur = buff;
	t_bigint	temp;

	t_uint32	out_number;
	while (1)
	{
		digit = digit - 1;
		out_number = ft_bigint_divid(&compound->v_num, &compound->v_dom);
		if (out_number >= 10)
			printf("out_number error == %d;\n", out_number);
		if (compound->v_num.length == 0 || digit == cuttoff_expo)
			break;
		*buff_cur = (char)(out_number + '0');
			buff_cur++;
		ft_bigint_copy(&temp, &compound->v_num);
		ft_bigint_mult_int(&compound->v_num, temp, 10);
	}
//	*buff_cur = (char)(out_number + '0');

//	printf("{{%s}}\n", buff_cur);
	*print_expo += ft_round_thatshit(compound, buff, buff_cur, out_number);
	buff_cur++;
	*buff_cur = '\0';
	printf("buff_cur - buff = %ld\n", buff_cur - buff);
	return (buff_cur - buff);
}


void	ft_format_float(t_bigint_compound *compound, t_int32 exponent, char *buff, t_uint32 buff_size)
{
	t_uint32	numdigits;
	t_int32		print_expo;
	t_int32		precision = 11;
	
	numdigits = mini_dragon4(compound, exponent, buff + 1, buff_size - 1, &print_expo, precision);
//	printf("print expo = %d;\n", print_expo);

//	ft_memmove(buff + print_expo + 2, buff + print_expo + 1, numdigits - print_expo);
//	buff[print_expo + 2] = '.';

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
	// manage the normalized and denormalized number
	if (((cast.nbr >> 52) & 0X7FF) != 0)
	{
		// normalized number;
		mantissa = ((1ull << 52) | (cast.nbr & 0XFFFFFFFFFFFFF));
		head->bigbit = 52;
		//*exponent = (((cast.nbr >> 52) & 0X7FF) - 1075);
		*exponent = (((cast.nbr >> 52) & 0X7FF) - 1075);
	}
	else
	{
		// dinormalized number;
		mantissa = (cast.nbr & 0XFFFFFFFFFFFFF);
		*exponent = 1 - 1075;
		head->bigbit = logbase2_64(mantissa);
	}
	*sign = (cast.nbr >> 63);
	printf("mantissa == {%llu}\t", mantissa);
	printf("exponent == {%d}\n", *exponent);
	ft_uint64_to_bigint(mantissa, &head->temp1);

}

/*
**----------------------------------------------------------------------------
** here is the start;
*/
typedef struct s_options
{
	t_uint32	precision; // the exacte lenght of fractional part;
	t_uint32	width; // minimum width of the whole number;
	t_uint32	signbit; //should the number have sign;
}				t_options;

void		print_double(double nbr, char *buff, t_uint32 buff_size)
{
	t_int32				exponent;
	t_int32				sign;
	t_bigint_compound	*compound;
	/* extract the floating point value */

	compound = malloc(sizeof(t_bigint_compound));
	ft_bzero(&compound->v_num, BLOCS_NBR);
	ft_bzero(&compound->v_dom, BLOCS_NBR);
	ft_bzero(&compound->temp1, BLOCS_NBR);
	ft_bzero(&compound->temp2, BLOCS_NBR);
	ft_get_values(nbr, compound, &exponent, &sign);
	if (sign & 1)
		*buff = '-';
	else
		*buff = '+';

	// manage the inf and nan here, check if mantissa is equale to zero ! 
	
	ft_format_float(compound, exponent, buff, buff_size);
/*	t_uint32	numdigits;
	t_int32		print_expo;
	t_int32		precision = 11;
	
	numdigits = mini_dragon4(&compound, exponent, buff + 1, buff_size - 1, &print_expo, precision);
			//	mini_dragon4(&compound, exponent, buff);
*/
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

/*
	printf("\n********************************************\n");
	printf("v_num len == %d;\n", compound->v_num.length);
	printf("v_num == %llu\t", ((t_uint64)(compound->v_num.tab[1]) << 32) | (t_uint64)compound->v_num.tab[0]);	printbits(&compound->v_num, 12);

	printf("v_dom len == %d;\n", compound->v_dom.length);
	printf("v_dom == %llu\t", ((t_uint64)(compound->v_dom.tab[1]) << 32) | (t_uint64)compound->v_dom.tab[0]);	printbits(&compound->v_dom, 12);

	printf("********************************************\n");
*/
