/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:54:57 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/25 15:15:21 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_left_u(char *ar, t_parse *one, t_hodl *size, int l)
{
	if (one->prec > l)
		size->i += ft_putnchar('0', one->prec - l);
	size->i += ft_putnst(ar, l);
	if (one->widht > MAX(l, one->prec))
	{
		if (one->prec > l)
			size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec));
		else
			size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec));
	}
}

void	print_right_u(char *ar, t_parse *one, t_hodl *size, int l)
{
	if (one->widht > one->prec)
	{
		if (one->flag[4] && one->prec == 0)
			size->i += ft_putnchar('0', one->widht - MAX(l, one->prec));
		else
			size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec));
		if (one->prec > l && ar[0] != '-')
			size->i += ft_putnchar('0', one->prec - l);
	}
	else
	{
		if (one->widht < one->prec)
			size->i += ft_putnchar('0', one->prec - l);
		else
			size->i += ft_putnchar('0', one->widht - l);
	}
	if (ar[0] == '0' && one->widht && one->q == -1 && one->prec == 0)
	{
		size->i += ft_putnchar(' ', 1);
		return ;
	}
	size->i += ft_putnst(ar, l);
}

int		parsing_u(va_list arg, t_parse *one, t_hodl *size)
{
	uintmax_t	i;
	int			len;
	char		*ar;

	i = 0;
	i = cast_unsigned(i, arg, one);
	ar = ft_uitoa(i);
	len = ft_strlen(ar);
	if (ar[0] == '0' && one->prec == 0 && !one->widht && one->q != 1)
		return (0);
	if (one->flag[0])
		print_left_u(ar, one, size, len);
	else
		print_right_u(ar, one, size, len);
	free(ar);
	return (0);
}
