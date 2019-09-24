#include "header.h"

void	printbits(int oc, int i)
{
//	int i = 31;
	char bb;
	while ( i >= 0)
	{
		bb = (oc >> i) & 1;
		printf("%u", bb);
		if (i == 8 || i == 16 || i == 24 || i == 32 || i == 40 || i == 48 || i == 56 || i == 64 || i == 72 || i == 80 || i == 88 || i == 96 || i == 104 || i== 112 || i ==  120 || i == 128)
			printf(" ");
		i--;
	}
	printf("\n");
}

void	get_bits(int nbr, int *exp, int *mantissa)
{
	int exp_flag;
	int m_flag;

	exp_flag = 2139095040;  // 01111111 10000000 00000000 00000000
	m_flag = 8388607; 		// 00000000 01111111 11111111 11111111
	(*exp) = ((nbr) & exp_flag ) >> 23;
	(*mantissa) = (nbr & m_flag);
//	printf("nbr : "); printbits(nbr);
//	printf("\nexp : ");printbits((*exp));
//	printf("\nman : ");printbits((*mantice));
}

int		power_of_two(int i)
{
	int j;
	int res;

	j = 0;
	res = 1;
	while (j < i)
	{
		res += 2 * res;
		j++;
	}
	return (res);
}
void	convert_bin_deci(int *nbr)
{
	int temp;
	int	i;

	i = 31;
	temp = 0;
	printbits(*nbr, 31);
	while (i)
	{
		if ((*nbr) & (1 << i))
		{
			temp += power_of_two(i);
		}
		i--;
	}
	printbits(temp, 31);
	printf("temp == %d;\n", temp);
	(*nbr) = temp;
}

char	*float_conversion(float nbr)
{
	int	exp;
	int mantissa;
	int temp;
	memcpy((void*)&temp, &nbr, sizeof(float));
	get_bits(temp, &exp, &mantissa);
	exp -= 127;
	printbits(temp, 31);

//	printbits(exp);
//	convert_bin_deci(&exp);
//	convert_bin_deci(&mantissa);
	printf("exp == %d;\n", exp);
	printf("man == %d;\n", mantissa);
	// db exp and mantissa are readable numbers in decimal base
	/* now calculate the printable value of nbr*/

	
	return ("aa");

}
int	main(void)
{
//	float nb = 123.456;
//	float_conversion(nb);
	//printf("%Lf\n",3652147892555555526658741555444115522015554426932587936258936258962581473692581473698251473682514736825147369825147369258147369258714369825714693258471368257146932584713682574136825471368521473582741.l);
	//
	long double tst = 0;
	void *p = &tst;

	p += 15;
	printbits(tst, 127);
	//printf("%.36Lf\n\n", tst);
//	long long tmp = memcpy(&tmp, &tst, 8);
	
	tst = 1;
//	memcpy(&tst, &tmp, 8)
	printbits(tst, 127);
	printf("%.36Lf\n", tst);
	/*float aa = 0./0;
	int bb;
	memcpy((void*)&bb, (void*)&aa, 4);
	printbits(bb);



	float aa1 = 10./0;
	int bb1;
	memcpy((void*)&bb1, (void*)&aa1, 4);
	printf("10./0  0%f\n", 10./0);

	printbits(bb1);



	float aa2 = 0.;
	int bb2;
	memcpy((void*)&bb2, (void*)&aa2, 4);
	printf("0.  %f\n", 0.);
	printbits(bb2);


	float aa3 = -10./0;
	int bb3;
	memcpy((void*)&bb3, (void*)&aa3, 4);
	printf("-10./0   %f\n", -10./0);
	printbits(bb3);



	float aa4 = -0./0;
	int bb4;
	memcpy((void*)&bb4, (void*)&aa4, 4);
	printf("-0./0   %f\n", -0./0);
	printbits(bb4);



	float aa5 = -0.;
	int bb5;
	memcpy((void*)&bb5, (void*)&aa5, 4);
	printf("-0.  %f\n", -0.);
	printbits(bb5);
	int a = 6;
	
	convert_bin_deci(&a);
*/
	return (0);
}
