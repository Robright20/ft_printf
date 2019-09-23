/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:06:49 by fokrober          #+#    #+#             */
/*   Updated: 2019/09/23 22:00:53 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printb(int a)
{
	int		i;
	int		p;

	i = 0;
	while (i < 32)
	{
		p = is_flag_on(a, i);
		printf("%d ", p);
		i++;
	}
}

int		main(void)
{
	int		flags = 0;
	char	*args;
	char	*arg;

	args = "#0-+d llhhlhLbrk'*$";
	arg = ARGS_BUF;
	save_all_flags(&flags, args);
	printb(flags);
	return (0);
}
