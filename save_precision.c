/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:29:53 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/01 22:28:13 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		save_precision(char *fmt, int *precision, va_list ap, va_list ap2)
{
	int		i;

	i = 0;
	if (fmt[0] == '.')
	{
		fmt++;
		while ((fmt[i] && ft_isdigit(fmt[i])) && fmt[0] != '0')
			i++;
		if (i != 0)
		{
			*width = ft_atoi(fmt);
			return (++i);
		}
		if (fmt[0] == '*')
		{
			i = va_argnth(ap2, &fmt[1]);
			(void)((i) && (*width = va_arg(ap2, int)));
			(void)((!i) && (*width = va_arg(ap, int)));
			i++;
		}
		va_end(ap2);
		return (++i);
	}
	return (0);
}
