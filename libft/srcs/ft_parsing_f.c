/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:22:19 by rywisozi          #+#    #+#             */
/*   Updated: 2019/02/25 17:05:13 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*print_left_f(char *ar, t_parse *one)
{
	int		i;
	int		s;

	i = 0;
	s = ft_strlen(ar);
	while (one->widht-- > s)
	{
		if (one->flag[0])
		{
			one->pm = 1;
			ar = ft_strjoin_free_first(ar, " ");
		}
		else
		{
			if (one->flag[4] == 1)
				ar = ft_strjoin_free_second("0", ar);
			else
				ar = ft_strjoin_free_second(" ", ar);
			one->sign = 1;
		}
	}
	return (ar);
}

char	*prin_f(char *a)
{
	int	i;

	i = ft_strlen(a);
	if (a[i - 1] >= 53)
	{
		a[i - 2] += 1;
		a[i - 1] = '\0';
	}
	if (ft_strchr(a, 58))
		a = prinf(a, i);
	else
		a[i - 1] = '\0';
	return (a);
}

char	*prinf2(char *a, int i, int flag)
{
	ft_bzero(&a[--i], 2);
	flag = 1;
	while (--i >= 0)
	{
		if (flag == 1 && a[i] == 57)
		{
			a[i] = 48;
			flag = 1;
			if (i == 0)
				a = ft_strjoin_free_second("1", a);
		}
		else
		{
			a[i] += 1;
			break ;
		}
	}
	return (a);
}

char	*prin_f2(char *a)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (a[i] != '.')
		i++;
	ft_bzero(&a[i + 2], ft_strlen(a) - i);
	i = ft_strlen(a) - 1;
	if (a[i] >= 53 && a[i - 2] < 57)
	{
		a[i - 2] += 1;
		ft_bzero(&a[i - 1], 1);
	}
	else if (a[i] == 57)
		a = prinf2(a, i, flag);
	else
		ft_bzero(&a[--i], 2);
	return (a);
}

void	parsing_f(va_list arg, t_parse *one, t_hodl *size)
{
	char			*a;
	int				i;
	unsigned long	l;
	long double		b;

	b = (!one->lenght || one->lenght[0] == 'l') ? va_arg(arg, double)
	: va_arg(arg, long double);
	l = (unsigned long)b;
	if (b < 0)
	{
		b = b * -1;
		l = (unsigned long)(b);
		one->fminus = 1;
	}
	a = ft_strjoin_free_first(ft_itoa(l), ".");
	i = (one->prec == 0) ? 7 : one->prec + 1;
	while (i-- > 0)
	{
		b = b - l;
		l = b * 10;
		a = ft_strjoin_free(a, ft_itoa(l));
		b = b * 10;
	}
	b_minus(a, one, size);
}
