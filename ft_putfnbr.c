/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 05:03:04 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/13 06:01:37 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "flaot_ft_printf.h"
# define DBL_DIGITS 16390
# define LDBL_DIGITS 16390

int	ft_putfnbr(va_list ap, int flags, int precision, int width)
{
	t_buffer	node;	
	double		nbr;
	t_int32		len;

	if (IS_ON(flags, BLONG))
		return (ft_putlfnbr(ap, flags, precision, width));
	len = DBL_DIGITS;
	if (precision > len)
		len += precision;
	if (width > len)
		len += width;
	nbr = va_arg(ap, double);
	node.buff = (char*)malloc(len * sizeof(char));
	node.max_len = len - 1;
	node.precision = (precision == -1) ? 0 : (precision == 0) ? 6 : precision;
	node.width = width;
	node.flags = flags;
	print_double(nbr, &node);
	write(1, node.buff, ft_strlen(node.buff));
	free(node.buff);
	return (ft_strlen(node.buff));
}


int	ft_putlfnbr(va_list ap, int flags, int precision, int width)
{
	t_buffer	node;	
	long double		nbr;
	t_int32			len;

	len = LDBL_DIGITS;
	if (precision > len)
		len += precision;
	if (width > len)
		len += width;
	nbr = va_arg(ap, long double);
	node.buff = (char*)malloc(len * sizeof(char));
	node.max_len = len - 1;
	node.precision = (precision == -1) ? 0 : (precision == 0) ? 6 : precision;
	node.width = width;
	node.flags = flags;
	print_long_double(nbr, &node);
	len = ft_strlen(node.buff);
	write(1, node.buff, len);
	free(node.buff);
	return (len);
}
