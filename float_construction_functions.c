/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/13 07:16:57 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** **********************************# 2 #*************************************
*/

static void		ft_add_trailing_zeros(t_buffer *node, t_uint32 *numdigits)
{
	t_int32	pos;
	t_int32	stop;

	pos = *numdigits;
	stop = node->precision + node->print_expo;
	if (stop > node->max_len)
		stop = node->max_len;
	while (pos <= stop)
		node->buff[pos++] = '0';
	*numdigits += (pos - *numdigits);
	node->buff[pos] = '\0';
}

/*
** ***************************************************************************
*/

static void		ft_add_leading_zeros(char *buff, t_int32 *print_expo, \
												t_uint32 *numdigits)
{
	t_int32	pos;

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

/*
** ***************************************************************************
*/

static void		ft_add_decimal_point(char *buff, t_int32 print_expo, \
									t_uint32 buff_size, t_uint32 numdigits)
{
	t_uint32	len;

	len = numdigits - print_expo - 1;
	if (numdigits + 2 > buff_size)
		len = buff_size - print_expo - 1;
	ft_memmove(buff + print_expo + 2, buff + print_expo + 1, len);
	buff[print_expo + 1] = '.';
}

/*
** ***************************************************************************
*/

static t_uint32	ft_add_sign(t_bigint_compound *compound, t_buffer node)
{
	if (compound->sign & 1)
	{
		node.buff[0] = '-';
		return (1);
	}
	else if (IS_ON(node.flags, PLUS))
	{
		node.buff[0] = '+';
		return (1);
	}
	else if (IS_ON(node.flags, SPACE))
	{
		node.buff[0] = ' ';
		return (1);
	}
	else
		return (0);
}

t_uint32		is_special_case(t_bigint_compound *compound, t_int32 exponent, \
								t_buffer *node, t_uint32 *numdigits)
{
	(void)exponent;
	if (compound->bigbit == -1337 && compound->v_num.length == 0)
	{
		if (compound->sign & 1)
		{
			ft_strcpy(node->buff, "-inf");
			*numdigits = 4;
		}
		else
		{
			ft_strcpy(node->buff, "inf");
			*numdigits = 3;
		}
		return (TRUE);
	}
	else if (compound->bigbit == -1337 && compound->v_num.length != 0)
	{
		ft_strcpy(node->buff, "nan");
		*numdigits = 3;
		return (TRUE);
	}
	return (FALSE);
}

void			ft_applywidth(t_buffer *node)
{
	const t_int32	len = ft_strlen(node->buff);
	t_int32			pos;
	t_int32			max;

	if (node->width > node->max_len)
		node->width = node->max_len;
	if (len < node->width)
	{
		if (!IS_ON(node->flags, MINUS))
		{
			pos = 0;
			if ((node->buff[0] == '-' || IS_ON(node->flags, PLUS) || \
						IS_ON(node->flags, SPACE)) && IS_ON(node->flags, ZERO))
				pos = 1;
			ft_memmove(node->buff + node->width - len + pos, node->buff + pos, len + 1 - pos);
								//len +1 to copy the '\0';
			max = (node->width - len + pos);
			while (pos < max)
			{
				node->buff[pos] = (IS_ON(node->flags, ZERO) ? '0' : ' ');
				pos++;
			}
		}
		else
		{
			pos = len;
			while (pos < node->width)
				node->buff[pos++] = ' ';
			node->buff[pos] = '\0';
		}
	}
}

void			ft_format_float(t_bigint_compound *compound, t_int32 exponent, \
														t_buffer *node)
{
	t_uint32	numdigits;
	t_uint32	pos;

	pos = ft_add_sign(compound, *node);
	if (pos == 1)
		node->buff++;
	if (is_special_case(compound, exponent, node, &numdigits) == FALSE)
		numdigits = mini_dragon4(compound, exponent, node);
	if (node->print_expo > 0 && compound->bigbit != -1337)
	{
		ft_add_trailing_zeros(node, &numdigits);
	}
	else if (compound->bigbit != -1337)
	{
		ft_add_leading_zeros(node->buff, &(node->print_expo), &numdigits);
		ft_add_trailing_zeros(node, &numdigits);
	}
	if (compound->bigbit != -1337 && (node->precision != 0 || IS_ON(node->flags, HASH)))
		ft_add_decimal_point(node->buff, node->print_expo, \
							node->max_len + 1, numdigits);
	if (pos == 1)
		node->buff--;
	ft_applywidth(node);
}

void		ft_scientific_format(t_bigint_compound *compound, t_int32 exponent, \
									t_buffer *node)
{
	t_uint32	numdigits;
	t_uint32	pos;

	pos = ft_add_sign(compound, *node);
	if (pos == 1)
		node->buff++;
	if (is_special_case(compound, exponent, node, &numdigits) == FALSE)
		numdigits = mini_dragon4(compound, exponent, node);
	// increment buff to leave the whole number;
	ft_add_trailing_zeros(node, &numdigits);
	ft_add_decimal_point(node->buff, 0, node->max_len, numdigits);
	if (pos == 1)
		node->buff--;
	// insert the decimal point prior the fractional number; this must check if # is activated
	// add trailing zeros or remove them, because we can have them after rounding up;
	// add the 'e' ( check the sign or live it to itoa)
	// itoa of the exponent;
	// join the buff with the exponent buff;
	// done
}
