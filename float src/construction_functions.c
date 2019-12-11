/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/11 23:44:41 by mzaboub          ###   ########.fr       */
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
	else if (IS_FLAG_ON(node.flags, PLUS))
	{
		node.buff[0] = '+';
		return (1);
	}
	else if (IS_FLAG_ON(node.flags, SPACE))
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
//	printf("len == %d;\n", compound->v_num.length);
//	printbits(&compound->v_num, 8);
//	printf("expo = %#X;\n", exponent);
//	printf("[bigbit == %d]\n", compound->bigbit);
	(void)exponent;
	if (compound->bigbit == -1337 && compound->v_num.length == 0)// infinity
	{
		if (compound->sign & 1)
		{
			ft_strcpy(node->buff, "-inf");
			*numdigits = 4;
//			printf("[buff == %s]\n", node->buff);
		}
		else
		{
			ft_strcpy(node->buff, "inf");
//			printf("[buff == %s]\n", node->buff);
			*numdigits = 3;
		}
		return (TRUE);
	}
	else if (compound->bigbit == -1337 && compound->v_num.length != 0)// NAN
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
	t_int32		pos;

	if (node->width > node->max_len)
		node->width = node->max_len;
	if (len < node->width)
	{
		if (!IS_FLAG_ON(node->flags, MINUS))
		{
			ft_memmove(node->buff + node->width - len, node->buff, len + 1);
			pos = 0;
			while (pos < (node->width - len))
				node->buff[pos++] = ' ';
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
	if (is_special_case(compound, exponent, node, &numdigits) == FALSE)
		numdigits = mini_dragon4(compound, exponent, node);
	if (node->print_expo > 0 && compound->bigbit != -1337)
	{
		ft_add_trailing_zeros(node, &numdigits);
	}
	else if (compound->bigbit != -1337)
	{
		ft_add_leading_zeros(node->buff + pos, &(node->print_expo), &numdigits);
		ft_add_trailing_zeros(node, &numdigits);
		node->buff[numdigits] = '\0';
	}
	if (compound->bigbit != -1337)
		ft_add_decimal_point(node->buff + pos, node->print_expo, \
							node->max_len + 1, numdigits);
	ft_applywidth(node);
}
