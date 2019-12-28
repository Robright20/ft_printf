/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:30:18 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/26 13:55:39 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			max(int a, int b)
{
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
	if (IS_ON(flags, POINTER))
	{
		special = 0;
		SET_FLAG_OFF(flags, POINTER);
		conv = HEX;
	}
	else
		special = ((result[0] == '0') && !IS_ON(flags, OCTAL));
	result = build[i++](&flags, result, conv, precision);
	if (!(result = build[i++](&flags, result, conv, width)))
		return ("Error");
	if (!(result = build[i++](&flags, result, conv, width)))
		return ("Error");
	while (i < 5)
	{
		(i == 3 && special) ? i++ : 1;
		if (!(result = build[i++](&flags, result, conv, width - max(precision, len))))
			return ("Error");
	//	printf("result[%d] == {%s}\n", i, result);

	}
//	printf("final result == {%s}\n", result);

	return (result);
}

ssize_t		ft_putxstr(char *s)
{
	ssize_t		len;
	
//	printf("\n\n\nputxstr result == {%s}\n", s);

	len = ft_strlen(s);
	write(1, s, len);
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
