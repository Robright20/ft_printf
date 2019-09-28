/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:05:15 by nkhribec          #+#    #+#             */
/*   Updated: 2019/09/28 11:43:32 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#define FLAG "+#- 0wpoxXdiu"
#define set_flag(flag, index) flag = flag | (1 << (32 - index))
#define is_on(flag, index) (flag & (1 << (32 - index))) != 0

typedef enum    e_flag
{
	    PLUS = 1, HASH, MINUS, SPACE, ZERO, WIDTH, PRECISION, OCTAL, x, X, i, d, u
}               t_flag;

void    printb(unsigned int c);
int     ft_putonbr(unsigned int n, int flag, int precision, int width);
int     ft_putxnbr(unsigned int n, int flag, int precision, int width);
int     ft_putxnbr(unsigned int n, int flag, int precision, int width);
int     ft_putdnbr(int n, int flag, int precision, int width);
void    nulltoblack(char *s, int until);
void    blacktozero(char *s, int until);
void    shift(char *s, int shift_value);
void    fprecision(char **s, int flag, int precision, int shift_value);
void    fwidth(char **s, int flag, int precision, int width);
int     ft_print(char **s, int flag, int precision, int width);
char    *ft_hash_plus_alloc_o(int *i, int flag);
char    *ft_hash_plus_alloc_heX(int *i, int flag);
char    *ft_hash_plus_alloc_hex(int *i, int flag);
char    *ft_hash_plus_alloc(int *i, int flag);
