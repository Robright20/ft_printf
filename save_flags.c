/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 22:23:12 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/05 13:38:43 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		save_flag(int *flags, char *format)
{
	int		pos;
	int		fw;

	fw = first_char_count(format);
	if ((pos = find_flag(FLAGS_BUF, format, fw)) == -1)
	{
		if ((pos = find_flag(FLAGS_BUF, format, 1)) != -1)
		{
			SET_FLAG_ON(*flags, pos);
			return (fw);
		}
		return (0);
	}
	SET_FLAG_ON(*flags, pos);
	return (fw);
}

int		find_flag(char *flag_lst, char *format, int flagw)
{
	int		pos;
	int		flagw_orig;

	pos = 0;
	while (*flag_lst)
	{
		flagw_orig = first_char_count(flag_lst);
		if (flagw == flagw_orig && ft_strncmp(flag_lst, format, flagw) == 0)
			return (pos);
		flag_lst += flagw_orig;
		pos++;
	}
	return (-1);
}

int		first_char_count(char *s)
{
	int		i;
	int		rep;

	i = 1;
	rep = 1;
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
