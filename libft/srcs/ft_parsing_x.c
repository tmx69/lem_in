/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:44:53 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/25 15:15:34 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	to_hex_pointer(uintmax_t n, t_parse *one,
unsigned int base, t_hodl *size)
{
	char	*hex;

	one->type == 'x' || one->type == 'p' ? hex = "0123456789abcdef" :
	(hex = "0123456789ABCDEF");
	if (n > 4294967295 && !one->lenght)
		n = n - 4294967296;
	if (n < base)
	{
		one->type == 'p' ? size->i += ft_putstr("7fff") : 0;
		size->i += ft_putchar_size(hex[n]);
	}
	else
	{
		to_hex_pointer(n / base, one, base, size);
		size->i += ft_putchar_size(hex[n % base]);
	}
}

void	print_left_x(uintmax_t i, t_parse *one, t_hodl *size, int l)
{
	if (one->flag[3] && i > 0)
		size->i += one->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
	if (one->prec > l)
		size->i += ft_putnchar('0', one->prec - l);
	to_hex_pointer(i, one, 16, size);
	if (one->widht > MAX(l, one->prec))
	{
		if (one->prec > l && i == 0)
			size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec));
		else
			size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec) -
			one->flag[3]);
	}
}

void	print_right_xtwo(uintmax_t i, t_parse *one, t_hodl *size, int l)
{
	if (one->flag[4] && one->prec == 0)
		size->i += ft_putnchar('0', one->widht - MAX(l, one->prec) -
		one->flag[3]);
	else if (i > 0 && l > one->prec)
		size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec) -
		one->flag[3]);
	else
		size->i += one->flag[3] && i > 0 ? ft_putnchar(' ', one->widht -
		MAX(l, one->prec) - one->flag[3]) : ft_putnchar(' ', one->widht -
		MAX(l, one->prec));
	if (one->flag[3] && i > 0 && !one->flag[4])
		size->i += one->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
	if (one->prec > l && i > 0)
		size->i += ft_putnchar('0', one->prec - l);
	else
		size->i += ft_putnchar('0', one->prec - l);
}

void	print_right_x(uintmax_t i, t_parse *one, t_hodl *size, int l)
{
	if (one->flag[3] && (one->prec > one->widht || one->flag[4]) && i > 0)
		size->i += one->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
	if (one->widht >= one->prec)
		print_right_xtwo(i, one, size, l);
	else
	{
		if (one->widht < one->prec)
			size->i += ft_putnchar('0', one->prec - l);
		else
			size->i += ft_putnchar('0', one->widht - l - one->flag[3]);
	}
	if (i == 0 && !one->prec && one->q == -1)
	{
		one->widht ? size->i += ft_putnchar(' ', 1) : 0;
		return ;
	}
	to_hex_pointer(i, one, 16, size);
}

int		parsing_x(va_list arg, t_parse *one, t_hodl *size)
{
	uintmax_t	i;
	char		*ar;
	int			a;

	i = 0;
	i = cast_unsigned(i, arg, one);
	ar = ft_itoa(i);
	a = to_hex(i, 16, 0, one);
	if (one->flag[3])
		one->flag[3] = 2;
	if (ar[0] == '0' && one->prec == 0 && !one->widht && one->q == -1)
		return (0);
	if (one->flag[0])
		print_left_x(i, one, size, a);
	else
		print_right_x(i, one, size, a);
	free(ar);
	return (0);
}
