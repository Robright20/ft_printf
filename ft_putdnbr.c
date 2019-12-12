/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:39:33 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/14 18:44:36 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putdnbr(va_list ap, int flags, int precision, int width)
{
	long long	n;
	long long	tmp;
	char		*ret;
	int			i;
	int			sign;

	i = flag_lookup(flags, LLONG, 4);
	n = (i != -1) ? (g_fetch_by_sizem[i](ap, 1)) : va_arg(ap, int);
	tmp = n;
	sign = n < 0;
	i = sign;
	while (tmp && ++i)
		tmp /= 10;
	if (i == 0)
		ret = ft_strdup("0");
	if (n && !(ret = ft_strnew(i)))
		return (0);
	n = sign ? -n : n;
	while (n)
	{
		ret[i-- - 1] = n % 10 + '0';
		n /= 10;
	}
	(void)(sign && (ret[0] = '-'));
	SET_FLAG_ON(flags, DEC);
	ret = build_result(flags, ret, precision, width);
	return (ft_putxstr(ret));
}

/*
**void	test(int flags, int precision, int width, char *fmt, ...)
**{
**	va_list	ap;
**
**	va_start(ap, fmt);
**	ft_putdnbr(ap, flags, precision, width);
**	va_end(ap);
**}
**
**int		main(void)
**{
**	test(0, 0, 0, "", 10000);
**	return (0);
**}
*/
