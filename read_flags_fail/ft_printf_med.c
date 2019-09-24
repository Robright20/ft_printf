/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_med.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:00:56 by mzaboub           #+#    #+#             */
/*   Updated: 2019/09/23 14:14:02 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_flags_conver(const char *format, int i, unsigned int *flagconv);
void	get_pre(const char *format, int i, int *pres);
void	get_width(const char *format, int i, int *width);
void	incriment_indice(const char *format, int *i);
void	ft_printf(const char *format, ...);
void	ft_print_bits(unsigned int oc);

int main()
{
	char *s = "hello%-+0# lLhllhhdifFeEgGcsSouxX";
	unsigned int	nbr = 4;
	unsigned int	nb;
	float aa = 4.21;
//	ft_printf("hello\n");
	ft_print_bits(aa);
//	get_flags_conver(s, 6, &nb);
//	printf("\nnbr == ");
//	ft_print_bits(nbr);
	//printf("\nnb  == ");
//	ft_print_bits(nb);

	return (0);
}

void	ft_print_bits(unsigned int oc)
{
	int i = 31;
	char bb;
	while ( i >= 0)
	{
		bb = (oc >> i) & 1;
		printf("%u", bb);
	//	if (i == 24 || i == 16 || i == 8)
	//		printf(" ");
		i--;
	}
}

void	ft_printf(const char *format, ...)
{
	int i;
	va_list	apt;

	i = 0;
	va_start(apt, format);
	while (format[i])
	{
		if (format[i] != '%' && format[i] != '\\')
		{
			write(1, &format[i], 1);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			unsigned int flagconv = 0;
			int pres = 0;
			int width = 0;
			get_flags_conver(format, i + 1, &flagconv);
			get_pre(format, i + 1, &pres);
			get_width(format, i + 1, &width);
			incriment_indice(format, &i);
		}
		else
			write (1, format + 1, 1);
	}
	va_end(apt);
}			

void	get_flags_conver(const char *format, int i, unsigned int *flagconv)
{
	char *str = "-+0# lLhllhhdifFeEgGcsSouxX"; //27 char
	int		j = 0;
	int		validation;

	while (format[i] != 0)
	{
		printf ("\nthe character format[%d]: %c;\n", i, format[i]);
		j = 0;
		validation = 0;
		while (j < 27 && validation == 0)
		{
			if (format[i] == str[j])
			{
				if (format[i + 1] == str[j + 1])// && str[j] == str[j + 1])
				{
					printf("\n\nbla bla\n\n");
					(*flagconv) = ((*flagconv) | (1 << (26 - j)));
					printf("foo; i == %d,\tj == %d;\n", i, j);
					printf("format[%d] = %c;\tstr[%d] = %c;\n", i, format[i], j, str[j]);
					printf("format[%d] = %c;\tstr[%d] = %c;\n", i + 1, format[i+1], j+1, str[j+1]);
					j++;
					//break;
				}
				else
				{
				//	printf("\n------\nj == %d, str[j] == %c;\nbefore :    :", j, str[j]); ft_print_bits(*flagconv);
					(*flagconv) = ((*flagconv) | (1 << (26 - j)));
				//	printf("\nflags :     ;     %s;\n", str);
				//	printf("after :     :");
				//	ft_print_bits(*flagconv);
				//	break;
				}
				validation = 1;
			}
			j++;
		}
		if (validation == 0 && strchr("*$123456789", format[i]) == 0)
			break;
		i++;
	}
}

void	get_pre(const char *format, int i, int *pres)
{
	// .*9, .*4$, .9
}

void	get_width(const char *format, int i, int *width)
{
	// *5, *3$, 7

}

void	incriment_indice(const char *format, int *i)
{
	//jfkdsjfkjs
}
