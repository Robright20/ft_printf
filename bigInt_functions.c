/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigInt_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:09:44 by mzaboub           #+#    #+#             */
/*   Updated: 2019/10/02 14:59:22 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "ft_printf.h"

/*
** ----------------------------------------------
**/

void		edit_carry_on(t_bigint *nbr)
{
	int carry;
	int i = 309;

	carry = 0;
	while (i >= 0)
	{
		if (carry != 0)
		{
			nbr->tab[i] += carry;
			carry = 0;
		}
		if (nbr->tab[i] > 9)
		{
			carry = nbr->tab[i] / 10;
			nbr->tab[i] = nbr->tab[i] % 10;
		}
		i--;
	}
}


/*
** ----------------------------------------------
**/

t_bigint	*bigint_add(t_bigint a, t_bigint b)
{
	int i = 309;
	t_bigint *sum;

	sum = malloc(sizeof(t_bigint));
	while (i > 0)
	{
		sum->tab[i] = a.tab[i] + b.tab[i];
		i--;
	}
	edit_carry_on(sum);
	return (sum);
}

/*
** ----------------------------------------------
**/


t_bigint	bigint_mult(t_bigint a, t_bigint b)
{
	int i = 309;
	int j = 309;
	int res;
	int i_ret = 309;
	int j_ret;
	int carry;
	
	t_bigint ret;
	ft_memset(&ret, 0, sizeof(ret));
	while (i >= 0)
	{
		carry = 0;
		j_ret = i_ret;
		j = 309;
		while (j > 0)
		{
			res = a.tab[i] * b.tab[j] + ret.tab[j_ret] + carry;
			carry = res / 10;
			ret.tab[j_ret] = res % 10;
			j--;
			(j_ret > 1) ? j_ret-- : j_ret;
		}
		if (carry > 0)
			ret.tab[j_ret] = carry;
		i_ret--;
		i--;
	}
	return (ret);			
}


/*
** ----------------------------------------------
**/

t_bigint	bigint_power(t_bigint a, int n)
{
	int i;
	t_bigint result;
	
	i = 0;
	ft_memset((void*)result.tab, 0, 1240);
	result.tab[309] = 1;		
	while (i < n)
	{
		result = bigint_mult(result, a);
		i++;
	}
	return (result);
}

/*
** ----------------------------------------------
**/

t_bigint	convert(long long  nbr)
{
	int i = 309;
	t_bigint ret;

	ft_memset(ret.tab, 0, 1240);
	while (nbr > 0)
	{
		ret.tab[i] = nbr % 10;
		nbr /= 10;
		i--;
	}
	return (ret);
}

/*
** ----------------------------------------------
**/

void	bigint_del(t_bigint *nbr)
{
	free(nbr);
}

/*
** ----------------------------------------------
**/
/*
int	main()
{
	long long nb1 = 999991654234;
	long long  nb2 = 654985474562;

	t_bigint *nb11 = convert(nb1);
	t_bigint *nb22 = convert(nb2);

	print_bigint(*nb11);
	print_bigint(*nb22);

	t_bigint *sum = bigint_add(*nb11, *nb22);
	t_bigint *mul = bigint_mult(*nb11, *nb22);

	printf("sum == ");	print_bigint(*sum);
	printf("mul == "); 	print_bigint(*mul);

	bigint_del(nb11);
	bigint_del(nb22);
	bigint_del(sum);
	bigint_del(mul);
	return (0);
}
*/
