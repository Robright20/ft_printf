/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:47:25 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/13 23:14:02 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**le 0 de l'octal n'est pas compter comme prefix quand on veut traiter la
**precision
*/

int		get_prefix_len(int flag, char *s)
{
	return (IS_ON(flag, PLUS) && (IS_ON(flag, DEC) || IS_ON(flag, IDEC))) +\
	((IS_ON(flag, HASH) && (IS_ON(flag, HEX) || IS_ON(flag, BHEX))) * 2) +\
	((s[0] == '-' || s[0] == '^') && !(IS_ON(flag, PLUS)));
}

char	*ft_realloc(char **s, size_t size)
{
	char	*tmp;

	tmp = *s;
	*s = (char*)ft_strnew(sizeof(char) * size);
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
	int		p_len;// 0x 0X 0
	
	p_len = get_prefix_len(flag, *s);
	*s = ft_realloc(s, precision + p_len);
	*s += p_len;
	shift(*s, shift_value);
	blacktozero(*s, shift_value);
	*s -= p_len;
}

void	ft_get_precision(char **s, int precision, int p_len, int len)
{
	int	shift_value;
	
	shift_value = precision - len;
	*s += p_len;
	shift(*s, shift_value);
	blacktozero(*s, shift_value);
	*s -= p_len;
}

void	fwidth(char **s, int flag, int precision, int width)
{
	int		len;
	int		shift_value;
	int		p_len;// +0x +0X +0
	int		take_space;
	
	*s = ft_realloc(s, width);
	p_len = get_prefix_len(flag, *s);
	take_space = !(IS_ON(flag, PLUS)) && (IS_ON(flag, SPACE)) && *s[0] == '^';
	len = (int)ft_strlen(*s) - p_len;
	if (precision > len)
		ft_get_precision(s, precision, p_len, len);//complete with 0000 after prefix
	len = (int)ft_strlen(*s);
	*s = *s + take_space;
	if (!(IS_ON(flag, MINUS)))
	{
		shift(*s, width - len);
		if (IS_ON(flag, ZERO) && !(IS_ON(flag, PRECISION)))// precision override 0 flag
			blacktozero(*s, width - len);
	}
	else
		nulltoblack(*s, width);
	*s = *s - take_space;
}

int		is_nbr(char c)
{
	return(c >= '0' && c <= '9');
}

void	addquote(char **s, int flag, int size)
{
	int		here;
	int		i;
	int		j;
	int		quotnbr;
	char	*tmp;

	quotnbr = (size - 1) / 3;
	if (!quotnbr)
		return ;
	tmp = *s;
	*s = (char*)ft_strnew(sizeof(char) * (ft_strlen(tmp) + quotnbr));
	i = ft_strlen(tmp) - 1;
	j = i + quotnbr;
	here = 0;
	while (i >= 0)
	{
		if (here && !(here % 3) && is_nbr(tmp[i]))
			(*s)[j--] = ',';
		(*s)[j--] = tmp[i--];
		here++;
	}
	printf("apres s = %s\n", *s);
	ft_strdel(&tmp);

}

int		ft_print(char **s, int flag, int precision, int width)
{
	int		len;
	int		p_len;

	if (IS_ON(flag, QUOTE) && (IS_ON(flag, DEC) || IS_ON(flag, IDEC) || IS_ON(flag, UINT)))
	{
		p_len = get_prefix_len(flag, *s);
		len = (int)ft_strlen(*s);
		addquote(s, flag, (len - p_len));
	}
	p_len = get_prefix_len(flag, *s);
	len = (int)ft_strlen(*s);
	if (precision > (len - p_len) && precision > width)
		fprecision(s, flag, precision, precision - (len - p_len));
	else if (width >= len)
		fwidth(s, flag, precision, width);
	ft_putstr(*s);
	len = ft_strlen(*s);
	ft_strdel(s);
	return (len);
}

