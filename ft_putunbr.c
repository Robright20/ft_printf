/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:38:14 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/13 04:49:43 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putunbr(va_list ap, int flags, int precision, int width)
{
	char				*ret;
	int					i;
	unsigned long long	n;
	unsigned long long	tmp;

	i = flag_lookup(flags, LLONG, 4);
	n = (i != -1) ? (g_fetch_by_sizem[i](ap, 0)) : va_arg(ap, int);
	tmp = n;
	i = 0;
	while (tmp && ++i)
		tmp /= 10;
	if (!(ret = ft_strnew(i)))
		return (0);
	while (n)
	{
		ret[i-- - 1] = n % 10 + '0';
		n /= 10;
	}
	SET_FLAG_ON(flags, XUINT);
	ret = build_result(flags, ret, precision, width);
	return (ft_putxstr(ret));
}
