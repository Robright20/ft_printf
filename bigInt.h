/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigInt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:30:29 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/19 00:18:32 by mzaboub          ###   ########.fr       */
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

# define BLOCS_NBR 514

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

#endif
