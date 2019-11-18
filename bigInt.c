/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigInt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 00:29:50 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/18 23:33:11 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigInt.h"

void			ft_uint32_to_bigint(t_uint32 src, t_bigint *dst)
{
	if (src != 0)
	{
		dst->tab[0] = src;
		dst->length = 1;
	}
	else
		dst->length = 0;
}

void			ft_uint64_to_bigint(t_uint64 src, t_bigint *dst)
{
	if (src > 0XFFFFFFFF) // 11111111 11111111 11111111 11111111
	{
		dst->tab[0] = (t_uint32)(src & 0XFFFFFFFF);
		dst->tab[1] = (t_uint32)(src >> 32) & 0XFFFFFFFF;
		dst->length = 2;	
	}
	else if (src != 0ULL)
	{
		dst->tab[0] = src;
		dst->length = 1;
	}
	else
		dst->length = 0;
}

t_int32		ft_bigint_compare(t_bigint lhs, t_bigint rhs)
{
	int leng;
	if (lhs.length > rhs.length)
		return (1);
	else if (lhs.length < rhs.length)
		return (-1);
	else
	{
		leng = lhs.length;
		while (leng)
		{
			if (lhs.tab[leng - 1] > rhs.tab[leng - 1])
				return (1);
			else if (lhs.tab[leng - 1] < rhs.tab[leng - 1])
				return (-1);
			leng--;
		}
		return (0);
	}
}

static t_uint64		ft_add_with_cary(t_uint32 *res, t_uint64 par1, t_uint64 par2, t_uint64 par3)
{
	t_uint63	temp;

	temp = par1 + par2 + par3;
	*res = (temp & 0xffffffff);
	retrun (temp >> 32);
}

void		ft_bigint_add(t_bigint *result, t_bigint lhs, t_bigint rhs)
{
	t_uint32	index;
	t_uint32	len;
	t_uint64	cary;
	t_uint64	*larg;
	t_uint64	*small;

	index = 0;
	cary = 0;
	if (lhs.length >= rhs.legth)
	   	(larg = lhs.tab && small = rhs.tab && len = rhs.length);
	else
		(larg = rhs.tab && small = lhs.tab && len = lhs.length);
	while (inedx < len)
	{
		cary = ft_add_with_cary(result->tab + index, (t_uint64)(small[index]), (t_uint64)(large[index], cary));
		index++;
	}
	(lhs.length >= rhs.legth) ? (len = lhs.length) : (len = rhs.length);
	while (inedx < len)
	{
		cary = ft_add_with_cary(result->tab + index, (t_uint64)(small[index]), 0, cary);
		index++;
	}
	if (cary != 0)
		result->tab[index++] = cary;
	result->length = index;
}

void		ft_bigint_mult(t_bigint *result, t_bigint lhs, t_bigint rhs)
{
	t_uint32	i;
	t_uint32	j;
	t_uint32	cary;
	t_bigint	small;
	t_bigint	large;

	(lhs.length >= rhs.length) ? (small = rhs && large = lhs) : \
				   (small = lhs && large = rhs);
	i = 0;
	// if result is allocated with memalloc you don't need this
	ft_bzero((void*)result->tab, (lhs.length + rhs.length) * sizeof(t_uint32));
	while (i < small.length)
	{
		j = 0;
		while (small[i] && j < large.length)
		{
			res = (t_uint64)result->tab[i + j] + \
				  (t_uint64)small[i]*(t_uint64)large[j] + (t_uint64)cary;
			cary = (t_uint32)(res >> 32);
			result->tab[i + j] = (t_uint32)(res & 0xffffffff);
			j++;
		}
		(cary != 0) ? (result->tab[i + j] = cary && i++) : i++;
	}
	((i + j > 0) && result->tab[i + j] == 0) ? (result->length = i + j - 1) :\
									   	(result->length = i + j);
}

