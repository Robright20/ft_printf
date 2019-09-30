/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpynull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:libft/ft_memcpynull.c
/*   Created: 2019/04/13 22:09:53 by mzaboub           #+#    #+#             */
/*   Updated: 2019/04/20 16:52:25 by mzaboub          ###   ########.fr       */
=======
/*   Created: 2019/09/22 20:06:49 by fokrober          #+#    #+#             */
/*   Updated: 2019/09/23 22:00:53 by fokrober         ###   ########.fr       */
>>>>>>> d108a795b5acb4f05af2b419e3d49340c0637a33:main.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpynull(void *dst, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
	}
<<<<<<< HEAD:libft/ft_memcpynull.c
	((unsigned char*)dst)[i] = '\0';
	return (dst);
=======
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
>>>>>>> d108a795b5acb4f05af2b419e3d49340c0637a33:main.c
}
