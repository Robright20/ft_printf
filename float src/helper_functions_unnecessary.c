/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 04:41:39 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/11 00:14:28 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printbits(void *p, int bytes)
{
	char bb;
	int  j;

	j = bytes;
	while (j-- > 1)
		p++;
	//p += i;
	while (bytes-- > 0)
	{
		j = 7;
		bb = *(char *)p;
		while (j >= 0)
		{
			printf("%u", ((bb >> j) & 1));
			j--;
		}
		p--;
		printf(" ");
	}
	printf("\n");
}

int     power(int n, int i)
{
	int j;
	int res;

	j = 0;
	res = 1;
	while (j < i)
	{
		res *= n;
		j++;
	}
	printf("%d^%d == %d;\n",n , i, res);
	return (res);
}
