/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:15:23 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/26 14:33:22 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_minus(char *new_result, char *result, int len, int width)
{
	ft_memcpy(new_result, result, len);
	ft_memset(&new_result[len], ' ', width - len);
	return (new_result);
}

char	*apply_zero(char *new_result, char *result, int size, int sign)
{
	(void)result;
//	printf("result [%s];\n", result);
//	printf("new result [%s];\n", new_result);
	ft_memset(new_result, '0', size + sign);
//	(void)(sign && (new_result[0] = '-'));
	if (sign && result[0] == '+')
		new_result[0] = '+';
	else if (sign && result[0] == '-')
		new_result[0] = '-';
	else if (sign && result[0] == ' ')
		new_result[0] = ' ';
	return (new_result);
}

char	*apply_width(int *flags, char *result, int conv, int width)
{
	char	*new_result;
	int		len;
	int		pholder;
	int		sign;

//	printf("result1 == {%s}\n", result);
	new_result = result;
	if (width < 0)
	{
		width = -width;
		SET_FLAG_ON(*flags, MINUS);
	}
	if (!result || (len = ft_strlen(result)) >= width)
		return (result);
	if (!(new_result = ft_strnew(width)))
		return (NULL);
	pholder = (IS_ON(*flags, MINUS) || !IS_ON(*flags, ZERO)) ? ' ' : '0';
	sign = (conv > STRING && (result[0] == '-' || result[0] == '+' || result[0] == ' '));
	ft_memset(new_result, pholder, width);
	ft_memcpy(&new_result[width - len], result, len);
	if (IS_ON(*flags, MINUS))
		apply_minus(new_result, result, len, width);
	else if (IS_ON(*flags, ZERO))
		apply_zero(new_result, result, width - len, sign);
	free(result);
	//printf("result2 == {%s}\n", new_result);
	return (new_result);
}
