/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:47:35 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/03 17:29:00 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		save_width(char *fmt, int *width, va_list ap, va_list ap2)
{
	int		i;

	i = 0;
	while ((fmt[i] && ft_isdigit(fmt[i])))
		i++;
	if (i != 0)
	{
		*width = ft_atoi(fmt);
		return (i);
	}
	if (fmt[0] == '*')
	{
		i = va_argnth(ap2, fmt + 1);
		(void)((i) && (*width = va_arg(ap2, int)));
		(void)((!i) && (*width = va_arg(ap, int)));
		i++;
	}
	va_end(ap2);
	return (i);
}
