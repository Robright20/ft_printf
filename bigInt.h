/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigInt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:30:29 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/29 16:09:59 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_INT_H
# define BIG_INT_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
//#include "header.h"
#include "libft/libft.h"

# define BLOCS_NBR 1000
# define TRUE 1
# define FALSE 0

typedef  int32_t  t_int32;
typedef  int64_t  t_int64; 
typedef  uint32_t t_uint32; 
typedef  uint64_t t_uint64;

typedef struct	s_bigint
{
	t_uint32 tab[BLOCS_NBR];
	t_uint32 length;
}				t_bigint;

void    printbits(void *p, int i);
void			ft_uint32_to_bigint(t_uint32 src, t_bigint *dst);
void			ft_uint64_to_bigint(t_uint64 src, t_bigint *dst);
t_int32			ft_bigint_compare(t_bigint lhs, t_bigint rhs);
t_uint32		BigInt_DivideWithRemainder_MaxQuotient9(t_bigint *dividend, const t_bigint *divisor);
void                ft_bigint_add(t_bigint *result, t_bigint lhs, t_bigint rhs);
void                ft_bigint_mult(t_bigint *result, t_bigint lhs, t_bigint rhs);
void                ft_bigint_mult_int(t_bigint *result, t_bigint lhs, t_uint32 rhs);
void                ft_bigint_shiftleft(t_bigint *result, t_uint32 shiftbits);
void                ft_bigint_subtraction(t_bigint *lhs, t_bigint *rhs);
t_uint32            ft_bigint_divid(t_bigint *lhs, t_bigint *rhs);
void				ft_bigint_copy(t_bigint *dst, t_bigint *src);
void		print_double(double nbr, char *buff, t_uint32 buff_size);
void		print_long_double(long double nbr, char *buff, t_uint32 buff_size);
void		ft_bigint_power10(t_bigint *result, t_int32 power);
t_uint32			logbase2_32(t_uint32 val);
t_uint32			logbase2_64(t_uint64 val);


#endif
