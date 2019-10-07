/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:32:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/07 02:24:05 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long long	ft_ll(va_list ap)
{
	return (va_arg(ap, long long));
}

long long	ft_l(va_list ap)
{
	return ((long long)va_arg(ap, unsigned long));
}

long long	ft_d(va_list ap)
{
	return ((long long)va_arg(ap, int));
}

long long	ft_h(va_list ap)
{
	return ((long long)(short)va_arg(ap, int));
}

long long	ft_hh(va_list ap)
{
	return ((long long)(char)va_arg(ap, int));
}

long long	(*dispatcher[5])(va_list ap) = {ft_ll, ft_l, ft_d, ft_h, ft_hh};

/*
** data are stocked in same way(int and unsig int) it deffer only in reading
** this means that we can store int in uint and recover this uint in int after
*/

int		ft_index(int flag)
{
	if (is_on(flag, ll))
		return (0);
	if (is_on(flag, l))
		return (1);
	if (is_on(flag, h))
		return (3);
	if (is_on(flag, hh))
		return (4);
	return (2);
}

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

int		ft_putunbr(va_list ap, int flag, int precision, int width)//also handle h, hh, l, ll
{
	char				*ret;
	int					i;
	unsigned long long	n;
	unsigned long long	tmp;

	n = dispatcher[ft_index(flag)](ap);
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

int		ft_putdnbr(va_list ap, int flag, int precision, int width)
{
	char					*ret;
	int						i;
	long long				n;
	unsigned long long		tmp;
	int						size;

	n = dispatcher[ft_index(flag)](ap);
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

int		ft_putonbr(va_list ap, int flag, int precision, int width)
{
	char				*ret;
	int					i;
	unsigned long long	n;
	unsigned long long	tmp;

	n = dispatcher[ft_index(flag)](ap);
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

int		ft_putxnbr(va_list ap, int flag, int precision, int width)
{
	char					*s;
	char					*ret;
	int						i;
	unsigned long long		n;
	unsigned long long		tmp;

	n = dispatcher[ft_index(flag)](ap);
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

int		ft_putXnbr(va_list ap, int flag, int precision, int width)
{
	char					*s;
	char					*ret;
	int						i;
	unsigned long long		n;
	unsigned long long		tmp;

	n = dispatcher[ft_index(flag)](ap);
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

void	display(int flag, int i, ...)
{
	va_list ap;
	long long n = 4123456789;

	va_start(ap, i);
	while(i--)
	{
		ft_putdnbr(ap, flag, 8, 10);
		printf("\n");
	}
	printf("n = %+ #10.8hhd\n", n);
	va_end(ap);
}

int		main(void)
{
	unsigned int	flag;

	flag = 0;
	set_flag(flag, HASH);
	set_flag(flag, PLUS);
	//set_flag(flag, ll);
	//set_flag(flag, l);
	//set_flag(flag, h);
	set_flag(flag, hh);
	//set_flag(flag, MINUS);
	set_flag(flag, SPACE);
	//set_flag(flag, ZERO);
	set_flag(flag, PRECISION);
	set_flag(flag, d);
	printb(flag);
	

	display(flag, 6, 15, 4123456789, -47, 69, 255, 256);
	//printf("size = %d\n", ft_putxnbr(1866, flag, 8, 10));
	//printf("%+# 10.8x\n", 1866);
	
	/*printf("size = %d\n", ft_putonbr(234, flag, 2, 1));
	printf("%+ 1.2o\n", 234);*/
}
