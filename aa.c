#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

char *printfloat(float d)
{
	double		f = d;
	int			i;
	int			coma_pos;
	long long 	n;

	coma_pos = 0;
	i = 0;
	while (f > 1)
	{
		f *= 0.1;
		coma_pos++;
	}
	printf("f apres decalage == %f\n", f);
	printf("come_pos == %d\n", coma_pos);
	double	tmp = f;
	while (tmp - (long long)tmp)
	{
		tmp *= 10;
		i++;
	}
	char *decim_char;
	printf("we have found nbr of digit == %i;\n", i);
	decim_char = malloc(sizeof(char) * (i + 2)); // +2 one for \0 and the other for dot
	i = 0;
	int integ;
	while (f - (long long)f != 0 && i < 19)
	{
		f *= 10;
		integ = (int)f;
		if (i == coma_pos)
			decim_char[i++] = '.';
		decim_char[i] = integ + '0';
		i++;
		f = f - (float)integ;
		printf("integ == %d;\n", integ);
		
	}
	printf("count == %d;\n", i);
	printf("string = %s;\n", decim_char);
	n = (long long)f;

	return (NULL);
}

int main()
{
	char *s;
	float nbr = 123456789.325123456789;
	s = printfloat(nbr);
	printf("float  = %.20f;\n", nbr);
}
