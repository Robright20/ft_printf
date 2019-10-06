/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:32:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/06 15:47:29 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	printb(unsigned int c)
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
	while (tmp && ++i)
		tmp /= 10;
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (ft_print(&ret, flag, precision, width));
}

int		ft_putdnbr(long long n, int flag, int precision, int width)
{
	char					*ret;
	int						i;
	unsigned long long		tmp;
	int						size;

	tmp = n < 0 ? -n : n;
	i = 0;
	while (tmp && ++i)
		tmp /= 10;
	size = i + (is_on(flag, PLUS) || (n < 0)) +\
		   ((is_on(flag, SPACE)) && !(is_on(flag, PLUS)) && (n >= 0));
	if (!(ret = ft_strnew(sizeof(char) * (i + 1))))
		return (0);
	if (size > i)
	{
		ret[0] = (is_on(flag, PLUS)) ? '+' : '^';
		ret[0] = (n < 0) ? '-' : ret[0];
	}
	tmp = n < 0 ? -n : n;
	while (tmp)
	{
		ret[size-- - 1] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (ft_print(&ret, flag, precision, width));
}

int		ft_putonbr(unsigned long long n, int flag, int precision, int width)
{
	char				*ret;
	int					i;
	unsigned long long	tmp;

	tmp = n;
	i = 0;
	while (tmp && ++i)
		tmp /= 8;
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i-- - 1] = n % 8 + '0';
		n /= 8;
	}
	return (ft_print(&ret, flag, precision, width));
}

int		ft_putxnbr(unsigned long long n, int flag, int precision, int width)
{
	char					*s;
	char					*ret;
	int						i;
	unsigned long long		tmp;

	s = "0123456789abcdef";
	tmp = n;
	i = 0;
	while (tmp && ++i)
		tmp /= 16;
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i-- - 1] = s[n % 16];
		n /= 16;
	}
	return (ft_print(&ret, flag, precision, width));
}

int		ft_putXnbr(unsigned long long n, int flag, int precision, int width)
{
	char					*s;
	char					*ret;
	int						i;
	unsigned long long		tmp;

	s = "0123456789ABCDEF";
	tmp = n;
	i = 0;
	while (tmp && ++i)
		tmp /= 16;
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i-- - 1] = s[n % 16];
		n /= 16;
	}
	return (ft_print(&ret, flag, precision, width));
}

int		main(void)
{
	unsigned int	flag;

	flag = 0;
	set_flag(flag, HASH);
	set_flag(flag, PLUS);
	//set_flag(flag, MINUS);
	set_flag(flag, SPACE);
	//set_flag(flag, ZERO);
	set_flag(flag, PRECISION);
	set_flag(flag, x);
	printb(flag);
	
	printf("size = %d\n", ft_putxnbr(1866, flag, 8, 10));
	printf("%+# 10.8x\n", 1866);
	
	/*printf("size = %d\n", ft_putonbr(234, flag, 2, 1));
	printf("%+ 1.2o\n", 234);*/
}
