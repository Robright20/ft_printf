#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

/*
** big int 
*/
 
typedef struct	s_bigint
{
		int tab[100];
}				t_bigint;

typedef union 		s_Record{ 
	long long	i;
	double		f;
	char		str[8];
}			t_record;

t_bigint	convert(long long nbr);
t_bigint	*bigint_add(t_bigint a, t_bigint b);
void		print_bigint(t_bigint bb, int dec_pos);
void		edit_carry_on(t_bigint *nbr);
t_bigint	bigint_power(t_bigint a, int n);

void	float_onversion(double nbr);
void	get_bits(long long nbr, long long *exp, long long *mantissa, long long *sign);
int		power(int n, int i);
void	intPart_bin_to_deci(int *nbr);
t_bigint	bigint_mult(t_bigint a, t_bigint b);
void    printbits(void *p, int i);
