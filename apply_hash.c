/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:12:14 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/13 05:08:25 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_hash_hex(char *result, int width, char *prefix)
{
	int		i;

	if (result[0] == '0' && width > 0)
	{
		if (width == 1)
		{
			result[0] = prefix[1];
			return ((result = place_before(result, "0")));
		}
		ft_memcpy(result, prefix, 2);
		return (result);
	}
	else if (result[0] == ' ')
	{
		i = 2;
		while (result[0] == ' ' && i)
			place_at_lastsp(result, prefix[--i]);
		prefix[2 - i] = '\0';
		(void)(i && (result = place_before(result, &prefix[i - 1])));
		return (result);
	}
	return (place_before(result, prefix));
}

char	*apply_hash_oct(char *result, int width)
{
	if (result[0] == '0' && width > 0)
	{
		result[0] = '0';
		return (result);
	}
	else if (result[0] == ' ')
	{
		place_at_lastsp(result, '0');
		return (result);
	}
	return (place_before(result, "0"));
}

char	*apply_hash(int *flags, char *result, int conv, int width)
{
	char	prefix[3];

	if (!IS_ON(*flags, HASH) || !result)
		return (result);
	if (conv == HEX || conv == BHEX)
	{
		conv == HEX ? ft_strcpy(prefix, "0x") : ft_strcpy(prefix, "0X");
		result = apply_hash_hex(result, width, prefix);
	}
	else if (conv == OCTAL)
		result = apply_hash_oct(result, width);
	return (result);
}

/*
**int		main(void)
**{
**	char	*s;
**
**	s = ft_strdup("bonjour");
**	printf("[%s]\n", apply_hash(0, s, HEX, 2));
**	s = ft_strdup(" bonjour");
**	printf("[%s]\n", apply_hash(0, s, HEX, 2));
**	s = ft_strdup("0bonjour");
**	printf("[%s]\n", apply_hash(0, s, HEX, 1));
**	s = ft_strdup("00bonjour");
**	printf("[%s]\n", apply_hash(0, s, HEX, 2));
**	return (0);
**}
*/
