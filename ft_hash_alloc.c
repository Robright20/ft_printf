/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:03:07 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/10 16:45:54 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hash_alloc(int *i, int flag)
{
	char	*s;
	int		p_len;

	p_len = (IS_ON(flag, HASH) && IS_ON(flag, OCTAL)) +\
	(((IS_ON(flag, HASH) && (IS_ON(flag, BHEX) || IS_ON(flag, HEX))) * 2));
	*i += p_len;
	printf("p_len = %d\n", p_len);
	if (!(s = ft_strnew(sizeof(char) * (*i))))
		return (NULL);
	if (p_len == 2)
		IS_ON(flag, HEX) ? ft_strcpy(s, "0x") : ft_strcpy(s, "0X");
	else if (p_len == 1)
			s[0] = '0';
	return (s);
}
