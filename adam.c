/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:32:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/13 23:14:08 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	(*g_fetch_by_sizem[4])(va_list ap, int bsigned) =
{
	fetch_by_sizem_ll, \
	fetch_by_sizem_hh, \
	fetch_by_sizem_l, \
	fetch_by_sizem_h, \
};

int		flag_lookup(int flag, int pos, int bound)
{
	int i;

	i = 0;
	while (i < bound)
	{
		if (IS_ON(flag, (pos + i)))
			return (i);
		i++;
	}
	return (-1);
}

/*
** also handle h, hh, l, ll
*/

int		ft_putunbr(va_list ap, int flag, int precision, int width)
{
	char				*ret;
	int					i;
	unsigned long long	n;
	unsigned long long	tmp;

	i = flag_lookup(flag, LLONG, 4);
	n = (i != -1) ? (g_fetch_by_sizem[i](ap, 0)) : va_arg(ap, int);
	tmp = n;
	i = 0;
	while (tmp && ++i)
		tmp /= 10;
	if (!(ret = ft_hash_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (ft_print(&ret, flag, precision, width));
}

int		ft_putdnbr(va_list ap, int flag, int precision, int width)
{
	char					*ret;
	int						i;
	int						size;
	long long				n;
	unsigned long long		tmp;

	i = flag_lookup(flag, LLONG, 4);
	n = (i != -1) ? (g_fetch_by_sizem[i](ap, 0)) : va_arg(ap, int);
	tmp = n < 0 ? -n : n;
	i = 0;
	while (tmp && ++i)
		tmp /= 10;
	size = i + (IS_ON(flag, PLUS) || (n < 0)) +\
		   ((IS_ON(flag, SPACE)) && !(IS_ON(flag, PLUS)) && (n >= 0));
	if (!(ret = (char*)ft_strnew(sizeof(char) * size)))
		return (0);
	if (size > i)
	{
		ret[0] = (IS_ON(flag, PLUS)) ? '+' : '^';
		ret[0] = (n < 0) ? '-' : ret[0];
	}
	tmp = n < 0 ? -n : n;
	while (tmp)
	{
		ret[--size] = tmp % 10 + '0';
		tmp /= 10;
	}
	printf("after = %s\n", ret);
	return (ft_print(&ret, flag, precision, width));
}

int		ft_putonbr(va_list ap, int flag, int precision, int width)
{
	char				*ret;
	int					i;
	unsigned long long	n;
	unsigned long long	tmp;

	i = flag_lookup(flag, LLONG, 4);
	n = (i != -1) ? (g_fetch_by_sizem[i](ap, 0)) : va_arg(ap, int);
	tmp = n;
	i = 0;
	while (tmp && ++i)
		tmp /= 8;
	if (!(ret = ft_hash_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i-- - 1] = n % 8 + '0';
		n /= 8;
	}
	return (ft_print(&ret, flag, precision, width));
}

int		ft_putxnbr(va_list ap, int flag, int precision, int width)
{
	char					*s;
	char					*ret;
	int						i;
	unsigned long long		n;
	unsigned long long		tmp;

	i = flag_lookup(flag, LLONG, 4);
	n = (i != -1) ? (g_fetch_by_sizem[i](ap, 0)) : va_arg(ap, int);
	s = "0123456789abcdef";
	tmp = n;
	i = 0;
	while (tmp && ++i)
		tmp /= 16;
	if (!(ret = ft_hash_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i-- - 1] = s[n % 16];
		n /= 16;
	}
	return (ft_print(&ret, flag, precision, width));
}

int		ft_putXnbr(va_list ap, int flag, int precision, int width)
{
	char					*s;
	char					*ret;
	int						i;
	unsigned long long		n;
	unsigned long long		tmp;

	i = flag_lookup(flag, LLONG, 4);
	n = (i != -1) ? (g_fetch_by_sizem[i](ap, 0)) : va_arg(ap, int);
	s = "0123456789ABCDEF";
	tmp = n;
	i = 0;
	while (tmp && ++i)
		tmp /= 16;
	if (!(ret = ft_hash_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i-- - 1] = s[n % 16];
		n /= 16;
	}
	return (ft_print(&ret, flag, precision, width));
}

//------------------test-function------------------------------
void	display(int flag, int i, ...)
{
	va_list ap;
	long long n = 15;

	va_start(ap, i);
	while(i--)
	{
		printf("my_size = %d", ft_putdnbr(ap, flag, 0, 11));
		//printf("my_size = %d", ft_putxnbr(ap, flag, 0, 0));
		printf("\n");
	}
	printf("size = %d\n", printf("%#+9.5d", n));
	va_end(ap);
}

int		main(void)
{
	unsigned int	flag;

	flag = 0;
	SET_FLAG(flag, HASH);
	SET_FLAG(flag, PLUS);
	SET_FLAG(flag, QUOTE);
	//SET_FLAG(flag, LLONG);
	//SET_FLAG(flag, LONG);
	//SET_FLAG(flag, HALF);
	//SET_FLAG(flag, HHALF);
	//SET_FLAG(flag, MINUS);
	SET_FLAG(flag, SPACE);
	SET_FLAG(flag, ZERO);
	//SET_FLAG(flag, PRECISION);
	SET_FLAG(flag, DEC);
//	printbits(flag, 4);
	

	display(flag, 1, 1000000);
	//printf("size = %d\n", ft_putxnbr(1866, flag, 8, 10));
	//printf("%+# 10.8x\n", 1866);
	
	/*printf("size = %d\n", ft_putonbr(234, flag, 2, 1));
	printf("%+ 1.2o\n", 234);*/
}
