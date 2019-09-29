/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:47:25 by nkhribec          #+#    #+#             */
/*   Updated: 2019/09/29 20:56:35 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_realloc(char **s, size_t size)
{
	char	*tmp;

	tmp = *s;
	*s = ft_memalloc(sizeof(char) * size);
	ft_strcpy(*s, tmp);
	ft_strdel(&tmp);
	return (*s);
}

void	nulltoblack(char *s, int until)
{
	while (until)
	{
		if (!*s)
			*s = '^';
		s++;
		until--;
	}
}

void	blacktozero(char *s, int until)
{
	while (until)
	{
		if (*s == '^')
			*s = '0';
		s++;
		until--;
	}
}

void	shift(char *s, int shift_value)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (--i >= 0)
		s[i + shift_value] = s[i];
	while (--shift_value >= 0)
		s[shift_value] = '^';
}

void	fprecision(char **s, int flag, int precision, int shift_value)
{
	int		prefix_len;// 0x 0X 0
	
	prefix_len =  (is_on(flag, PLUS)) + ((is_on(flag, HASH)) && (is_on(flag, OCTAL))) +\
				  ((is_on(flag, HASH) && ((is_on(flag, X)) || (is_on(flag, x)))) * 2) +\
				  ((*s[0] == '-' || *s[0] == '^') && !(is_on(flag, PLUS)));
	*s = ft_realloc(s, precision + prefix_len + 1);
	*s += prefix_len;
	shift(*s, shift_value);
	blacktozero(*s, shift_value);
	*s -= prefix_len;
}

void	ft_get_precision(char **s, int precision, int prefix_len, int len)
{
	int	shift_value;
	
	shift_value = precision - len;
	*s += prefix_len;
	shift(*s, shift_value);
	blacktozero(*s, shift_value);
	*s -= prefix_len;
}

void	fwidth(char **s, int flag, int precision, int width)
{
	int		len;
	int		shift_value;
	int		prefix_len;// +0x +0X +0
	int		take_space;
	
	*s = ft_realloc(s, width + 1);
	prefix_len = (is_on(flag, PLUS)) + ((is_on(flag, HASH)) && (is_on(flag, OCTAL))) +\
				 ((is_on(flag, HASH) && ((is_on(flag, X)) || (is_on(flag, x)))) * 2) +\
				 ((*s[0] == '-' || *s[0] == '^') && !(is_on(flag, PLUS)));
	take_space = !(is_on(flag, PLUS)) && (is_on(flag, SPACE)) && *s[0] == '^';
	len = (int)ft_strlen(*s) - prefix_len;
	if (precision > len)
		ft_get_precision(s, precision, prefix_len, len);//complete with 0000 after prefix
	len = (int)ft_strlen(*s);
	*s = *s + take_space;
	if (!(is_on(flag, MINUS)))
	{
		shift(*s, width - len);
		if (is_on(flag, ZERO))
			blacktozero(*s, width - len);
	}
	else
		nulltoblack(*s, width);
	*s = *s - take_space;
}

int		ft_print(char **s, int flag, int precision, int width)
{
	int		len;
	int		prefix_len;

	prefix_len =  (is_on(flag, PLUS)) + ((is_on(flag, HASH)) && (is_on(flag, OCTAL))) +\
				  ((is_on(flag, HASH) && ((is_on(flag, X)) || (is_on(flag, x)))) * 2) +\
				  ((*s[0] == '-' || *s[0] == '^') && !(is_on(flag, PLUS)));
	len = (int)ft_strlen(*s);
	if (precision >= (len - prefix_len) && precision >= width)
	{
		printf("-----pppp----    aa%s------\n", *s);
		fprecision(s, flag, precision, precision - (len - prefix_len));
		ft_putendl(*s);
		ft_strdel(s);
		return (precision);
	}
	if (width >= len && width >= precision)
	{
		printf("------www--     aa%s--------\n", *s);
				fwidth(s, flag, precision, width);
		ft_putendl(*s);
		ft_strdel(s);
		return (width);
	}
	ft_putendl(*s);
	ft_strdel(s);
	return (len);
}

