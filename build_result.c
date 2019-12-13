/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:30:18 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/12 05:39:08 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			max(int a, int b)
{
	//printf("[[diff == %d]]", a > b ? a : b);
	return (a > b ? a : b);
}

char		*build_result(int flags, char *result, int precision, int width)
{
	static char	*(*build[5])(int*, char*, int, int) = {apply_precision, \
		apply_quote, apply_width, apply_hash, apply_signs};
	int			conv;
	int			i;
	int			len;
	int			special;

	if (width < 0)
	{
		width = -width;
		SET_FLAG_ON(flags, MINUS);
	}
	conv = flag_lookup(flags, 0, 12);
	if (conv < 0)
		return (result);
	i = 0;
	len = ft_strlen(result);
	special = (result[0] == '0');
	result = build[i++](&flags, result, conv, precision);
	if (!(result = build[i++](&flags, result, conv, width)))
		return ("Error");
	if (!(result = build[i++](&flags, result, conv, width)))
		return ("Error");
	//printf("{%s}{%d}", result, ft_strlen(result));
	while (i < 5)
	{
		(i == 3 && special) ? i++ : 1;
		if (!(result = build[i++](&flags, result, conv, width - max(precision, len))))
			return ("Error");
//	printf("[%s]{%d}", result, ft_strlen(result));
	}
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
