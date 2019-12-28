/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_dragon4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 04:42:14 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/27 22:13:43 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_bigint.h"

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
** ***************************# 3 #********************************************
*/

t_int32		ft_round_thatshit(t_bigint_compound *compound, char *buff,\
											char **cur, t_uint32 out_number)
{
	t_int32	value;
	char	*buff_cur;

//	printf("cur_digit = %d;\n", out_number);
	ft_bigint_shiftleft(&compound->v_num, 1);
	value = ft_bigint_compare(compound->v_num, compound->v_dom);
//	printf("value = %d;\n", value);
	buff_cur = *cur;
	(value == 0) ? (value = ((out_number & 1) == 1)) : 1;
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
				if (*(--buff_cur) != '9')
				{
					*buff_cur += 1;
					break ;
				}
			}
		else
			*buff_cur = (out_number + '1');
	}
	else
		*buff_cur = (out_number + '0');
	*cur = buff_cur;
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

/*
** initializing v_num and v_dom
** digit = number of digits before decimale point
** cuttoff_num if the precision
** add that number so that we get only one number before decimale point in \
** 			the first division
*/

/*
** ***************************************************************************
** initialise digit_expo, v_num, v_dom, 
*/

static void	ft_predivision(t_bigint_compound *compound, t_int32 exponent,\
									t_int32 *digit_expo, t_int32 precision, t_buffer *node)
{
	if (exponent > 0)
	{
		ft_bigint_shiftleft(&compound->v_num, exponent);
		ft_uint32_to_bigint(1, &compound->v_dom);
	}
	else if (exponent < 0)
	{
		ft_uint32_to_bigint(1, &compound->v_dom);
		ft_bigint_shiftleft(&compound->v_dom, -exponent);
	}
	*digit_expo = (t_int32)((double)(compound->bigbit + exponent) *\
			LOG10_2 - 0.69) + 1;
//	printf("++++++++++ digit_expo = %d +++++++++++\n", *digit_expo);
	if (precision >= 0 && *digit_expo <= -precision && node->bol != 1)
	//if (precision >= 0 && *digit_expo <= -precision)
	{
		*digit_expo = -precision + 1;
	}
//	printf("++++++++++ digit_expo = %d +++++++++++\n", *digit_expo);
	if (*digit_expo > 0)
		ft_bigint_power10(&compound->v_dom, (*digit_expo));
	else if (*digit_expo < 0)
		ft_bigint_power10(&compound->v_num, -(*digit_expo));
	if (ft_bigint_compare(compound->v_num, compound->v_dom) >= 0)
		(*digit_expo)++;
	else
		ft_bigint_power10(&compound->v_num, 1);
}

/*
** ***************************************************************************
*/

void		ft_check_highbloc(t_bigint_compound *compound)
{
	t_uint32	hibloc_log2;
	t_uint32	shift;
	t_uint32	hibloc;

	hibloc = compound->v_dom.tab[compound->v_dom.length - 1];
	if (hibloc < 8 || hibloc > 429496729)
	{
		hibloc_log2 = logbase2_32(hibloc);
		shift = (32 + 27 - hibloc_log2) % 32;
		ft_bigint_shiftleft(&compound->v_num, shift);
		ft_bigint_shiftleft(&compound->v_dom, shift);
	}
}

/*
** ***************************************************************************
** initialising the cuutoff exponent
*/

t_int32		ft_initialize(t_int32 *cuttoff_expo, t_buffer *node, \
							t_uint32 max_len, t_int32 digit_expo)
{
	t_int32 precision;

	precision = node->precision;
	*cuttoff_expo = digit_expo - max_len;
	if (*cuttoff_expo < -(int)max_len)
		*cuttoff_expo = -max_len;
	if ((node->bol == 0) && (precision >= 0) && (-precision > *cuttoff_expo))
		*cuttoff_expo = -precision;
	else if ((node->bol == 1) && (precision >= 0) && (-precision > *cuttoff_expo))
	{
	//	printf("\n===========\n");
	//	printf("digit_expo == %d;\n", digit_expo);
	//	printf("precision == %d;\n", precision);
	//	printf("cuttoff_expo == %d;\n", *cuttoff_expo);
		//(*cuttoff_expo) = digit_expo - precision - 1;
//		if (digit_expo > -precision)
//			(*cuttoff_expo) = digit_expo - precision;
//		else if (precision != 0 && digit_expo <= -precision)
//			(*cuttoff_expo) = digit_expo - precision -1;
	//	if (digit_expo > 0 && digit_expo != precision)
	//		(*cuttoff_expo) = digit_expo - precision;
	//	else
			(*cuttoff_expo) = digit_expo - precision - 1;

	//	else
	//		(*cuttoff_expo) = -2 -  precision;
//		printf("cuttoff_expo == %d;\n", *cuttoff_expo);
	//	printf("cuttoff_expo == %d;\n", *cuttoff_expo);
	//	printf("===========\n");
	}
	return (digit_expo - 1);
}

/*
** ***************************************************************************
*/

int			ft_fill_buffer(t_bigint_compound *compound, t_int32 *digit_expo, \
							t_int32 cuttoff_expo, t_buffer *node)
{
	t_int32	out_number;
	char	*buff_cur;

	out_number = 0;
	buff_cur = node->buff;
//	printf("\n###digit_expo   == %d;\n", *digit_expo);
//	printf("###cuttoff_expo == %d;\n", cuttoff_expo);
	while (1)
	{
		(*digit_expo)--;
		out_number = ft_bigint_divid(&compound->v_num, &compound->v_dom);
		//printf(">>out_number = %d;\n", out_number);
		//if (compound->v_num.length == 0 || ((node->bol == 0) && *digit == cuttoff_expo) || ((node->bol == 1) && (*digit == cuttoff_expo + 1))
		if (compound->v_num.length == 0 || (*digit_expo == cuttoff_expo))
			break ;
		*buff_cur = (char)(out_number + '0');
		buff_cur++;
		ft_bigint_copy(&compound->temp1, &compound->v_num);
		ft_bigint_mult_int(&compound->v_num, compound->temp1, 10);
	}
	node->print_expo += ft_round_thatshit(compound, node->buff, &buff_cur, \
											out_number);
	buff_cur++;
	*buff_cur = '\0';
//	printf(">> buff == [%s]\n", node->buff);
	return (buff_cur - node->buff);
}

/*
** ***************************************************************************
*/

int			mini_dragon4(t_bigint_compound *compound, t_int32 exponent, \
							t_buffer *node)
{
	t_int32		digit_expo;
	t_int32		cuttoff_expo;

	if (ft_is_zero(compound->v_num) == TRUE)
	{
		node->buff[0] = '0';
		node->print_expo = 0;
		return (1);
	}
	ft_predivision(compound, exponent, &digit_expo, node->precision, node);
	node->print_expo = ft_initialize(&cuttoff_expo, node, \
										node->max_len, digit_expo);
	ft_check_highbloc(compound);
	return (ft_fill_buffer(compound, &digit_expo, cuttoff_expo, node));
}

/*
** ***************************************************************************
*/
