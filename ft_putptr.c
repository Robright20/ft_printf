/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:17:13 by fokrober          #+#    #+#             */
/*   Updated: 2019/09/25 01:57:25 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int		ft_putptr(int *flags, int width, int precision, va_list ap)
{
	set_flag(flags, HASH);
	set_flag(flags, flagtoi(EL, ARGS_BUF));
	return (ft_putxnbr(flags, width, precision, ap));
}
*/

int		main(void)
{
	char	*s;

	s = ARGS_BUF;
	printf("%c\n", s[IDEC]);
	return (0);
}
