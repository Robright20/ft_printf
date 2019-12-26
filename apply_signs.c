/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_signs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:36:13 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/26 13:58:48 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*place_before(char *result, char *prefix, int xbool)
{
	char	*new_result;
	int		len;
	int		p_len;

	len = ft_strlen(result);
	p_len = ft_strlen(prefix);
	if (xbool)
	{
		ft_memmove(result + p_len, result, len - p_len);
		ft_memcpy(result, prefix, p_len);
		return (result);
	}
	if (!(new_result = ft_strnew(len + p_len)))
		return (NULL);
	ft_memcpy(new_result, prefix, p_len);
	ft_memcpy(&new_result[p_len], result, len);
	ft_strdel(&result);
	return (new_result);
}

char	*place_at_lastsp(char *new_result, int sign, int flags)
{
	char	*tmp;

	int	i = 0;

	while (new_result[i] == ' ')
		i++;
	if (!new_result[i] && IS_ON(flags, MINUS))
		new_result[0] = sign;
	else if (i > 0 && new_result[i] != '-')
	{
		if (IS_ON(flags, OCTAL) && new_result[i] == '0')
			return (new_result);
		new_result[i - 1] = sign;
	}
	return (new_result);
}

char	*apply_space(char *result, int diff, int flags)
{
	int		xbool;

	xbool = (diff > 0 && IS_ON(flags, MINUS));
	if (result[0] == '0')
	{
		if (diff > 0 && !IS_ON(flags, MINUS))
			result[0] = ' ';
		else
			return (place_before(result, " ", xbool));
	}
	else if (result[0] != '-' && result[0] != ' ')
		return (place_before(result, " ", xbool));
	return (result);
}

char	*apply_plus(char *result, int diff, int flags)
{
	int		xbool;

	xbool = (diff > 0 && IS_ON(flags, MINUS));
	if (result[0] == '0')
	{
		if (diff > 0 && !IS_ON(flags, MINUS))
			result[0] = '+';
		else
			return (place_before(result, "+", xbool));
	}
	else if (result[0] == ' ')
		return (place_at_lastsp(result, '+', flags));
	else if (result[0] != '-')
		return (place_before(result, "+", xbool));
	return (result);
}

char	*apply_signs(int *flags, char *result, int conv, int diff)
{
	char	*new_result;

	new_result = result;
	if (!(conv == DEC || conv == IDEC) && !(conv >= XFLOAT && conv <= GEXPO))
		return (result);
	if (IS_ON(*flags, SPACE))
		new_result = apply_space(result, diff, *flags);
	if (IS_ON(*flags, PLUS))
		new_result = apply_plus(new_result, diff, *flags);
	return (new_result);
}

/*
**int		main(void)
**{
**	char	*s;
**	char	*rep;
**	int		flags;
**
**	flags = 0;
**	//
**	s = ft_strnew(7);
**	ft_strcpy(s, "bonjour");
**	rep = place_before(s, "+");
**	printf("s [%s]\nrep [%s]\n", s, rep);
**	ft_strdel(&rep);
**	s = ft_strnew(8);
**	ft_strcpy(s, " bonjour");
**	rep = place_at_lastsp(s, '+');
**	printf("s [%s]\nrep [%s]\n", s, rep);
**
**	s = ft_strnew(10);
**	ft_strcpy(s, "  -bonjour");
**	rep = place_at_lastsp(s, '+');
**	printf("s [%s]\nrep [%s]\n", s, rep);
**	/
**	SET_FLAG_ON(flags, PLUS);
**	SET_FLAG_ON(flags, SPACE);
**	//s = ft_strdup("001");
**	//s = ft_strdup("-001");
**	//s = ft_strdup(" 1");
**	//s = ft_strdup("   1");
**	s = ft_strdup("001");
**	rep = apply_signs(&flags, s, DEC, 1);
**	printf("[%s]\n", rep);
**	return (0);
**}
*/
