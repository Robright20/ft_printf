/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:32:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/09/24 04:47:50 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#define FLAG "+#- 0wpoxX"
#define set_flag(flag, index) flag = flag | (1 << (7 - index))
#define is_on(flag, index) (flag & (1 << (7 - index))) != 0

typedef enum 	e_flag
{
	PLUS, HASH, MINS, SPACE, ZERO, WIDTH, PRECISION, OCTAL, x, X
}				t_flag;

void            printb(unsigned char c)
{
	int             i;
	unsigned char   m;

	i = 8;
	while (--i > -1)
	{
		m = (((c & (1 << i)) >> i) + '0');
		write(1, &m, 8);
	}
	write(1, "\n", 1);
}

/*int		ft_holder_len(char *s, char flag, int width, int precision)
{
	int		len;
	int		i;
	t_flag	j;

	i = -1;
	len = ft_strlen(s);
	len = width > (precision + is_on(0) + is_on(1)) ? width : precision + is_on(0) + is_on(1);
	while (++i < 5)
	{
		is_on(flag, i);

	}
	return (len);
}

int		ft_print(char *s, int flag, int width, int precision)
{
	t_flag	j;
	int		len;

	len = (int)ft_strlen(s);
	if (len > width && len > precision)
	{
		if (is_on(((((flag, (j = PLUS)))))))

			write(1, "+", 1);
		if (is_on(((flag, (j = HASH)))))
		{
			if (is_on((j = OCTAL)))
				write(1, "", 1);
			if (is_on((j = HEX)))
				write(1, "ox", 1);
		
		}
		write(1, s, len);
		return (len)
	}
}*/

char	*ft_hash_plus_alloc_o(int *i, char flag)
{
	char	*s;
	t_flag	j;


	if (is_on(flag, (j = HASH)))
	{
		if (is_on(flag, (j = PLUS)))
		{
			*i += 2;
			if (!(s = ft_memalloc(sizeof(char) * ((*i) + 1))))
				return (NULL);
			s[0] = '+';
			s[1] = '0';
		}
		else
		{
			*i += 1;
			if (!(s = ft_memalloc(sizeof(char) * ((*i) + 1))))
				return (NULL);
			s[0] = '0';
		}	
	}
	else
	{
		*i +=1;
		if (!(s = ft_memalloc(sizeof(char) * ((*i) + 1))))
			return (NULL);
		s[0] = '+';
	}
	return (s);
}

char	*ft_hash_plus_alloc_heX(int *i, char flag)
{
	char	*s;
	t_flag	j;

	if (is_on(flag, (j = HASH)))
	{
		if (is_on(flag, (j = PLUS)))
		{
			*i += 3;
			if (!(s = ft_memalloc(sizeof(char) * ((*i) + 1))))
				return (NULL);
			s[0] = '+';
			s[1] = '0';
			s[2] = 'X';
		}
		else
		{
			*i += 2;
			if (!(s = ft_memalloc(sizeof(char) * ((*i) + 1))))
				return (NULL);
			s[0] = '0';
			s[1] = 'X';
		}	
	}
	else
	{
		*i += 1;
		if (!(s = ft_memalloc(sizeof(char) * ((*i) + 1))))
			return (NULL);
		s[0] = '+';
	}
	return (s);
}
char	*ft_hash_plus_alloc_hex(int *i, char flag)
{
	char	*s;
	t_flag	j;

	if (is_on(flag, (j = HASH)))
	{
		if (is_on(flag, (j = PLUS)))
		{
			*i += 3;
			if (!(s = ft_memalloc(sizeof(char) * ((*i) + 1))))
				return (NULL);
			s[0] = '+';
			s[1] = '0';
			s[2] = 'x';
		}
		else
		{
			*i += 2;
			if (!(s = ft_memalloc(sizeof(char) * ((*i) + 1))))
				return (NULL);
			s[0] = '0';
			s[1] = 'x';
		}	
	}
	else
	{
		*i += 1;
		if (!(s = ft_memalloc(sizeof(char) * ((*i) + 1))))
			return (NULL);
		s[0] = '+';
	}
	return (s);
}

char	*ft_hash_plus_alloc(int *i, char flag)
{
	t_flag	j;

	if (!(is_on(flag, (j = HASH))) && !(is_on(flag, (j = HASH))))
		return (ft_memalloc(sizeof(char) * ((*i) + 1)));
	if (is_on(flag, (j = OCTAL)))
		return (ft_hash_plus_alloc_o(i, flag));
	if (is_on(flag, (j = X)))
		return (ft_hash_plus_alloc_heX(i, flag));
	if (is_on(flag, (j = x)))
		return (ft_hash_plus_alloc_hex(i, flag));
	return (ft_memalloc(sizeof(char) * ((*i) + 1)));
}

//int		ft_putonbr(unsigned int n, char flag, int width, int precision)
int		ft_putonbr(unsigned int n, char flag)
{
	char	*s;
	char	*result;
	int		i;
	int		a;
	t_flag	j;

	a = n;
	i = -1;
	if (!(s = ft_memalloc(sizeof(char) * 8)))
		return (0);
	while (++i < 8)
		s[i] = '0' + i;
	i = 0;
	while (a)
	{
		a /= 8;
		i++;
	}
	if (!(result = ft_hash_plus_alloc(&i, flag)))
		return (0);
	while (n)
	{
		result[i - 1] = s[n % 8];
		n /= 8;
		i--;
	}
	ft_putendl(result);
	ft_strdel(&s);
	ft_strdel(&result);
	return (0);
}

//int		ft_putxnbr(unsigned int n, char flag, int width, int precision)
int		ft_putXnbr(unsigned int n, char flag)
{
	char	*s;
	char	*result;
	int		i;
	int		a;
	t_flag	j;

	a = n;
	i = -1;
	if (!(s = ft_memalloc(sizeof(char) * 16)))
		return (0);
	while (++i < 10)
		s[i] = '0' + i;
	i--;
	while (++i < 16)
		s[i] = 'a' + i - 10;
	i = 0;
	while (a)
	{
		a /= 16;
		i++;
	}
	if (!(result = ft_hash_plus_alloc(&i, flag)))
		return (0);
	while (n)
	{
		result[i - 1] = s[n % 16];
		n /= 16;
		i--;
	}
	ft_putendl(result);
	ft_strdel(&s);
	ft_strdel(&result);
	return (0);
}

int		ft_putxnbr(unsigned int n, char flag)
{
	char	*s;
	char	*result;
	int		i;
	int		a;
	t_flag	j;

	a = n;
	i = -1;
	if (!(s = ft_memalloc(sizeof(char) * 16)))
		return (0);
	while (++i < 10)
		s[i] = '0' + i;
	i--;
	while (++i < 16)
		s[i] = 'A' + i - 10;
	i = 0;
	while (a)
	{
		a /= 16;
		i++;
	}
	if (!(result = ft_hash_plus_alloc(&i, flag)))
		return (0);
	a = i;
	while (n)
	{
		result[i - 1] = s[n % 16];
		n /= 16;
		i--;
	}
	ft_putendl(result);
	ft_strdel(&s);
	ft_strdel(&result);
	return (a);
}

int 	main()
{
	char flag = 0;
	t_flag	j;

	//set_flag(flag, (j = HASH));
	//set_flag(flag, (j = PLUS));
	ft_putonbr(12, flag);
	ft_putxnbr(12, flag);
	ft_putXnbr(12, flag);
}
