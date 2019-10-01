/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:03:07 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/01 14:52:25 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_hash_plus_alloc(int *i, int flag)
{
	char	*s;
	int		prefix_len = 0;

	prefix_len = (is_on(flag, PLUS)) + ((is_on(flag, HASH)) && (is_on(flag, OCTAL))) +\
				 (((is_on(flag, HASH)) && ((is_on(flag, X)) || (is_on(flag, x)))) * 2);
	printf("prefix = %d\n", prefix_len);
	*i += prefix_len;
	if (!(s = ft_memalloc(sizeof(char) * ((*i) + 1))))
		return (NULL);
	if (prefix_len == 3)
		is_on(flag, x) ? ft_strcpy(s, "+0x") : ft_strcpy(s, "+0X");
	else if (prefix_len == 2)
	{
		if (is_on(flag, x) || is_on(flag, X))
			ft_strcpy(s, "0x");
		else
			ft_strcpy(s, "+0");
	}
	else if (prefix_len == 1)
	{
		if (is_on(flag, PLUS))
			s[0] = '+';
		else
			s[0] = '0';
	}
	return (s);
}
