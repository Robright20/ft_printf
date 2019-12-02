/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/02 22:05:36 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>

void		ft_add_trailing_zeros(char *buff, t_int32 print_expo, t_uint32 *numdigits, t_int32 precision)
{
	t_int32	pos;

	pos =*numdigits;
	while (pos <= precision + print_expo + 1)
		buff[pos++] = '0';
	*numdigits += (pos - *numdigits);
}

void	ft_add_leading_zeros(char *buff, t_int32 *print_expo, t_uint32 *numdigits, t_int32 precision)
{
	t_int32	pos;

	(void)precision;
	pos = -(*print_expo);
	if (pos >= 0)
	{
		ft_memmove(buff + pos, buff, *numdigits);
		*numdigits += pos;
		pos--;
		while (pos >= 0)
			buff[pos--] = '0';
		*print_expo = 0;
	}
}

void	ft_add_decimal_point(char *buff, t_int32 print_expo, t_uint32 buff_size, t_uint32 numdigits)
{
	t_uint32	len;

	len = numdigits - print_expo - 1;
	if (numdigits + 2 > buff_size)
		len = buff_size - print_expo - 1;
	ft_memmove(buff + print_expo + 2, buff + print_expo + 1, len);
	buff[print_expo + 1] = '.';
}

void	ft_format_float(t_bigint_compound *compound, t_int32 exponent, char *buff, t_uint32 buff_size)
{
	t_uint32	numdigits;
	t_int32		print_expo;
	t_int32		precision = compound->precision;
	t_uint32	pos;

	if (*buff == '+' || *buff == '-')
		pos = 1;
	else
		pos = 0;
	numdigits = mini_dragon4(compound, exponent, buff + pos, buff_size - pos, &print_expo, precision);
	if (print_expo > 0)
	{
		ft_add_trailing_zeros(buff + pos, print_expo, &numdigits, precision);
		buff[numdigits] = '\0';
	}
	else
	{
		ft_add_leading_zeros(buff + pos, &print_expo, &numdigits, precision);
		ft_add_trailing_zeros(buff + pos, print_expo, &numdigits, precision);
		buff[numdigits - 1] = '\0';
	}
	ft_add_decimal_point(buff + pos, print_expo, buff_size, numdigits);
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
	ft_uint64_to_bigint(mantissa, &head->temp1);
}

/*
**----------------------------------------------------------------------------
** here is the start;
*/

void		print_double(double nbr, char *buff, t_uint32 buff_size)
{
	t_int32				exponent;
	t_int32				sign;
	t_bigint_compound	*compound;
	t_uint32			flag_sign = 0;

	/* extract the floating point value */
	compound = malloc(sizeof(t_bigint_compound));
	ft_bzero(&compound->v_num, BLOCS_NBR);
	ft_bzero(&compound->v_dom, BLOCS_NBR);
	ft_bzero(&compound->temp1, BLOCS_NBR);
	ft_bzero(&compound->temp2, BLOCS_NBR);
	ft_get_values(nbr, compound, &exponent, &sign);
	if (sign & 1)
		*buff = '-';
	else if (flag_sign)
		*buff = '+';
	else
		*buff = '\0';
	// manage the inf and nan here, check if mantissa is equale to zero ! 
	compound->precision = 100;	
	ft_format_float(compound, exponent, buff, buff_size);
}

void	ft_get_ldbl_values(long double nbr, t_bigint_compound *head,\
							t_int32 *exponent, t_int32 *sign)
{
	t_ldbl_union	cast;
	t_uint64		mantissa;

	cast.dbl = nbr;
	// manage the normalized and denormalized number
	if (((cast.integer.high) & 0X7FFF) != 0)
	{
		// normalized number;
		mantissa = ((1ull << 63) | (cast.integer.low & 0X7FFFFFFFFFFFFFFF));
		head->bigbit = 63;
		*exponent = (((cast.integer.high) & 0X7FFF) - 16446);
	}
	else
	{
		// dinormalized number;
		mantissa = (cast.integer.low & 0X7FFFFFFFFFFFFFFF);
		*exponent = 1 - 16446;
		head->bigbit = logbase2_64(mantissa);
	}
//	*sign = (cast.integer.high >> 16);
	*sign = 0;
	ft_uint64_to_bigint(mantissa, &head->temp1);
}

void		print_long_double(long double nbr, char *buff, t_uint32 buff_size)
{
	t_int32				exponent;
	t_int32				sign;
	t_uint32			flag_sign = 0;
	t_bigint_compound	*compound;

	compound = malloc(sizeof(t_bigint_compound));
	ft_bzero(&compound->v_num, BLOCS_NBR);
	ft_bzero(&compound->v_dom, BLOCS_NBR);
	ft_bzero(&compound->temp1, BLOCS_NBR);
	ft_bzero(&compound->temp2, BLOCS_NBR);
	ft_get_ldbl_values(nbr, compound, &exponent, &sign);
	if (sign & 1)
		*buff = '-';
	else if (flag_sign)
		*buff = '+';
	else
		*buff = '\0';
	// manage the inf and nan here, check if mantissa is equale to zero !
	compound->precision = 100;
	ft_format_float(compound, exponent, buff, buff_size);
}
