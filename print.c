/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:47:25 by nkhribec          #+#    #+#             */
/*   Updated: 2019/09/28 22:38:19 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//char	*ft_increment_size()
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
	//printf("i = %d\n", i);
	while (--i >= 0)
		s[i + shift_value] = s[i];
	while (--shift_value >= 0)
		s[shift_value] = '^';
}

void	fprecision(char **s, int flag, int precision, int shift_value)
{
	char	*tmp;
	int		avoid_prefix;// 0x 0X 0
	
	//avoid_prefix =  is_on(flag, PLUS) + (is_on(flag, HASH) && is_on(flag, OCTAL)) +\
					(is_on(flag, HASH) && (is_on(flag, X) || is_on(flag, x)) * 2) + (*s[0] == '-')\
					+ ((is_on(flag, DEC1) || is_on(flag, DEC2)) && (*s[0] != '-'));
	avoid_prefix =  (is_on(flag, PLUS)) + ((is_on(flag, HASH)) && (is_on(flag, OCTAL))) +\
					((is_on(flag, HASH) && ((is_on(flag, X)) || (is_on(flag, x)))) * 2) +\
					((*s[0] == '-' || *s[0] == '^') && !(is_on(flag, PLUS)));
	printf("preci$$$$%d\n", avoid_prefix);
	tmp = *s;
	*s = ft_memalloc(sizeof(char) * (precision + avoid_prefix + 1));
	ft_strcpy(*s, tmp);
	ft_strdel(&tmp);
	*s += avoid_prefix;
	shift(*s, shift_value);
	blacktozero(*s, shift_value);
	*s -= avoid_prefix;
}

void	fwidth(char **s, int flag, int precision, int width)
{
	char	*tmp;
	int		len;
	int		shift_value;
	int		avoid_prefix;// +0x +0X +0
	int		take_space;
	
	avoid_prefix =  (is_on(flag, PLUS)) + ((is_on(flag, HASH)) && (is_on(flag, OCTAL))) +\
					((is_on(flag, HASH) && ((is_on(flag, X)) || (is_on(flag, x)))) * 2) +\
					((*s[0] == '-') && !(is_on(flag, PLUS)));
	
	//printf("5$$$$$$$$%d\n", avoid_prefix);
	
	take_space = !(is_on(flag, PLUS)) && (is_on(flag, SPACE)) && *s[0] == '^';
	printf("take_space = %d\n", take_space);

	len = (int)ft_strlen(*s) - avoid_prefix;
	tmp = *s;
	*s = ft_memalloc(sizeof(char) * (width + 1));
	ft_strcpy(*s, tmp);
	ft_strdel(&tmp);
	shift_value = len > precision ? 0 : precision - len;
	*s += avoid_prefix;
	*s = *s + take_space;
	shift(*s, shift_value);
	blacktozero(*s, shift_value);
	*s -= avoid_prefix;
	//printf("shift value = %d\n", shift_value);
	len = (int)ft_strlen(*s) + take_space;
	printf("******%s\n", *s);
	if (!(is_on(flag, MINUS)))
	{
		shift(*s, width - len);
		if (is_on(flag, ZERO))
			blacktozero(*s, width - len);
	}
	else
		nulltoblack(*s, width);
	*s = *s - take_space;
	printf("******%s\n", *s);
}

int		ft_print(char **s, int flag, int precision, int width)
{
	int		len;
	int		prefix_len;

	prefix_len =  (is_on(flag, PLUS)) + ((is_on(flag, HASH)) && (is_on(flag, OCTAL))) +\
				  ((is_on(flag, HASH) && ((is_on(flag, X)) || (is_on(flag, x)))) * 2) +\
				  (*s[0] == '-' && !(is_on(flag, PLUS)));
	//printf("5$$$$$$$$%d\n", prefix_len);
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

