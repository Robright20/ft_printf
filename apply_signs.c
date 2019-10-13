/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_signs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:36:13 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/13 04:19:59 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*place_before(char *result, char *prefix)
{
	char	*new_result;
	int		len;
	int		p_len;

	len = ft_strlen(result);
	p_len = ft_strlen(prefix);
	if (!(new_result = ft_strnew(len + p_len)))
		return (NULL);
	ft_memcpy(new_result, prefix, p_len);
	ft_memcpy(&new_result[p_len], result, len);
	ft_strdel(&result);
	return (new_result);
}

char	*place_at_lastsp(char *new_result, int sign)
{
	char	*tmp;

	if (!(tmp = ft_strrchr(new_result, ' ')) || tmp[1] == '-')
		return (new_result);
	tmp[0] = sign;
	return (new_result);
}

char	*apply_space(char *new_result, int width)
{
	if (new_result[0] == '0')
	{
		if (width > 0)
			new_result[0] = ' ';
		else
			return (place_before(new_result, " "));
	}
	else if (new_result[0] == ' ')
		return (place_at_lastsp(new_result, ' '));
	else if (new_result[0] != '-')
		return (place_before(new_result, " "));
	return (new_result);
}

char	*apply_plus(char *new_result, int width)
{
	if (new_result[0] == '0')
	{
		if (width > 0)
			new_result[0] = '+';
		else
			return (place_before(new_result, "+"));
	}
	else if (new_result[0] == ' ')
		return (place_at_lastsp(new_result, '+'));
	else if (new_result[0] != '-')
		return (place_before(new_result, "+"));
	return (new_result);
}

char	*apply_signs(int *flags, char *result, int conv, int width)
{
	char	*new_result;

	new_result = result;
	if (!(conv == DEC || conv == IDEC) && !(conv >= XFLOAT && conv <= GEXPO))
		return (result);
	//printf("%d\n", conv);
	if (IS_ON(*flags, SPACE))
		new_result = apply_space(result, width);
	if (IS_ON(*flags, PLUS))
		new_result = apply_plus(new_result, width);
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
