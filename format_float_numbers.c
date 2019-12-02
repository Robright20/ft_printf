/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/02 22:34:10 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>

static void		ft_add_trailing_zeros(char *buff, t_int32 print_expo, t_uint32 *numdigits, t_int32 precision)
{
	t_int32	pos;

	pos =*numdigits;
	while (pos <= precision + print_expo + 1)
		buff[pos++] = '0';
	*numdigits += (pos - *numdigits);
}

static void	ft_add_leading_zeros(char *buff, t_int32 *print_expo, t_uint32 *numdigits, t_int32 precision)
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

static void	ft_add_decimal_point(char *buff, t_int32 print_expo, t_uint32 buff_size, t_uint32 numdigits)
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
