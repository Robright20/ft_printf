/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:09:20 by fokrober          #+#    #+#             */
/*   Updated: 2019/09/22 21:47:57 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_flag(char *flags, char *format, int argw)
{
	char	*s;
	int		pos;

	s = ARGS_BUF;
	pos = 0;
	while (*s)
	{
		if (ft_strnstr(s, format, argw) == argw)
		{
			if (s[0] != s[argw])
			{
				flags[pos] = 1;
				break ;
			}
			else
				s += argw;
		}
		s += first_char_nbr(s);
		pos++;
	}
}

int		ft_strnstr(char *s1, char *s2, int n)
{
	int		rep;

	rep = n;
	while (n)
	{
		if ((*s1 && *s2))
		{
			if (*s1 != *s2)
				return (0);
		}
		else
			return (*s1 == *s2);
		(void)(s1++ && s2++ && n--);
	}
	return (rep);
}

void	save_all_flags(char *flags, char *args)
{
	int		o;

	while (*args)
	{
		o = first_char_nbr(args);
		save_flag(flags, args, o);
		args += o;
	}
}

int		first_char_nbr(char *s)
{
	int		rep;
	int		i;

	rep = 1;
	i = 1;
	while (s[i] && (s[0] == s[i++]))
		rep++;
	return (rep);
}
