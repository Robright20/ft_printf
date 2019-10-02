/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 22:23:12 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/01 22:57:02 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_flag(int *flags, char *format)
{
	char	*s;
	int		pos;

	if ((pos = find_flag(ARG_BUF, format)) == -1)
		return ;
	SET_FLAG_ON(flags, pos);
}

int		find_flag(char *s, char *format)
{
	int		pos;
	int		argw;

	pos = 0;
	while (*s)
	{
		argw = first_char_nbr(s);
		if (ft_strncmp(s, format, argw) == argw)
		{
			if (s[0] != s[argw])
				return (pos);
			else
				s += argw;
		}
		s += argw;
		pos++;
	}
	return (-1);
}

int		first_char_nbr(char *s)
{
	int		i;
	int		rep;

	(void)((i = 1) && (rep = 1));
	while (s[i] && (s[0] == s[i++]))
		rep++;
	return (rep);
}

int		is_conv_spec(char c, char *args)
{
	int		i;

	i = 0;
	while (i < CONV_BOUND)
	{
		if (args[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
