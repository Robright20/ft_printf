/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putonbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:40:30 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/13 04:49:36 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putonbr(va_list ap, int flags, int precision, int width)
{
	char				*ret;
	int					i;
	unsigned long long	n;
	unsigned long long	tmp;

	i = flag_lookup(flags, LLONG, 4);
	n = (i != -1) ? (g_fetch_by_sizem[i](ap, 0)) : va_arg(ap, unsigned int);
	tmp = n;
	i = 0;
	while (tmp && ++i)
		tmp /= 8;
	if (n == 0)
		ret = ft_strdup("0");
	if (n && !(ret = ft_strnew(i)))
		return (0);
	while (n)
	{
		ret[i-- - 1] = n % 8 + '0';
		n /= 8;
	}
	SET_FLAG_ON(flags, OCTAL);
	ret = build_result(flags, ret, precision, width);
	return (ft_putxstr(ret));
}
