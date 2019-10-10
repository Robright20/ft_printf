/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_by_sizem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:34:54 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/10 20:19:20 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	fetch_by_sizem_h(va_list ap, int bsigned)
{
	return (bsigned ? (long long)(short)va_arg(ap, int) :\
			(long long)(unsigned short)va_arg(ap, int));
}

long long	fetch_by_sizem_hh(va_list ap, int bsigned)
{
	return (bsigned ? (long long)(char)va_arg(ap, int) :\
			(long long)(unsigned char)va_arg(ap, int));
}

long long	fetch_by_sizem_l(va_list ap, int bsigned)
{
	(void)bsigned;
	return ((long long)va_arg(ap, long));
}

long long	fetch_by_sizem_ll(va_list ap, int bsigned)
{
	(void)bsigned;
	return (va_arg(ap, long long));
}
