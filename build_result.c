/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:30:18 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/13 04:48:48 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*build_result(int flags, char *ret, int precision, int width)
{
	static char	*(*build[5])(int*, char*, int, int) = {apply_precision, \
		apply_width, apply_hash, apply_signs, apply_quote};
	char		*result;
	int			conv;
	int			i;

	if (width < 0)
	{
		width = -width;
		SET_FLAG_ON(flags, MINUS);
	}
	conv = flag_lookup(flags, 0, 12);
	if (conv < 0)
		return (ret);
	i = 0;
	result = build[i++](&flags, ret, conv, precision);
	if (!(result = build[i++](&flags, result, conv, width)))
		return ("Error");
	while (i < 5)
		if (!(result = build[i++](&flags, result, conv, width - precision)))
			return ("Error");
	return (result);
}

ssize_t		ft_putxstr(char *s)
{
	ssize_t		len;

	len = 0;
	while (s && *s)
		len += write(1, s++, 1);
	return (len);
}

int			flag_lookup(int flags, int pos, int bound)
{
	int i;

	i = 0;
	while (i < bound)
	{
		if (IS_ON(flags, (pos + i)))
			return (i);
		i++;
	}
	return (-1);
}

/*
**	result = apply_precision(&flags, ret, conv, precision);
**	result = apply_width(&flags, result, conv, width);
**	result = apply_hash(&flags, result, conv, width - precision);
**	result = apply_signs(&flags, result, conv, width - precision);
**	result = apply_quote(&flags, result, conv, width);
*/
