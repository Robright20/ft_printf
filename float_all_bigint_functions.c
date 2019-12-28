/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_all_bigint_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:14:26 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/28 18:18:22 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_bigint.h"

/*
** ---------------------------------------------------------------------------
*/

void				ft_uint32_to_bigint(t_uint32 src, t_bigint *dst)
{
	ft_memset(dst->tab, 0, (BLOCS_NBR) * sizeof(dst->tab[0]));
	if (src != 0)
	{
		dst->tab[0] = src;
		dst->length = 1;
	}
	else
		dst->length = 0;
}

/*
** ---------------------------------------------------------------------------
*/

void				ft_uint64_to_bigint(t_uint64 src, t_bigint *dst)
{
	ft_memset(dst->tab, 0, (BLOCS_NBR) * sizeof(dst->tab[0]));
	if (src > 0XFFFFFFFF)
	{
		dst->tab[0] = (t_uint32)(src & 0XFFFFFFFF);
		dst->tab[1] = (t_uint32)((src >> 32) & 0XFFFFFFFF);
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

/*
** ---------------------------------------------------------------------------
*/

t_int32				ft_bigint_compare(t_bigint lhs, t_bigint rhs)
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

/*
** ---------------------------------------------------------------------------
*/

static t_uint64		ft_add_ints(t_uint32 *res, t_uint64 par1, \
		t_uint64 par2, t_uint64 par3)
{
	t_uint64	temp;

	temp = par1 + par2 + par3;
	*res = (temp & 0xffffffff);
	return (temp >> 32);
}

/*
** ---------------------------------------------------------------------------
*/

static	t_uint32	ft_assigne_left_and_right(t_bigint lhs, t_bigint rhs, \
		t_bigint *small, t_bigint *larg)
{
	if (lhs.length >= rhs.length)
	{
		*small = rhs;
		*larg = lhs;
		return (rhs.length);
	}
	else
	{
		*small = lhs;
		*larg = rhs;
		return (lhs.length);
	}
}

/*
** ---------------------------------------------------------------------------
*/

void				ft_bigint_add(t_bigint *result, t_bigint lhs, t_bigint rhs)
{
	t_uint32	index;
	t_uint32	len;
	t_uint64	cary;
	t_bigint	larg;
	t_bigint	small;

	index = 0;
	cary = 0;
	len = ft_assigne_left_and_right(lhs, rhs, &small, &larg);
	while (index < len)
	{
		cary = ft_add_ints(result->tab + index, (t_uint64)(small.tab[index]), \
				(t_uint64)(larg.tab[index]), cary);
		index++;
	}
	(lhs.length >= rhs.length) ? (len = lhs.length) : \
								(len = rhs.length);
	while (index++ < len)
		cary = ft_add_ints(result->tab + index - 1, \
				(t_uint64)(small.tab[index - 1]), 0, cary);
	if (cary != 0)
		result->tab[index++] = cary;
	result->length = index;
}

/*
** ---------------------------------------------------------------------------
**	you can remove ft_bzero if result is allocated with memalloc.
**	result = lhs * rhs; (bouth of them are bigints);
*/

void				ft_bigint_mult(t_bigint *result, t_bigint lhs, t_bigint rhs)
{
	t_uint32	i;
	t_uint32	j;
	t_uint64	cary;
	t_bigint	small;
	t_bigint	larg;

	ft_assigne_left_and_right(lhs, rhs, &small, &larg);
	i = 0;
	ft_bzero((void*)result->tab, (lhs.length + rhs.length) * sizeof(t_uint32));
	while (i < small.length)
	{
		j = 0;
		while (small.tab[i] != 0 && j < larg.length)
		{
			cary = (t_uint64)result->tab[i + j] + \
					(t_uint64)small.tab[i] * (t_uint64)larg.tab[j] + cary;
			result->tab[i + j] = (t_uint32)(cary & 0xffffffff);
			cary = (cary >> 32);
			j++;
		}
		(cary != 0) ? ((result->tab[i + j] = (cary & 0xffffffff))) : 1;
		i++;
	}
	((i + j > 0) && result->tab[i + j - 1] == 0) ? (result->length = i + j - 1)\
													: (result->length = i + j);
}

/*
** ---------------------------------------------------------------------------
**	result = (bigint) * (uint32);
*/

void				ft_bigint_mult_int(t_bigint *result, \
										t_bigint lhs, \
										t_uint32 rhs)
{
	t_uint64	cary;
	t_uint32	index;

	index = 0;
	cary = 0;
	while (index < result->length)
	{
		cary = (t_uint64)lhs.tab[index] * (t_uint64)rhs + cary;
		result->tab[index] = (t_uint32)(cary & 0xffffffff);
		cary = cary >> 32;
		index++;
	}
	if (cary != 0)
		result->tab[index++] = (t_uint32)cary;
	result->length = index;
}

/*
** ---------------------------------------------------------------------------
**	result = result << 32;
*/

static	void		ft_shift_bloc(t_uint32 *dstbloc, \
									t_uint32 *srcbloc, \
									t_uint32 *stopbloc)
{
	while (srcbloc >= stopbloc)
	{
		*dstbloc = *srcbloc;
		srcbloc--;
		dstbloc--;
	}
	while (dstbloc >= stopbloc)
	{
		*dstbloc = 0;
		dstbloc--;
	}
}

/*
** ---------------------------------------------------------------------------
*/

static	void		ft_shift_bits(t_uint32 *dstbloc, \
									t_uint32 *srcbloc, \
									t_uint32 *stopbloc, \
									t_uint32 shiftbits)
{
	const	t_uint32	highbits_shift = (shiftbits % 32);
	const	t_uint32	lowbits_shift = (32 - highbits_shift);
	t_uint32			highbits;
	t_uint32			lowbits;

	highbits = 0;
	lowbits = (*srcbloc) >> lowbits_shift;
	while (srcbloc > stopbloc)
	{
		*dstbloc = highbits | lowbits;
		highbits = (*srcbloc) << highbits_shift;
		srcbloc--;
		lowbits = (*srcbloc) >> lowbits_shift;
		dstbloc--;
	}
	*dstbloc = highbits | lowbits;
	*(--dstbloc) = (*srcbloc << highbits_shift);
	while (--dstbloc >= stopbloc)
		*dstbloc = 0;
}

/*
** ---------------------------------------------------------------------------
** shift bigints to the left, "shiftbits" time
** if the shift is exactly n bloc -> ft_shift_bloc
** else it's not an exact n bloc -> ft_shift_bits
** 		in this cas we can shift for more then a bloc;
*/

void				ft_bigint_shiftleft(t_bigint *result, t_uint32 shiftbits)
{
	const	t_uint32	highbits_shift = (shiftbits % 32);
	const	t_uint32	blocs_to_shift = (shiftbits / 32);
	t_uint32			*dstbloc;
	t_uint32			*srcbloc;

	srcbloc = result->tab + result->length - 1;
	dstbloc = srcbloc + blocs_to_shift;
	if (highbits_shift == 0)
	{
		ft_shift_bloc(dstbloc, srcbloc, result->tab);
		result->length += blocs_to_shift;
	}
	else
	{
		ft_shift_bits(dstbloc + 1, srcbloc, result->tab, shiftbits);
		result->length += blocs_to_shift + 1;
		if (result->tab[result->length - 1] == 0)
			result->length--;
	}
}

/*
** ---------------------------------------------------------------------------
** lhs = lhs - rhs;
*/

void				ft_bigint_subtraction(t_bigint *lhs, t_bigint *rhs)
{
	t_uint32 index;
	t_uint64 borrow;
	t_uint64 diff;

	index = 0;
	borrow = 0;
	while (index < lhs->length)
	{
		diff = (t_uint64)lhs->tab[index] - (t_uint64)rhs->tab[index] - \
											(t_uint64)borrow;
		borrow = (diff >> 32) & 1;
		lhs->tab[index] = (t_uint32)(diff & 0xffffffff);
		index++;
	}
}

/*
** ---------------------------------------------------------------------------
**
** 				lhs = lhs / rhs and quotient is returnd;
**
** 	if (lhs->length > rhs->length)
**		printf("length error\n");
**	if (rhs->tab[rhs->length - 1] == 0xffffffff)
**		printf("there is an error here;");
** var [0] <=> product result
** var [1] <=> borrow
** var [2] <=> difference
*/

static void				ft_divid_annex(t_bigint *lhs, \
										t_bigint *rhs, \
										t_div_vars *all)
{
	while (all->index < rhs->length)
	{
		all->var[0] = (t_uint64)rhs->tab[all->index] * (t_uint64)all->q + \
											(t_uint64)all->carry;
		all->carry = all->var[0] >> 32;
		all->var[2] = (t_uint64)lhs->tab[all->index] - \
						(all->var[0] & 0xffffffff) - all->var[1];
		all->var[1] = (all->var[2] >> 32) & 1;
		lhs->tab[all->index++] = (t_uint32)(all->var[2] & 0xffffffff);
	}
}

t_uint32			ft_bigint_divid(t_bigint *lhs, t_bigint *rhs)
{
	t_div_vars	all;

	if (lhs->length < rhs->length)
		return (0);
	ft_memset(&all, 0, sizeof(all));
	all.q = lhs->tab[rhs->length - 1] / (rhs->tab[rhs->length - 1] + 1);
	(all.q > 9) ? (exit(1)) : 1;
	ft_divid_annex(lhs, rhs, &all);
	while (lhs->length > 0 && lhs->tab[lhs->length - 1] == 0)
		lhs->length = (lhs->length - 1);
	if (ft_bigint_compare(*lhs, *rhs) >= 0)
	{
		ft_bigint_subtraction(lhs, rhs);
		all.q++;
	}
	while (lhs->length > 0 && lhs->tab[lhs->length - 1] == 0)
		lhs->length = (lhs->length - 1);
	return (all.q);
}

/*
** ---------------------------------------------------------------------------
** vn <=> value numerator
** vd <=> value dinomirator;
*/

/*
** ---------------------------------------------------------------------------
** bigint copy;
*/

void		ft_bigint_copy(t_bigint *dst, t_bigint *src)
{
	t_uint32	index;

	index = 0;
	dst->length = src->length;
	while (index < src->length)
	{
		dst->tab[index] = src->tab[index];
		index++;
	}
}

/*
** ---------------------------------------------------------------------------
** result = result * 10^power
*/

void		ft_bigint_power10(t_bigint *result, t_int32 power)
{
	t_int32		index;
	t_bigint	swap;

	index = 0;
	while (index < power)
	{
		ft_bigint_copy(&swap, result);
		ft_bigint_mult_int(result, swap, 10);
		index++;
	}
}

/*
** ---------------------------------------------------------------------------
** this is the log table orginised before fixing it for the norme;
** ;
**	static const t_uint32		log_table[256] = {
**		0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
**		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
**		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
**		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
**		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
**		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
**		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
**		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
**		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
**		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
**		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
**		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
**		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
**		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
**		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
**		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
**	};
*/

t_uint32			logbase2_32(t_uint32 val)
{
	t_uint32					temp;
	static const t_uint32		log_table[256] = {
		0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
	};

	temp = val >> 24;
	if (temp)
		return (24 + log_table[temp]);
	temp = val >> 16;
	if (temp)
		return (16 + log_table[temp]);
	temp = val >> 8;
	if (temp)
		return (8 + log_table[temp]);
	return (log_table[val]);
}

t_uint32	logbase2_64(t_uint64 val)
{
	t_uint64 temp;

	temp = val >> 32;
	if (temp)
		return (32 + logbase2_32((t_uint32)temp));
	return (logbase2_32((t_uint32)val));
}

t_int32	ft_is_zero(t_bigint nbr)
{
	if (nbr.length != 0)
		return (FALSE);
	return (TRUE);
}
