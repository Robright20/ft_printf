/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/27 22:13:41 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** **********************************# 2 #*************************************
*/

static void		ft_add_trailing_zeros(t_buffer *node, t_uint32 *numdigits, \
														t_int32 bigbit)
{
	t_int32	pos;
	t_int32	stop;

	if (node->print_expo > 0 && bigbit != -1337 && \
			node->print_expo >= *numdigits)
	{
		stop = *numdigits;
		pos = node->print_expo;
		node->buff[pos + 1] = '\0';
		while (pos >= stop)
			node->buff[pos--] = '0';
		*numdigits = node->print_expo + 1;
	}
}

/*
** ***************************************************************************
*/

static void		ft_add_leading_zeros(char *buff, t_int32 *print_expo, \
		t_uint32 *numdigits, t_int32 bigbit)
{
	t_int32	pos;

	if (bigbit != -1337)
	{
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
}

/*
** ***************************************************************************
** number of digits after decimal point
*/

static void		ft_add_pt(char *buff, t_int32 print_expo, \
		t_uint32 buff_size, t_uint32 numdigits)
{
	t_uint32	len;

	len = numdigits - print_expo - 1;
	if (numdigits + 2 > buff_size)
		len = buff_size - print_expo - 1;
	if (len != 0)
	{
		ft_memmove(buff + print_expo + 2, buff + print_expo + 1, len + 1);
		buff[print_expo + 1] = '.';
	}
	else
	{
		buff[print_expo + 1] = '.';
		buff[print_expo + 2] = '\0';
	}
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

/*
** ****************************************************************************
*/

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

/*
** ****************************************************************************
*/

static char	*get_exponent_digits(t_buffer *node)
{
	char	*str;
	char	*tmp;

	str = ft_itoa(node->print_expo);
	if ((node->print_expo >= 0 && ft_strlen(str) < 2) || \
			(node->print_expo < 0 && ft_strlen(str) < 3))
	{
		if (node->print_expo >= 0)
			tmp = ft_strjoin("+0", str);
		else
			tmp = ft_strjoin("-0", str + 1);
		ft_memdel((void**)&str);
		str = tmp;
	}
	else if (node->print_expo >= 0)
	{
		tmp = ft_strjoin("+", str);
		ft_memdel((void**)&str);
		str = tmp;
	}
	tmp = ft_strjoin("e", str);
	ft_memdel((void**)&str);
	return (tmp);
}

/*
** ****************************************************************************
*/

static void	ft_special_case(t_buffer *node)
{
	SET_FLAG_ON(node->flags, STRING);
	SET_FLAG_OFF(node->flags, XFLOAT);
	SET_FLAG_OFF(node->flags, ZERO);
	node->buff = \
		build_result(node->flags, node->buff, node->precision, node->width);
}

void			ft_format_float(t_bigint_compound *compound, t_int32 exponent, \
		t_buffer *node)
{
	t_uint32	numdigits;
	t_uint32	pos;

	pos = ft_add_sign(compound, *node);
    (node->buff) += (pos == 1) ? 1 : 0;
	if ((node->precision == 0 && !IS_ON(node->flags, POINT)) || \
			(node->precision < 0))
		node->precision = 6;
	ft_memset(node->buff, '\0', node->max_len + 1);
	if (is_special_case(compound, exponent, node, &numdigits) == TRUE)
	{
		ft_special_case(node);
		/*
		SET_FLAG_ON(node->flags, STRING);
		SET_FLAG_OFF(node->flags, XFLOAT);
		SET_FLAG_OFF(node->flags, ZERO);
		node->buff = \
			build_result(node->flags, node->buff, node->precision, node->width);
		*/
		return ;
	}
	else
		numdigits = mini_dragon4(compound, exponent, node);
	ft_add_leading_zeros(node->buff, &(node->print_expo), \
							&numdigits, compound->bigbit);
	ft_add_trailing_zeros(node, &numdigits, compound->bigbit);
	if (compound->bigbit != -1337 && (node->precision != 0 || \
				IS_ON(node->flags, HASH)))
		ft_add_pt(node->buff, node->print_expo, node->max_len + 1, numdigits);
	node->buff = apply_precision(&node->flags, node->buff, \
									XFLOAT, node->precision);
	numdigits = ft_strlen(node->buff);

    (node->buff) -= (pos == 1) ? 1 : 0;
	node->buff = apply_width(&node->flags, node->buff, XFLOAT, node->width);
}

/*
** ****************************************************************************
*/

void		ft_scientific_format(t_bigint_compound *compound, t_int32 exponent, \
		t_buffer *node)
{
	t_uint32	numdigits;
	t_uint32	pos;
	int		i = 0;
	char		*str;
	char		*temp;
	char		signe;

	pos = ft_add_sign(compound, *node);
    (node->buff) += (pos == 1) ? 1 : 0;
	//(pos == 1) ? (node->buff++) : 1;
	if ((node->precision == 0 && !IS_ON(node->flags, POINT)) || (node->precision < 0))
		node->precision = 6;
	ft_memset(node->buff, '\0', node->max_len + 1);// we can do this befor and gain this line 
	if (is_special_case(compound, exponent, node, &numdigits) == FALSE)
	{
		numdigits = mini_dragon4(compound, exponent, node);
		node->buff = apply_precision(&node->flags, node->buff, EXPO, node->precision);
		numdigits = (node->precision > 0) ? node->precision + 1 : numdigits;

		if (node->precision != 0 || IS_ON(node->flags, HASH))
		{
			ft_memmove(node->buff + 2, node->buff + 1, numdigits);
			node->buff[1] = '.';
		}
	//	(pos == 1) ? (node->buff--) : 1;
   		 (node->buff) -= (pos == 1) ? 1 : 0;
		str = get_exponent_digits(node);
		temp = node->buff;
		node->buff = ft_strjoin(node->buff, str);
		ft_memdel((void**)&temp);
		ft_memdel((void**)&str);
	}
	else
	{
		SET_FLAG_ON(node->flags, STRING);
		SET_FLAG_OFF(node->flags, XFLOAT);
		SET_FLAG_OFF(node->flags, ZERO);
		node->buff = build_result(node->flags, node->buff, node->precision, node->width);
		return ;
	}
	node->buff = apply_width(&node->flags, node->buff, EXPO, node->width);
}

/*
** ****************************************************************************
*/
