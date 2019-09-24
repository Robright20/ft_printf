#include "header.h"

void	ft_print_bits(long long oc)
{
	int i = 63;
	char bb;
	while ( i >= 0)
	{
		bb = (oc >> i) & 1;
		printf("%u", bb);
		if (i == 8 || i == 16 || i == 24 || i == 32 || i == 40 || i == 48 || i == 56 || i == 64)
			printf(" ");
		i--;
	}
	printf("\n");
}

int	main(void)
{
	float nbr = 789.54230;
	//long double nb = 324.432;
	long long temp = 45645645645454;
printf("nbr == %#.2g;\n", nbr); 
/*
	temp = 0;
	printf("temp == %lld;\n", temp);
	memcpy((void*)&temp, (void*)&nbr, 8);
	printf("temp == %lld;\n", temp);

	//printf("nbr == %f;\n", nbr);
	printf("float == %lu, long llong == %lu;\n", sizeof(float), sizeof(long long));
//	printf("uns int == %lu;\n", sizeof(unsigned int));
	ft_print_bits(temp);
*/	double a;
	long double b = 145456465445645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645645656346513215456445421111454564564564564564564564564545645645645645645645656.20;
	size_t c;
	printf("size_t == %lu;\n", sizeof(c));
	printf("double == %lu;\nlong double == %lu;\n", sizeof(a), sizeof(b));
//	printf("%Lf\n", b);
//	printf("nbr == %e;\nnbr == %f;\n", nbr, nbr);
//	printf("temp == %llhd;\n", temp);
	return (0);
}
