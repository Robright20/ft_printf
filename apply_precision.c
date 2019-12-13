/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:52:58 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/12 01:28:07 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision(int *flags, char *result, int conv, int precision)
{
	char	*new_result;
	int		len;
	int		sign;
	int		index;

	new_result = result;
	if (IS_ON(*flags, POINT))
		SET_FLAG_OFF(*flags, ZERO);
	if ((DEC <= conv && conv <= BHEX) && (result[0] == '0') && \
		IS_ON(*flags, POINT) && (precision == 0))
		result[0] = '\0';
	if (!result || (len = ft_strlen(result)) >= precision)
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
	return (new_result);
}

/*
** int		main()
** {
**	char	*s = "12345";
**	char	*s2 = "-12345";
**
**	printf("%.10d\n", 12345);
**	printf("[%s]\n", apply_precision(0, s, DEC, 10));
**	printf("%.10d\n", -12345);
**	printf("[%s]\n", apply_precision(0, s2, DEC, 10));
**	return (0);
** }
*/
