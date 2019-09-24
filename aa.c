#include <stdio.h>

char *printfloat(float f)
{
	double		d = f;
	int			i;
	int			com_pos;
	long long 	n;

	com_pos = 0;
	i = 0;
	while (f > 1)
	{
		f *= 0.1;
		com_pos++;
	}
	printf("%f\n", f);
	printf("%d\n", com_pos);
	tmp = f;
	while (tmp - (long)f)
	{
		f *= 10;
		i++;
	}
	s = malloc(sizeof(char) * (i + 2));
	while (f - (long)f != 0 && i < 19)
	{
		f *= 10;
		i++;
	}
	printf("count == %d;\n", count);
	n = (long long)f;

	return (NULL);
}

int main()
{
	char *s;

	s = printfloat(12.325);
}
