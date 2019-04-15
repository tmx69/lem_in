/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:57:33 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/25 15:14:13 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_left_o(uintmax_t i, t_parse *one, t_hodl *size, int l)
{
	if (one->prec > l)
		size->i += ft_putnchar('0', one->prec - l);
	else if (one->flag[3])
		size->i += ft_putnchar('0', 1);
	to_hex_pointer(i, one, 8, size);
	if (one->widht > MAX(l, one->prec))
	{
		if (one->prec > l)
			size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec));
		else
			size->i += ft_putnchar(' ', one->widht -
			MAX(l, one->prec) - one->flag[3]);
	}
}

void	print_right_otwo(uintmax_t i, t_parse *one, t_hodl *size, int l)
{
	if (one->flag[4] && one->prec == 0)
		size->i += ft_putnchar('0', one->widht - MAX(l, one->prec) -
		one->flag[3]);
	else if (i > 0 && l > one->prec)
		size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec) -
		one->flag[3]);
	else
		size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec));
	if (one->prec > l && i > 0)
		size->i += ft_putnchar('0', one->prec - l - one->flag[3]);
	else
		size->i += ft_putnchar('0', one->prec - l);
}

void	print_right_o(uintmax_t i, t_parse *one, t_hodl *size, int l)
{
	if (one->widht > one->prec)
		print_right_otwo(i, one, size, l);
	else
	{
		if (one->widht < one->prec && i > 0)
			size->i += ft_putnchar('0', one->prec - l - one->flag[3]);
		else if (one->widht < one->prec)
			size->i += ft_putnchar('0', one->prec - l);
		else
			size->i += ft_putnchar('0', one->widht - l - one->flag[3]);
	}
	one->flag[3] && i > 0 ? size->i += ft_putstr("0") : 0;
	if (i == 0 && one->widht && one->q == -1 && one->prec == 0)
		one->flag[3] ? size->i += ft_putnchar('0', 1) :
		(size->i += ft_putnchar(' ', 1));
	else
		to_hex_pointer(i, one, 8, size);
}

int		parsing_o(va_list arg, t_parse *one, t_hodl *size)
{
	uintmax_t	i;
	char		*ar;
	int			len;

	i = 0;
	i = cast_unsigned(i, arg, one);
	ar = ft_itoa(i);
	len = to_hex(i, 8, 0, one);
	if (ar[0] == '0' && one->prec == 0 && !one->widht &&
	one->q == -1 && !one->flag[3])
		return (0);
	if (one->flag[0])
		print_left_o(i, one, size, len);
	else
		print_right_o(i, one, size, len);
	free(ar);
	return (0);
}
