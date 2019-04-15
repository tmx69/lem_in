/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:14:24 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/25 11:21:07 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_left_s(char *a, t_parse *one, t_hodl *size, int l)
{
	if (one->prec)
	{
		one->prec > l ? size->i += ft_putnst(a, l) :
		(size->i += ft_putnst(a, one->prec));
		if (one->prec < l)
			size->i += ft_putnchar(' ', one->widht - one->prec);
		else if (one->prec > l)
			size->i += ft_putnchar(' ', one->widht - l);
	}
	else if (one->widht)
	{
		size->i += ft_putnst(a, l);
		if (one->widht > l && !one->flag[4])
			size->i += ft_putnchar(' ', one->widht - l);
	}
	else
		size->i += ft_putnst(a, l);
}

void	print_right_s(char *a, t_parse *one, t_hodl *size, int l)
{
	if (one->prec)
	{
		if (one->flag[4] && one->prec < l)
			size->i += ft_putnchar('0', one->widht - one->prec);
		else if (one->flag[4] && one->prec > l)
			size->i += ft_putnchar('0', one->widht - l);
		else if (one->prec < l)
			size->i += ft_putnchar(' ', one->widht - one->prec);
		else if (one->prec > l)
			size->i += ft_putnchar(' ', one->widht - l);
		size->i += one->prec > l ? ft_putnst(a, l) : (ft_putnst(a, one->prec));
	}
	else if (one->widht)
	{
		if (one->widht > l && !one->flag[4])
			size->i += ft_putnchar(' ', one->widht - l);
		else if (one->widht > l && one->flag[4])
			size->i += ft_putnchar('0', one->widht - l);
		if (one->prec > l || one->prec == 0)
			size->i += ft_putnst(a, l);
		else if (one->prec < l)
			size->i += ft_putnst(a, one->prec);
	}
	else
		size->i += ft_putnst(a, l);
}

int		parsing_s(va_list arg, t_parse *one, t_hodl *size)
{
	char	*a;
	int		l;

	a = va_arg(arg, char *);
	if (a == NULL)
	{
		if (!one->widht)
			size->i += ft_putstr("(null)");
		else
			size->i += ft_putnchar('0', one->widht);
		return (0);
	}
	l = ft_strlen(a);
	if (one->q == -1 && one->prec == 0)
		size->i += ft_putnchar(' ', one->widht);
	else if (one->flag[0])
		print_left_s(a, one, size, l);
	else
		print_right_s(a, one, size, l);
	return (0);
}
