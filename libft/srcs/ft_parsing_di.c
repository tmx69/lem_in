/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:02:18 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/25 15:13:28 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putnstrn(char const *s, size_t num)
{
	char	*s2;
	int		i;

	i = num;
	if (s)
	{
		s2 = (char *)s;
		while (s2[num])
		{
			ft_putchar(s2[num]);
			num++;
		}
	}
	return (num - i);
}

void	print_left_di(char *ar, t_parse *one, t_hodl *size, int l)
{
	if (ar[0] == '-')
	{
		one->flag[0] && one->prec ? size->minus = 1 : 0;
		size->i += ft_putchar_size('-');
		size->i += ft_putnchar('0', one->prec - l + 1);
		size->i += ft_putnstrn(ar, 1);
		size->i += ft_putnchar(' ', one->widht - size->space -
		size->plus - size->minus - MAX(l, one->prec));
		return ;
	}
	if (one->prec && !size->plus)
		size->i += ft_putnchar('0', one->prec - size->plus - l - size->minus);
	one->flag[1] ? size->i += ft_putchar_size('+') : 0;
	if (one->flag[1])
		size->i += ft_putnchar('0', one->prec - l);
	size->i += ft_putnst(ar, l);
	if (one->widht)
		size->i += ft_putnchar(' ', one->widht - size->minus -
		size->space - size->plus - MAX(l, one->prec));
}

void	print_right_di_two(char *ar, t_parse *one, t_hodl *size, int l)
{
	if (ar[0] == '-')
	{
		if (l <= one->prec)
			size->i += ft_putnchar(' ', one->widht - size->space -
			MAX(l, one->prec) - 1);
		else
			size->i += ft_putnchar(' ', one->widht - size->space -
			MAX(l, one->prec));
		size->i += ft_putchar_size('-');
		size->i += ft_putnchar('0', one->prec - l + 1);
		size->i += ft_putnstrn(ar, 1);
		return ;
	}
	size->i += ft_putnchar(' ', one->widht - size->space - size->minus -
	size->plus - MAX(l, one->prec));
	if (one->flag[4] && one->pzero && ar[0] == '0')
	{
		size->i += ft_putnst(" +", 2);
		return ;
	}
	one->flag[1] ? size->i += ft_putchar_size('+') : 0;
	size->i += ft_putnchar('0', one->prec - l);
	size->i += ft_putnst(ar, l);
}

void	print_right_di(char *ar, t_parse *one, t_hodl *size, int l)
{
	if (!one->prec)
	{
		if (ar[0] == '0' && one->widht && one->q != 1)
			ar[0] = ' ';
		if (one->flag[4])
		{
			ar[0] == '-' ? size->i += ft_putchar_size('-') : 0;
			size->i += ft_putnchar('0', one->widht - size->plus -
			size->space - size->minus - MAX(l, one->prec));
		}
		else
		{
			size->i += ft_putnchar(' ', one->widht - size->space -
			size->plus - MAX(l, one->prec));
			size->i += ft_putnchar('0', one->prec - size->plus - l);
			one->flag[1] && ar[0] != '-' ? size->i += ft_putchar_size('+') : 0;
		}
		size->i += ar[0] == '-' && one->flag[4] ? ft_putnstrn(ar, 1) :
		ft_putnst(ar, l);
	}
	else
		print_right_di_two(ar, one, size, l);
}

int		parsing_di(va_list arg, t_parse *one, t_hodl *size)
{
	intmax_t	i;
	int			len;
	char		*ar;

	i = cast_signed(0, arg, one);
	ar = ft_itoa(i);
	len = ft_strlen(ar);
	if (one->flag[1] && ar[0] != '-')
	{
		size->plus = 1;
		size->i += one->flag[1] && one->flag[4] ? ft_putchar_size('+') : 0;
	}
	if (!one->flag[1] && ar[0] != '-' && one->flag[2])
	{
		size->i += ft_putchar_size(' ');
		size->space = 1;
	}
	if (ar[0] == '0' && one->prec == 0 && !one->widht && one->q != 1)
		return (0);
	if (one->flag[0])
		print_left_di(ar, one, size, len);
	else
		print_right_di(ar, one, size, len);
	free(ar);
	return (0);
}
