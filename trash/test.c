#include <stdio.h>
#include <stdarg.h>

void	foo(int i, ...)
{
	va_list	ap;
	int		d;
	char	c, *s;

	va_start(ap, i);
	while (--i)
		va_arg(ap, void*);
	d = va_arg(ap, int);
	printf("%d\n", d);
}

int		main(void)
{
	int		a;

	(void)a;
	foo(1, "bonjour", &a, 2);
	return (0);
}
