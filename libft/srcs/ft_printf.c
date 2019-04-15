/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:57:46 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/25 17:16:02 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		thirdfoo(va_list arg, t_parse one, t_hodl *size)
{
	if (one.type == '%')
		parsing_per(&one, size);
	if (one.type == 'c')
		parsing_c(arg, &one, size);
	if (one.type == 's')
		parsing_s(arg, &one, size);
	if (one.type == 'p')
		parsing_p(arg, &one, size);
	if (one.type == 'd')
		parsing_di(arg, &one, size);
	if (one.type == 'u')
		parsing_u(arg, &one, size);
	if (one.type == 'U')
	{
		one.lenght = "l";
		parsing_u(arg, &one, size);
	}
	if (one.type == 'o')
		parsing_o(arg, &one, size);
	if (one.type == 'x' || one.type == 'X')
		parsing_x(arg, &one, size);
	if (one.type == 'f')
		parsing_f(arg, &one, size);
	return (0);
}

char	*secondfoo(char *format, va_list arg, t_parse one, t_hodl *size)
{
	while (*format == '-' || *format == '+' || *format == ' ' || *format == '#'
	|| *format == '0' || *format == '*' || *format == '.' || *format == 'l' ||
	*format == 'j' || *format == 'h' || *format == 'L' || *format == 'z' ||
	ft_isdigit(*format))
	{
		format = ft_parse_flags(format, &one);
		format = ft_parse_widht(format, arg, &one);
		format = ft_parse_prec(format, arg, &one);
		format = ft_parse_lenght(format, &one);
	}
	if (one.q != -1)
		one.q = 1;
	one.flag[5] ? one.flag[4] = '\0' : 0;
	format = ft_parse_type(format, &one);
	one.flag[1] ? one.flag[2] = 0 : 0;
	one.flag[0] ? one.flag[4] = 0 : 0;
	size->sign = 0;
	size->minus = 0;
	size->plus = 0;
	size->space = 0;
	thirdfoo(arg, one, size);
	return (format);
}

int		firstfoo(const char *format, va_list arg, t_hodl *size)
{
	char	*ptr;
	t_parse one;

	ptr = ft_strchr(format, '%');
	if (*format == '\0')
		return (0);
	if (ptr == NULL)
	{
		size->i += ft_putstr(format);
		return (size->i);
	}
	else if (format < ptr)
	{
		ft_putnst(format, ptr - format);
		size->i += ptr - format;
		return (firstfoo(ptr, arg, size));
	}
	else
	{
		ft_bzero(&one, sizeof(one));
		ptr = secondfoo(ptr + 1, arg, one, size);
		return (firstfoo(ptr, arg, size));
	}
	return (size->i);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	arg;
	t_hodl	*size;
	int		res;

	res = 0;
	size = (t_hodl *)malloc(sizeof(t_hodl) * 10);
	ft_bzero(size, sizeof(*size));
	va_start(arg, format);
	firstfoo(format, arg, size);
	va_end(arg);
	res = size->i;
	free(size);
	return (res);
}
