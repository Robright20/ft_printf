#include <stdio.h>
#include <stdarg.h>
#define ARGS_BUF "csp,diouxX,feg,#0-+ i,ll,hh,lhL,brk,',*,$"
#define ARGS_SIZE 32

int		ft_strncmp(char *s1, char *s2, int n);

void	save_options(char *flags, char *format, int argw)
{
	char	*s;
	int		pos;

	s = ARGS_BUF;
	pos = 0;
	while (*s)
	{
	//	printf("%c\n", *s);
		if (ft_strncmp(s, format, argw))
		{
			flags[pos] = 1;
			break ;
		}
		else if (*s == *format)
		{
			flags[pos] = 1;
			break ;
		}
		s += 1 + ft_strncmp(s, s + 1, argw - 1);
	//	s += 1 + (s[0] == s[1]);
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

int		main(void)
{
	static char	flags[ARGS_SIZE];
	char		*args;
	int			i;
	int			o;

	args = "pp";
	i = 0;
	while (args[i])
	{
		o = first_char_nbr(&args[i]);
		printf("o %d\n", o);
		save_options(flags, &args[i], o);
		args += o;
		//args += 1 + ft_strncmp(args, args + 1, ARGW - 1);
	}
	i = 0;
	while (i < ARGS_SIZE)
		printf("%d", flags[i++]);
	printf("\n");
	return (0);
}
