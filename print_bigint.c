/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bigint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:11:44 by mzaboub           #+#    #+#             */
/*   Updated: 2019/11/23 20:11:21 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "ft_printf.h"

void	print_bigint(t_bigint bb, int dec_pos, long long sign, t_fwp flg)
{
	int		i;
	int		nb_pad;
	int		nbr_width;
	int		pre;
	char	*str;

	pre = 6;
	i = 0;
	str = precision(&bb, dec_pos, sign, flg);
//	ft_putstr("first print :\t"); ft_putstr(str); write(1, ";\n", 2);
	str = add_padding(str, flg, sign);
//	ft_putstr("sec print   :\t"); ft_putstr(str); write(1, ";\n", 2);
	last_flags(&str, flg);// add +, ' ' flags
	ft_putstr("third print :\t"); ft_putstr(str); write(1, ";\n", 2);
}

/*
 ** ----------------------------------------------
 */

char	*precision(t_bigint *bb, int dec_pos, long long sign, t_fwp flg)
{
	int		i;
	int		n;
	char	*str;
	int		j;
	int 	pre;

	i = 0;
	pre = flg.precision;
	while (bb->tab[i] == 0 && i + 1 < dec_pos)
		i++;
	n = pre + dec_pos - i;

	if (flg.precision > 0)
		rounding(bb, dec_pos + flg.precision);
	(flg.precision == 0 && IS_FLAG_ON(flg.flags, HASH)) ? (str = ft_strnew(n + 2)) : (str = ft_strnew(n + 1));
	j = 0;
	while (i < dec_pos + pre)
	{
		if (i == dec_pos)
			str[j++] = '.';
		str[j] = bb->tab[i] + '0';
		i++;
		j++;
	}
	if (IS_FLAG_ON(flg.flags, HASH) && flg.precision == 0)
			str[j] = '.';
	return (str);
}

/*
 ** ----------------------------------------------
 */

char	*add_padding(char *str, t_fwp flg, long long sign)
{
	int		len;
	char	*buff;
	int		i;
	char	pad;

	i = 0;
	len = ft_strlen(str);

	if (flg.width < len && sign == -1)
		buff = ft_strnew(len + 1);
	else if (flg.width < len)
		buff = ft_strnew(len);
	else
		buff = ft_strnew(flg.width);

	if (sign == -1)
		add_pad_neg(buff, flg, str, len); 
	else
		add_pad_pos(buff, flg, str, len);
	ft_strdel(&str);
	return (buff);
}

void	add_pad_neg(char *buff, t_fwp flg, char *str, int len)
{
	char 	pad;
	int		i;

	i = 0;
	if (IS_FLAG_ON(flg.flags, MINUS))
	{
		buff[0] = '-';
		ft_strcpy(buff + 1, str);		
		while (len + 1< flg.width)
			buff[len++ + 1] = ' ';
	}
	else
	{
		if (IS_FLAG_ON(flg.flags, ZERO))
		{
			buff[0] = '-';
			i = 1;
			while (i < (flg.width - len))
				buff[i++] =  '0';
			ft_strcpy(buff + i, str);
		}
		else
		{
			i = 0;
			while (i + 1 < (flg.width - len))
				buff[i++] =  ' ';
			buff[i] = '-';
			ft_strcpy(buff + i + 1, str);
		}
	}
}


void	add_pad_pos(char *buff, t_fwp flg, char *str, int len)
{
	char	pad;
	int		i;

	i = 0;
	if (IS_FLAG_ON(flg.flags, MINUS))
	{
		ft_strcpy(buff, str);		
		while (len + 1< flg.width)
			buff[len++] = ' ';
	}
	else
	{
		(IS_FLAG_ON(flg.flags, ZERO)) ? pad = '0' : (pad = ' ');
		while (i < (flg.width - len))
			buff[i++] =  pad;
		ft_strcpy(buff + i, str);
	}
}

void	last_flags(char **str, t_fwp flg)
{
	char *buff;
	if ((*str)[0] != '-')
	{
		if (IS_FLAG_ON(flg.flags, PLUS) && (*str)[0] == '0' && (*str)[1] != '.')
			(*str)[0] = '+';
		else if (IS_FLAG_ON(flg.flags, PLUS))
		{
			buff = ft_strnew(ft_strlen(*str) + 1);
			buff[0] = '+';
			ft_strcpy(buff + 1, *str);
			ft_strdel(str);
			(*str) = buff;
		}
		else if (IS_FLAG_ON(flg.flags, SPACE) && (*str)[0] == '0')
			(*str)[0] = '+';
		else if (IS_FLAG_ON(flg.flags, SPACE) && (*str)[0] != '0')
		{
			buff = ft_strnew(ft_strlen(*str) + 1);
			buff[0] = '+';
			ft_strcpy(buff + 1, *str);
			ft_strdel(str);
			(*str) = buff;
		}

	}
}

void	rounding(t_bigint *bb, int i)
{
	if (bb->tab[i] >= 5)
		bb->tab[i - 1] += 1;
	edit_carry_on(bb);
}
