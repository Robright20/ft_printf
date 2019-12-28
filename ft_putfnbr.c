/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 05:03:04 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/28 02:11:43 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	//node.precision = (precision == -1) ? 0 : (precision == 0) ? 6 : precision;
	node.precision = precision;
	node.width = width;
	node.flags = flags;
	node.bol = 0;
	print_double(nbr, &node, 0);
	len = write(1, node.buff, ft_strlen(node.buff));
	ft_memdel((void**)&node.buff);
	return (len);
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
//	node.precision = (precision == -1) ? 0 : (precision == 0) ? 6 : precision;
	node.precision = precision;
	node.width = width;
	node.flags = flags;
	node.bol = 0;
	print_long_double(nbr, &node, 0);
	len = ft_strlen(node.buff);
	write(1, node.buff, len);
//	printf("++++++++++++++++++\n");
	ft_memdel((void**)&node.buff);
	return (len);
}

int		ft_putenbr(va_list ap, int flags, int precision, int width)
{
	t_buffer	*node;	
	double		nbr;
	t_int32		len;

	if (IS_ON(flags, BLONG))
		return (ft_putlenbr(ap, flags, precision, width));
	node = malloc(sizeof(t_buffer));
	len = LDBL_DIGITS;
	if (precision > len)
		len += precision;
	if (width > len)
		len += width;
	nbr = va_arg(ap, double);
	node->buff = (char*)malloc(len * sizeof(char));
	node->max_len = len - 1;
	node->precision = precision;
	node->width = width;
	node->flags = flags;
	node->bol = 1;
	print_double(nbr, node, 1);
//	printf("====================== after print_double\n");
	len = ft_strlen(node->buff);
	write(1, node->buff, len);
//	printf("\n====================== after buffer write\n");
	ft_memdel((void**)&node->buff);
//	printf("\n-====================== after buffer free\n");
	//free(node);
	//ft_memdel(&node);

//	printf("\n-====================== after node free\n");
	return (len);
}

int		ft_putlenbr(va_list ap, int flags, int precision, int width)
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
	node.precision = precision;
	node.width = width;
	node.flags = flags;
	node.bol = 1;
	print_long_double(nbr, &node, 1);
	len = ft_strlen(node.buff);
	write(1, node.buff, len);
	ft_memdel((void**)&node.buff);
	return (len);
}
