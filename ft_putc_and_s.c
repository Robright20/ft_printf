/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc_and_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 02:08:32 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/13 05:23:41 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putc(va_list ap, int flags, int precision, int width)
{
	char	c;

	(void)precision;
	c = (char)va_arg(ap, int);
	if (width > 0 && IS_ON(flags, MINUS))
	{
		write(1, &c, 1);
		while (--width)
			write(1, " ", 1);
		return (width);
	}
	else if (width > 0 && !IS_ON(flags, MINUS))
	{
		while (--width)
			write(1, " ", 1);
		write(1, &c, 1);
		return (width);
	}
	else
		write(1, &c, 1);
	return (1);
}

int		ft_puts(va_list ap, int flags, int precision, int width)
{
	char	*s;
	int		len; 

	s = va_arg(ap, char*);
	if (!s)
	{
		write(1, "null", 4);
		return (4);
	}
	s = ft_strdup(s);
	//len = (ft_strlen(s) < precision) ? ft_strlen(s) : precision; 
	//printf("[precision = %d]\n", precision);
	//printf("[strlen = %zu]\n", ft_strlen(s));
	//printf("[len = %d]\n", len);

	apply_width(&flags, s, (int)'s', width);
	write(1, s, ft_strlen(s));

/*
	if (width > len && IS_ON(flags, MINUS))
	{
		write(1, s, len);
		width -= len;
		while (width--)
			write(1, " ", 1);
		return (width);
	}
	else if (width > len && !IS_ON(flags, MINUS))
	{
		width -= len;
		while (width--)
			write(1, " ", 1);
		write(1, s, len);
		return (width);
	}
	else
		write(1, s, len);
*/
	return (1);
}
