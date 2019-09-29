/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_downcas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:40:40 by nkhribec          #+#    #+#             */
/*   Updated: 2019/09/29 21:53:34 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_upercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char *ft_downcase(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (is_upercase(s[i]))
			s[i] = s[i] - 'A' + 'a';
	return (s);
}

int		main()
{
	char s[] = "ADAM AAAAAA adam ; 898 Naji khrribeche";
	printf("%s\n", ft_downcase(s));
}
