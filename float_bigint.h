/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:30:29 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/25 18:11:52 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
# define BIGINT_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

/*
** ---------------------------------------------------------------------------
** some necessery  defines and typedefs
*/

# define BLOCS_NBR 1000
# define TRUE 1
# define FALSE 0
# define LOG10_2 0.30102999566398119521373889472449

typedef	int32_t		t_int32;
typedef	int64_t		t_int64;
typedef	uint32_t	t_uint32;
typedef	uint64_t	t_uint64;

/*
** ---------------------------------------------------------------------------
** main struct for bigInt impelimentation
*/

typedef struct	s_bigint
{
	t_uint32	tab[BLOCS_NBR];
	t_uint32	length;
}				t_bigint;

typedef struct	s_buffer
{
	char	*buff;
	int		max_len;
	t_int32	print_expo;
	t_int32	precision;
	t_int32	width;
	t_int32	flags;
	t_int32	bol;
}				t_buffer;

typedef struct	s_bigints_compound
{
	t_bigint	v_num;
	t_bigint	v_dom;
	t_int32		sign;
	t_bigint	temp1;
	t_int32		bigbit;
}				t_bigint_compound;

/*
** ---------------------------------------------------------------------------
** struct to store the flags and how to print the number;
*/

/*
** precision is the exacte lenght of fractional part;
** width	 is minimum width of the whole number;
** signbit	 is should the number have sign;
*/

/*
** ---------------------------------------------------------------------------
** this struct is to extract the double (64bit float)
*/

typedef union	u_floatunion
{
	double		fltnbr;
	t_uint64	nbr;
}				t_floatunion;

/*
** this union and struct is to extract the long double bits (80bit float)
*/

typedef struct	s_double_struct
{
	t_uint64	low;
	t_uint64	high;
}				t_double_struct;

typedef union	u_longdobleunion
{
	long double		dbl;
	t_double_struct integer;
}				t_ldbl_union;

/*
** ---------------------------------------------------------------------------
** this struct is to gather all the necissery arguments in one place
*/

/*
** ---------------------------------------------------------------------------
** function declaration
** t_uint32			BigInt_DivideWithRemainder_MaxQuotient9(
**								t_bigint *dividend, const t_bigint *divisor);
*/
void			ft_uint32_to_bigint(t_uint32 src, t_bigint *dst);
void			ft_uint64_to_bigint(t_uint64 src, t_bigint *dst);
t_int32			ft_bigint_compare(t_bigint lhs, t_bigint rhs);
void			ft_bigint_add(t_bigint *result, t_bigint lhs, t_bigint rhs);
void			ft_bigint_mult(t_bigint *result, t_bigint lhs, t_bigint rhs);
void			ft_bigint_mult_int(t_bigint *result, t_bigint lhs,\
														t_uint32 rhs);
void			ft_bigint_shiftleft(t_bigint *result, t_uint32 shiftbits);
void			ft_bigint_subtraction(t_bigint *lhs, t_bigint *rhs);
t_uint32		ft_bigint_divid(t_bigint *lhs, t_bigint *rhs);
void			ft_bigint_copy(t_bigint *dst, t_bigint *src);
void			print_double(double nbr, t_buffer *buff_tools, int bol);
void			print_long_double(long double nbr, t_buffer *node, int bol);
void			ft_bigint_power10(t_bigint *result, t_int32 power);
t_uint32		logbase2_32(t_uint32 val);
t_uint32		logbase2_64(t_uint64 val);
int				mini_dragon4(t_bigint_compound *compound, t_int32 exponent, \
														t_buffer *node);
t_int32			ft_is_zero(t_bigint nbr);
void			printbits(void *p, int i);

#endif
