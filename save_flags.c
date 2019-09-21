#include <stdio.h>
#include <stdarg.h>
#define ARGS_BUF "csp,diouxX,feg,#0-+ i,ll,hh,lhL,brk,',*,$"
#define ARGS_SIZE 32

int		ft_strncmp(char *s1, char *s2, int n);

void	save_flag(char *flags, char *format, int argw)
{
	char	*s;
	int		pos;

	s = ARGS_BUF;
	pos = 0;
	while (*s)
	{
		if (ft_strncmp(s, format, argw) == argw)
		{
			if (s[0] != s[argw])
			{
				flags[pos] = 1;
				break ;
			}
			else
				s += argw;
		}
		s++;
		if (*s != ',')
			pos++;
	}
}

int		ft_strncmp(char *s1, char *s2, int n)
{
	int		rep;

	rep = n;
	while (n)
	{
		if ((*s1 && *s2))
		{
			if (*s1 != *s2)
				return (0);
		}
		else
			return (*s1 == *s2);
		(void)(s1++ && s2++ && n--);
	}
	return (rep);
}

int		first_char_nbr(char *s)
{
	int		i;
	int		rep;

	(void)((i = 1) && (rep = 1));
	while(s[i] && (s[0] == s[i++]))
		rep++;
	return (rep);
}

void	save_all_flags(char *flags, char *args)
{
	int			o;

	while (*args)
	{
		o = first_char_nbr(args);
		save_flag(flags, args, o);
		args += o;
	}
}

int		main(void)
{
	static char	flags[ARGS_SIZE];
	char		*args;
	int			i;

	args = "phhlL";
	save_all_flags(flags, args);
	i = 0;
	while (i < ARGS_SIZE)
		printf("%d", flags[i++]);
	printf("\n");
	return (0);
}
