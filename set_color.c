/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 21:44:49 by fokrober          #+#    #+#             */
/*   Updated: 2019/09/29 21:35:17 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_color(char *color)
{
	static char	*colors[13] = {"reset", "red", "bold red", "green",
		"bold green", "yellow", "bold yellow", "blue", "bold blue", "magenta",
		"bold magenta", "cyan", "bold cyan"};
	
	color = ft_downcase(color);
	i = 0;
	while (i < 13)
	{
		if (!ft_strcmp(color, colors[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	set(int color_id)
{
	char	*fmt;
	int		rep;

	if (color_id == -1)
		return ;
	else if (!color_id)
	{
		write(1, "\e[0m", 4);
		return ;
	}
	rep = (color_id % 2 == 0);
	while (fmt[i])
	{
		(void)((fmt[i] == '[') && (fmt[i + 1] = '0' + rep));
		(void)((fmt[i] == 'm') && (fmt[i - 1] = '0' + (color_id - rep)));
		i++;
	}
	write(1, fmt, ft_strlen(fmt));
}

int		set_color(char *fmt)
{
	int		color_id;
	char	*color;
	int		i;

	i = 0;
	if (s[i] == '{')
	{
		while (s[i] == '}' && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (0);
		if (!(color = ft_strsub(fmt, 0, i)))
			return (0);
		color_id = find_color(color);
		set(color_id);
	}
	if (color_id != -1)
		return (i);
	return (0);
}
