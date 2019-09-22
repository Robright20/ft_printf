/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:06:49 by fokrober          #+#    #+#             */
/*   Updated: 2019/09/22 21:55:03 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	static char	flags[ARGS_SIZE];
	char		*args;
	char		*arg;
	int			i;

	args = "cspdiouxXfeg#0-+ llhhlhLbrk'*$";
	arg = ARGS_BUF;
	printf("%s", arg);
	save_all_flags(flags, args);
	printf("\n");
	i = 0;
	while (i < ARGS_SIZE)
		printf("%d", flags[i++]);
	printf("\n");
	return (0);
}
