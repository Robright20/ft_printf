/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc_and_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 02:08:32 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/27 22:24:24 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putc(va_list ap, int flags, int precision, int width)
{
	unsigned char	c;
	int		ret;

	(void)precision;
	c = (char)va_arg(ap, int);
	//printf("\nc == ;;%c;;\n", c);
	if (width < 0)
	{
		width *= -1;
		SET_FLAG_ON(flags, MINUS);
	}
	if (width > 0 && IS_ON(flags, MINUS))
	{
		write(1, &c, 1);
		ret = width;
		while (--width)
			write(1, " ", 1);
		return (ret);
	}
	else if (width > 0 && !IS_ON(flags, MINUS))
	{
		ret = width;
		while (--width)
			write(1, " ", 1);
		write(1, &c, 1);
		return (ret);
	}
	else
		write(1, &c, 1);
	return (1);
}

int		ft_put_char(char c, int flags, int width)
{
	char	pad;
	int		ret;

	if (width > 0 && IS_ON(flags, MINUS))
	{
		write(1, &c, 1);
		ret = width;
		while (--width)
			write(1, " ", 1);
		return (ret);
	}
	else if (width > 0 && !IS_ON(flags, MINUS))
	{
		pad = IS_ON(flags, ZERO) ? '0' : ' ';
		ret = width;
		while (--width)
			write(1, &pad, 1);
		write(1, &c, 1);
		return (ret);
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
		s = ft_strdup("(null)");
	s = ft_strdup(s);
	SET_FLAG_ON(flags, STRING);
	s = build_result(flags, s, precision, width);
	return (ft_putxstr(s));
}
