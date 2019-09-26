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


t_bigint	*convert(long long nbr);
t_bigint	*bigint_add(t_bigint a, t_bigint b);
void		print_bigint(t_bigint bb);
void		edit_carry_on(t_bigint *nbr);

void	float_onversion(float nbr);
void	get_bits(int nbr, int *exp, int *mantissa);
int		power(int n, int i);
void	intPart_bin_to_deci(int *nbr);
void	float_conversion(float nbr);
t_bigint	*bigint_mult(t_bigint a, t_bigint b);
