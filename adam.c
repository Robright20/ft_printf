/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:32:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/09/28 11:24:20 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void            printb(unsigned int c)
{
	int             i;
	unsigned int	m;

	i = 32;
	while (--i > -1)
	{
		m = (((c & (1 << i)) >> i) + '0');
		write(1, &m, 1);
	}
	write(1, "\n", 1);
}

int		ft_putdnbr(int n, int flag, int precision, int width)
{
	char			*ret;
	int				i;
	unsigned int	a;

	a = n < 0 ? -n : n;
	i = 0;
	while (a)
	{
		a /= 10;
		i++;
	}
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	a = n < 0 ? -n : n;
	while (a)
	{
		ret[i - 1] = a % 10 + '0';
		a /= 10;
		i--;
	}
	if (n < 0)
		ret[0] = '-';
	printf("s2 = %s\n", ret);
	ft_putendl(ret);
	ft_print(&ret, flag, precision, width);
	ft_strdel(&ret);
	return (0);
}

int		ft_putonbr(unsigned int n, int flag, int precision, int width)
{
	char			*ret;
	int				i;
	unsigned int	a;

	a = n;
	i = 0;
	while (a)
	{
		a /= 8;
		i++;
	}
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i - 1] = n % 8 + '0';
		n /= 8;
		i--;
	}
	ft_putendl(ret);
	ft_print(&ret, flag, precision, width);
	ft_strdel(&ret);
	return (0);
}

int		ft_putxnbr(unsigned int n, int flag, int precision, int width)
{
	char	*s;
	char	*ret;
	int		i;
	int		a;

	s = "0123456789abcdef";
	a = n;
	i = -1;
	i = 0;
	while (a)
	{
		a /= 16;
		i++;
	}
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	printf("%s\n", ret);
	a = i;
	while (n)
	{
		ret[i - 1] = s[n % 16];
		n /= 16;
		i--;
	}
	ft_print(&ret, flag, precision, width);
	ft_strdel(&ret);
	return (a);
}

int		ft_putXnbr(unsigned int n, int flag, int precision, int width)
{
	char	*s;
	char	*ret;
	int		i;
	int		a;

	s = "0123456789ABCDEF";
	a = n;
	i = -1;
	i = 0;
	while (a)
	{
		a /= 16;
		i++;
	}
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	a = i;
	while (n)
	{
		ret[i - 1] = s[n % 16];
		n /= 16;
		i--;
	}
	ft_print(&ret, flag, precision, width);
	ft_strdel(&ret);
	return (a);
}

int 	main()
{
	unsigned int	flag = 0;

	//set_flag(flag, HASH);
	set_flag(flag, PLUS);
	//set_flag(flag, MINUS);
	//set_flag(flag, SPACE);
	set_flag(flag, ZERO);
	set_flag(flag, OCTAL);
	printb(flag);
	ft_putonbr(11248, flag, 6, 6);
	//printf("hexa |%#5x|\n", 100);
}
