/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:38:28 by rywisozk          #+#    #+#             */
/*   Updated: 2019/02/25 17:13:43 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*mp(char *a, t_parse *one)
{
	int i;

	i = ft_strlen(a) - 1;
	if (one->pm == 1)
		a[i] = '\0';
	return (a);
}

char	*sign(char *a, t_parse *one)
{
	if (!one->flag[4])
	{
		if (one->fminus == 1)
			a = ft_strjoin_free_second("-", mp(a, one));
		else if (one->flag[1])
			a = ft_strjoin_free_second("+", mp(a, one));
	}
	if (one->flag[4] && one->sign == 1)
	{
		if (one->fminus == 1)
			a[0] = '-';
		else if (one->flag[1])
			a[0] = '+';
	}
	else if (one->flag[4] && one->sign != 1)
	{
		if (one->fminus == 1)
			a = ft_strjoin_free_second("-", mp(a, one));
		else if (one->flag[1])
			a = ft_strjoin_free_second("+", mp(a, one));
	}
	return (a);
}

char	*znak(char *a, t_parse *one)
{
	int		i;

	i = 0;
	while (a[i] == ' ')
		i++;
	if (i > 0)
	{
		if (one->fminus == 1)
			a[i - 1] = '-';
		else if (one->flag[1])
			a[i - 1] = '+';
	}
	if (i == 0)
		a = sign(a, one);
	return (a);
}

char	*prinf(char *a, int i)
{
	while (ft_strchr(a, 58))
	{
		if (a[i] == 58)
		{
			a[i] = '0';
			if (i == 0)
			{
				a = ft_strjoin_free_second("1", a);
				break ;
			}
			if (a[i - 1] != '.')
				a[i - 1] += 1;
			else
				a[i - 2] += 1;
		}
		i--;
	}
	return (a);
}

void	b_minus(char *a, t_parse *one, t_hodl *size)
{
	int i;

	if (one->q == 1 && one->prec > 0)
	{
		i = ft_strlen(a);
		a[i - 1] = '\0';
	}
	if (one->prec >= 0)
		a = prin_f(a);
	if (one->prec == 0 && one->q == -1)
		a = prin_f2(a);
	if (one->widht > 0 || !one->widht)
		a = hashf(a, one);
	a = znak(a, one);
	if (one->flag[3] == 1 && one->q == -1 && one->prec == 0)
		a = ft_strjoin_free_first(a, ".");
	i = 0;
	while (a[i])
		size->i += ft_putchar_size(a[i++]);
	ft_strdel(&a);
}
