/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:32:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/09/26 21:17:20 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#define FLAG "+#- 0wpoxX"
#define set_flag(flag, index) flag = flag | (1 << (32 - index))
#define is_on(flag, index) (flag & (1 << (32 - index))) != 0

typedef enum 	e_flag
{
	PLUS = 1, HASH, MINUS, SPACE, ZERO, WIDTH, PRECISION, OCTAL, x, X
}				t_flag;

void            printb(unsigned int c)
{
	int             i;
	unsigned int	m;

	i = 32;
	while (--i > -1)
	{
		m = (((c & (1 << i)) >> i) + '0');
		write(1, &m, 1);
	}
	write(1, "\n", 1);
}

void	blacktozero(char *s, int until)
{
	while (until)
	{
		if (*s == ' ')
			*s = '0';
		s++;
		until--;
	}
}
void	shift(char *s, int shift_value)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	//printf("i = %d\n", i);
	while (--i >= 0)
		s[i + shift_value] = s[i];
	while (--shift_value >= 0)
		s[shift_value] = ' ';
}

void	fprecision(char **s, int flag, int precision, int shift_value)
{
	char	*tmp;
	
	tmp = *s;
	*s = ft_memalloc(sizeof(char) * (precision + 1));
	ft_strcpy(*s, tmp);
	ft_strdel(&tmp);
	shift(*s, shift_value);
	blacktozero(*s, shift_value);
}

void	fwidth(char **s, int flag, int precision, int width)
{
	char	*tmp;
	int		len;
	int		shift_value;

	len = (int)ft_strlen(*s);
	tmp = *s;
	*s = ft_memalloc(sizeof(char) * (width + 1));
	ft_strcpy(*s, tmp);
	printf("s = %s\n", *s);
	ft_strdel(&tmp);
	shift_value = len > precision ? 0 : precision - len;
	shift(*s, shift_value);
	printf("s = %s\n", *s);
	blacktozero(*s, shift_value);
	printf("s = %s\n", *s);
	//printf("shift value = %d\n", shift_value);
	len = (int)ft_strlen(*s);
	if (!(is_on(flag, MINUS)))
	{
		shift(*s, width - len);
		if (is_on(flag, ZERO))
			blacktozero(*s, width - len);
	}
	else
	{
		shift(*s, width - len);
		//blacktozero(*s, width - len);
	}
}

int		ft_print(char *s, int flag, int precision, int width)
{
	int		len;

	len = (int)ft_strlen(s);
	if (precision >= len && precision >= width)
	{
		printf("-----pppp----------\n");
		fprecision(&s, flag, precision, precision - len);
		ft_putendl(s);
		return (precision);
	}
	if (width >= len && width >= precision)
	{
		printf("------www--%d--------\n", len);
		fwidth(&s, flag, precision, width);
		//printf("s = %s\n", s);
		ft_putendl(s);
		return (width);
	}
	ft_putendl(s);
	return (len);
}

char	*ft_hash_plus_alloc_o(int *i, int flag)
{
	char	*s;

	if (is_on(flag, HASH))
	{
		if (is_on(flag, PLUS))
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

char	*ft_hash_plus_alloc_heX(int *i, int flag)
{
	char	*s;

	if (is_on(flag, HASH))
	{
		if (is_on(flag, PLUS))
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
char	*ft_hash_plus_alloc_hex(int *i, int flag)
{
	char	*s;

	if (is_on(flag, HASH))
	{
		if (is_on(flag, PLUS))
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

char	*ft_hash_plus_alloc(int *i, int flag)
{
	if (!(is_on(flag, HASH)) && !(is_on(flag, PLUS)))
		return (ft_memalloc(sizeof(char) * ((*i) + 1)));
	if (is_on(flag, OCTAL))
		return (ft_hash_plus_alloc_o(i, flag));
	if (is_on(flag, X))
		return (ft_hash_plus_alloc_heX(i, flag));
	if (is_on(flag, x))
		return (ft_hash_plus_alloc_hex(i, flag));
	return (ft_memalloc(sizeof(char) * ((*i) + 1)));
}

//int		ft_putonbr(unsigned int n, int flag, int width, int precision)
int		ft_putonbr(unsigned int n, int flag)
{
	char	*s;
	char	*ret;
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
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	while (n)
	{
		ret[i - 1] = s[n % 8];
		n /= 8;
		i--;
	}
	ft_putendl(ret);
	ft_strdel(&s);
	ft_strdel(&ret);
	return (0);
}

//int		ft_putxnbr(unsigned int n, int flag, int width, int precision)
int		ft_putXnbr(unsigned int n, int flag)
{
	char	*s;
	char	*ret;
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
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	printf("%s\n", ret);
	while (n)
	{
		ret[i - 1] = s[n % 16];
		n /= 16;
		i--;
	}
	ft_putendl(ret);
	ft_strdel(&s);
	ft_strdel(&ret);
	return (0);
}

int		ft_putxnbr(unsigned int n, int flag, int precision, int width)
{
	char	*s;
	char	*ret;
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
	if (!(ret = ft_hash_plus_alloc(&i, flag)))
		return (0);
	a = i;
	while (n)
	{
		ret[i - 1] = s[n % 16];
		n /= 16;
		i--;
	}
	ft_putendl(ret);
	ft_print(ret, flag, precision, width);
	ft_strdel(&s);
	//ft_strdel(&ret);
	return (a);
}

int 	main()
{
	/*char s[] = "65           ";
	printf("%s\n", s);
	blacktozero(s);
	printf("%s\n", s);*/
	unsigned int	flag = 0;

	set_flag(flag, HASH);
	set_flag(flag, PLUS);
	//set_flag(flag, MINUS);
	set_flag(flag, ZERO);
	
	set_flag(flag, x);
	printb(flag);
	ft_putxnbr(10, flag, 10, 15);
}
