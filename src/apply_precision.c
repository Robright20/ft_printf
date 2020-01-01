/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:52:58 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/31 22:14:52 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*apply_precision(int *flags, char *result, int conv, int precision)
{
	char	*new_result;
	int		len;
	int		sign;
	int		index;

	new_result = result;

	if (precision < 0)
	{
		precision = 0;
		SET_FLAG_OFF(*flags, POINT);
	}
	if (IS_ON(*flags, POINT) && (conv != EXPO) && (conv != XFLOAT) && (conv != STRING))
		SET_FLAG_OFF(*flags, ZERO);
	if ((DEC <= conv && conv <= BHEX) && (result[0] == '0') && \
		IS_ON(*flags, POINT) && (precision == 0))
		result[0] = '\0';
	if (!result || \
		(((len = ft_strlen(result)) > precision) && conv != STRING  && conv != XFLOAT && conv != EXPO))
		return (result);
	if (DEC <= conv && conv <= BHEX)
	{
		sign = (result[0] == '-');
		if (!(new_result = ft_strnew(precision + sign)))
			return (NULL);
		new_result[0] = '-';
		ft_memset(&new_result[sign], '0', precision);
		index = precision - (len - sign);
		ft_strcpy(&new_result[sign] + index, &result[sign]);
		free(result);
	}
	if ((conv == EXPO) && (precision > 0))
	{
		result[precision + 1] = '\0';
		index = precision;
		len = ft_strlen(result);
		while ((index > 0) && index >= len)
			result[index--] = '0';
		new_result = result;
	}
	if ((conv == XFLOAT) && (precision > 0))
	{
		int	digitsBefore = 0;
		while (result[digitsBefore] != '.' && result[digitsBefore])
			digitsBefore++;
		if (result[digitsBefore] == '.')
			digitsBefore++;
		len = ft_strlen(result);
		index = precision - (len - digitsBefore);
		result[len + index--] = '\0';
		while (index >= 0)
			result[len + index--] = '0';
		new_result = result;
	}
	if (conv == STRING)
		IS_ON(*flags, POINT) ? new_result[precision] = '\0' : 1;
	return (new_result);
}
