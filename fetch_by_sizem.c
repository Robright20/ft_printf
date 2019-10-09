/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_by_sizem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:34:54 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/09 15:57:03 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	fetch_by_sizem_h(va_list ap, int bsigned)
{
	long long	result;
	
	result = bsigned ? (long long)(short)va_arg(ap, int) ||\
			(!bsigned && ()));
	return (result);
}
long long	fetch_by_sizem_ll(va_list ap);
long long	fetch_by_sizem_l(va_list ap);
long long	fetch_by_sizem_hh(va_list ap);
