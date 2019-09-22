/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:32:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/09/22 18:15:35 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_print(char *s, )
{
	
}

int		ft_putxnbr(unsigned int n)
{
	char	*s;
	char	*ret;
	int		i;
	int		a;

	a = n;
	i = -1;
	if (!(s = ft_memalloc(sizeof(char) * 17)))
		return (0);
	while (++i < 10)
		s[i] = '0' + i;
	i--;
	while (++i < 16)
		s[i] = 'a' + i - 10;
	i = 0;
	while (a != 0)
	{
		a /= 16;
		i++;
	}
	if (!(ret = ft_memalloc(sizeof(char) * (i + 1))))
		return (0);
	while (i > 0)
	{

		ret[i - 1] = s[n % 16];
		n /= 16;
		i--;
	}
	ft_print(ret, );
	ft_putstr(ret);
	ft_strdel(&s);
	ft_strdel(&ret);
	return (0);
}

int 	main()
{
	ft_putxnbr(55145);
}
