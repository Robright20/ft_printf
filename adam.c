/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:32:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/04 18:23:43 by nkhribec         ###   ########.fr       */
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

int		ft_putunbr(unsigned long long n, int flag, int precision, int width)//also handle h, hh, l, ll
{
	char				*ret;
	int					i;
	unsigned long long	tmp;

	tmp = n;
	i = 0;
	while (tmp)
	{
		tmp /= 10;
		i++;
	}
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	ft_putendl(ret);
	ft_print(&ret, flag, precision, width);
	ft_strdel(&ret);
	return (0);
}

int		ft_putdnbr(long long n, int flag, int precision, int width)//also handle h, hh, l, ll
{
	char			*ret;
	int				i;
	unsigned long long		tmp;
	int				size;

	tmp = n < 0 ? -n : n;
	i = 0;
	while (tmp)
	{
		tmp /= 10;
		i++;
	}
	size = i + (is_on(flag, PLUS) || (n < 0)) +\
		   ((is_on(flag, SPACE)) && !(is_on(flag, PLUS)) && (n >= 0));
	if (!(ret = ft_memalloc(sizeof(char) * (i + 1))))
		return (0);
	if (size > i)
	{
		ret[0] = (is_on(flag, PLUS)) ? '+' : '^';
		ret[0] = (n < 0) ? '-' : ret[0];
	}
	tmp = n < 0 ? -n : n;
	while (tmp)
	{
		ret[size - 1] = tmp % 10 + '0';
		tmp /= 10;
		size--;
	}
	printf("%d\n", size);
	ft_putendl(ret);
	ft_print(&ret, flag, precision, width);
	ft_strdel(&ret);
	return (0);
}

int		ft_putonbr(unsigned long long n, int flag, int precision, int width)//also handle h, hh, l, ll
{
	char				*ret;
	int					i;
	unsigned long long	tmp;

	tmp = n;
	i = 0;
	while (tmp)
	{
		tmp /= 8;
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
	ft_print(&ret, flag, precision, width);
	ft_strdel(&ret);
	return (0);
}

int		ft_putxnbr(unsigned long long n, int flag, int precision, int width)//also handle h, hh, l, ll
{
	char					*s;
	char					*ret;
	int						i;
	unsigned long long		tmp;

	s = "0123456789abcdef";
	tmp = n;
	i = 0;
	while (tmp)
	{
		tmp /= 16;
		i++;
	}
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	printf("%s\n", ret);
	while (n)
	{
		ret[i - 1] = s[n % 16];
		n /= 16;
		i--;
	}
	ft_print(&ret, flag, precision, width);
	ft_strdel(&ret);
	return (0);
}

int		ft_putXnbr(unsigned long long n, int flag, int precision, int width)//also handle h, hh, l, ll
{
	char	*s;
	char	*ret;
	int		i;
	unsigned long long		tmp;

	s = "0123456789ABCDEF";
	tmp = n;
	i = 0;
	while (tmp)
	{
		tmp /= 16;
		i++;
	}
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i - 1] = s[n % 16];
		n /= 16;
		i--;
	}
	ft_print(&ret, flag, precision, width);
	ft_strdel(&ret);
	return (0);
}

int 	main()
{
	unsigned int	flag = 0;

	//set_flag(flag, HASH);
	//set_flag(flag, PLUS);
	//set_flag(flag, MINUS);
	//set_flag(flag, SPACE);
	set_flag(flag, ZERO);
	//set_flag(flag, PRECISION);
	set_flag(flag, d);
	printb(flag);
	ft_putdnbr(18, flag, 1, 7);
	//printf("hexa |%#5x|\n", 100);
}
