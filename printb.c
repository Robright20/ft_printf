/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:10:33 by fokrober          #+#    #+#             */
/*   Updated: 2019/10/03 15:11:33 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printbits(void *p, int i)
{
	char bb;
	int  j;

	j = i;
	while (j-- > 1)
		p++;
	while (i > 0)
	{
		j = 7;
		bb = *(char *)p;
		while (j >= 0)
		{
			printf("%u", ((bb >> j) & 1));
			j--;
		}
		i--;
		p--;
		printf(" ");
	}
	printf("\n");
}