/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_pcper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:49:01 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/25 11:20:07 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		to_hex(uintmax_t n, unsigned int base, int i, t_parse *one)
{
	char		*hex;
	static int	j;

	j = 0;
	hex = "0123456789abcdef";
	if (n < base)
		i = 1;
	else
	{
		j = i++;
		j = to_hex(n / base, base, j, one);
	}
	return (i + j);
}

void	to_hex_p(uintmax_t n, t_parse *one, unsigned int base, t_hodl *size)
{
	char	*hex;

	one->type == 'x' || one->type == 'p' ? hex = "0123456789abcdef" :
	(hex = "0123456789ABCDEF");
	if (!n && !one->prec && !one->pzero && one->q == -1)
		return ;
	if (n < base)
		size->i += ft_putchar_size(hex[n]);
	else
	{
		to_hex_p(n / base, one, base, size);
		size->i += ft_putchar_size(hex[n % base]);
	}
}

int		parsing_c(va_list arg, t_parse *one, t_hodl *size)
{
	if (one->flag[0])
	{
		size->i += ft_putchar_size((char)va_arg(arg, int));
		if (one->widht)
			size->i += ft_putnchar(' ', one->widht - 1);
	}
	else
	{
		if (one->widht)
		{
			if (one->flag[4])
				size->i += ft_putnchar('0', one->widht - 1);
			else
				size->i += ft_putnchar(' ', one->widht - 1);
		}
		size->i += ft_putchar_size((char)va_arg(arg, int));
	}
	return (one->size);
}

int		parsing_p(va_list arg, t_parse *one, t_hodl *size)
{
	int					l;
	unsigned long long	i;

	i = 0;
	i = va_arg(arg, unsigned long long);
	l = to_hex(i, 16, 0, one);
	if (!one->flag[0] && one->widht > one->prec && one->pzero == 1)
	{
		if (!one->flag[4])
			size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec) - 2);
	}
	else if (!one->flag[0] && one->widht > one->prec && one->pzero == 0)
		size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec) - 2);
	size->i += ft_putstr("0x");
	if (one->prec > l || one->pzero)
	{
		if (!one->flag[4] || one->prec)
			size->i += ft_putnchar('0', (one->prec - l));
		else
			size->i += ft_putnchar('0', (one->widht - l - 2));
	}
	to_hex_p(i, one, 16, size);
	if (one->flag[0] && ((one->widht > one->prec) || one->pzero))
		size->i += ft_putnchar(' ', one->widht - MAX(l, one->prec) - 2);
	return (one->size);
}

int		parsing_per(t_parse *one, t_hodl *size)
{
	if (one->flag[0])
	{
		size->i += ft_putchar_size('%');
		if (one->widht)
			size->i += ft_putnchar(' ', one->widht - 1);
	}
	else
	{
		if (one->widht)
		{
			if (one->flag[4])
				size->i += ft_putnchar('0', one->widht - 1);
			else
				size->i += ft_putnchar(' ', one->widht - 1);
		}
		size->i += ft_putchar_size('%');
	}
	return (0);
}
