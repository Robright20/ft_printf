/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:49:28 by mzaboub           #+#    #+#             */
/*   Updated: 2019/09/26 23:38:31 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	float_conversion(float nbr);
void	get_bits(int nbr, int *exp, int *mantissa);
int		power(int n, int i);
void	intPart_bin_to_deci(int *nbr);
void	float_conversion(float nbr);
/*
** ------------------------------------------------
*/

void	printbits(int oc, int i)
{
	char bb;
	while ( i >= 0)
	{
		bb = (oc >> i) & 1;
		printf("%u", bb);
		if (i == 8 || i == 16 || i == 24 || i == 32 || i == 40 || i == 48 ||\
			   	i == 56 || i == 64 || i == 72 || i == 80 || i == 88 || \
				i == 96 || i == 104 || i== 112 || i ==  120 || i == 128)
			printf(" ");
		i--;
	}
	printf("\n");
}


/*
** ------------------------------------------------
*/

void	get_bits(int nbr, int *exp, int *mantissa)
{
	int exp_flag;
	int m_flag;

	exp_flag = 2139095040;  // 01111111 10000000 00000000 00000000
	m_flag = 8388607; 		// 00000000 01111111 11111111 11111111
	(*exp) = ((nbr) & exp_flag ) >> 23;
	(*mantissa) = (nbr & m_flag);
//	printf("nbr : "); printbits(nbr);
//	printf("\nexp : %d;\t", *exp);printbits((*exp), 31);
//	printf("\nman : ");printbits((*mantice));
}


/*
** ------------------------------------------------
*/

int		power(int n, int i)
{
	int j;
	int res;

	j = 0;
	res = 1;
	while (j < i)
	{
		res *= n;
		j++;
	}
	printf("%d^%d == %d;\n",n , i, res);
	return (res);
}

/*
** ------------------------------------------------
*/

void	intPart_bin_to_deci(int *nbr)
{
	int temp;
	int	i;

	i = 31;
	temp = 0;
	while (i)
	{
		if ((*nbr) & (1 << i))
		{
			temp += power(2, i);
		}
		i--;
	}
	(*nbr) = temp;
}


/*
** ------------------------------------------------
*/

void	float_conversion(float nbr)
{
	int	exp = 0;
	int mantissa;
	int temp;

	ft_memcpy((void*)&temp, &nbr, sizeof(float));
	get_bits(temp, &exp, &mantissa);
//	exp -= 127;

	printf("exp == %d;\n", exp);
	printf("man == %d;\n", mantissa);
	// the read of exponnent and mantissa is done, every thing is good;
	
/*
** creat the bigint type 
** creat - bigInt_addition()
** 		 - bigInt_multiplication()
** 		 - int_to_bigInt()
** calcule of 2^23	and convert this to bigInt type ===> a
** calcule of 2^(exp - 150)  usning bigInt type		===> e
** convert the mantissa to bingInt					===> m 
** calcule this in big int  (a + m) * e
*/
	t_bigint a = *convert(power(2, 23));
	t_bigint m = *convert(mantissa);
	t_bigint e;
	int n;
	int dec_pos = 0;
	if (exp > 150)
	{
		e = *convert(power(2, exp - 150));
	}
	else
	{
		n = 150 - exp;
		e = *convert(power(5, n));		
		dec_pos = -n;
		printf("ooops negative exponent :p\n");
	//	return ;
	}
	printf("a == "); print_bigint(a);
	printf("\nm == "); print_bigint(m);
	printf("\ne == "); print_bigint(e);
	t_bigint add = *bigint_add(a, m);
	printf("\ntp == "); print_bigint(add);
	t_bigint *result = bigint_mult(add, e);
	print_bigint(*result);
	printf("\ndec_pos is : %d\n", dec_pos);
}

/*
** ------------------------------------------------
*/

int	main(void)
{
	float nbr = 15070.409;
	float_conversion(nbr);
	printf("nbr == %f;\n", nbr);

	return (0);
}
