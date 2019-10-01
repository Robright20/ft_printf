/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 22:23:12 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/01 22:28:16 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strncmp(char *s1, char *s2, int n);
int		first_char_nbr(char *s);
int		find_flag(char *s, char *format);

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
