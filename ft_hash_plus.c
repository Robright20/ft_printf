/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:03:07 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/06 15:47:34 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_hash_plus_alloc(int *i, int flag)
{
	char	*s;
	int		p_len;

	p_len = (is_on(flag, HASH) && is_on(flag, OCTAL)) +\
	(((is_on(flag, HASH) && is_on(flag, X)) || is_on(flag, x)) * 2);
	*i += p_len;
	if (!(s = ft_strnew(sizeof(char) * (*i))))
		return (NULL);
	if (p_len == 2)
		is_on(flag, x) ? ft_strcpy(s, "0x") : ft_strcpy(s, "0X");
	else if (p_len == 1)
			s[0] = '0';
	return (s);
}
