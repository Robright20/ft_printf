/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:57:29 by fokrober          #+#    #+#             */
/*   Updated: 2019/09/22 21:47:32 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <strings.h>
# include <stdio.h>
# define ARGS_BUF "cspdiouxXfeg#0-+ llhhlhLbrk'*$"
# define ARGS_SIZE 32

int		ft_strnstr(char *s1, char *s2, int n);
void	save_flag(char *flags, char *format, int argw);
int		first_char_nbr(char *s);
void	save_all_flags(char *flags, char *args);
#endif
