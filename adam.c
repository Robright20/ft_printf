/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:32:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/10/09 22:14:48 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

long long	ft_hd(va_list ap)
{
	return ((long long)(short)va_arg(ap, int));
}

long long	ft_hu(va_list ap)
{
	return ((long long)(unsigned short)va_arg(ap, int));
}

long long	ft_hhd(va_list ap)
{
	return ((long long)(char)va_arg(ap, int));
}

long long	ft_hhu(va_list ap)
{
	return ((long long)(unsigned char)va_arg(ap, int));
}

long long	(*dispatcher[7])(va_list ap) = {ft_ll, ft_l, ft_d, ft_hd, ft_hu,\
			ft_hhd, ft_hhu};

/*
 **
 **
 **
*/

int		ft_index(int flag)
{
	if (IS_ON(flag, LLONG))
		return (0);
	if (IS_ON(flag, LONG))
		return (1);
	if (IS_ON(flag, HALF))
	{
		if (IS_ON(flag, DEC) || IS_ON(flag, IDEC))
			return (3);
		else
			return (4);
	}
	if (IS_ON(flag, HHALF))
	{
		if (IS_ON(flag, DEC) || IS_ON(flag, IDEC))
			return (5);
		else
			return (6);
	}
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
	size = i + (IS_ON(flag, PLUS) || (n < 0)) +\
		   ((IS_ON(flag, SPACE)) && !(IS_ON(flag, PLUS)) && (n >= 0));
	if (!(ret = ft_strnew(sizeof(char) * (i + 1))))
		return (0);
	if (size > i)
	{
		ret[0] = (IS_ON(flag, PLUS)) ? '+' : '^';
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

//------------------test-function------------------------------
void	display(int flag, int i, ...)
{
	va_list ap;
	long long n = 15;

	va_start(ap, i);
	while(i--)
	{
		printf("my_size = %d", ft_putonbr(ap, flag, 0, 0));
		printf("\n");
	}
	printf("size = %d\n", printf("%#.0o", n));
	va_end(ap);
}

int		main(void)
{
	unsigned int	flag;

	flag = 0;
	SET_FLAG(flag, HASH);
	SET_FLAG(flag, PLUS);
	//SET_FLAG(flag, LLONG);
	//SET_FLAG(flag, LONG);
	//SET_FLAG(flag, HALF);
	SET_FLAG(flag, HHALF);
	//SET_FLAG(flag, MINUS);
	SET_FLAG(flag, SPACE);
	//SET_FLAG(flag, ZERO);
	SET_FLAG(flag, PRECISION);
	SET_FLAG(flag, OCTAL);
	printb(flag);
	

	display(flag, 1, 15);
	//printf("size = %d\n", ft_putxnbr(1866, flag, 8, 10));
	//printf("%+# 10.8x\n", 1866);
	
	/*printf("size = %d\n", ft_putonbr(234, flag, 2, 1));
	printf("%+ 1.2o\n", 234);*/
}
