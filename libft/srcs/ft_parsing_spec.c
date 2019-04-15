/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:47:18 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/25 12:20:41 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_parse_flags(char *format, t_parse *one)
{
	if (*format == '-')
		one->flag[0] = 1;
	else if (*format == '+')
		one->flag[1] = 1;
	else if (*format == ' ')
		one->flag[2] = 1;
	else if (*format == '#')
		one->flag[3] = 1;
	else if (*format == '0')
		one->flag[4] = 1;
	else
		return (format);
	return (ft_parse_flags(format += 1, one));
}

char	*ft_parse_widht(char *format, va_list arg, t_parse *one)
{
	if (ft_isdigit(*format) || *format == '*')
	{
		if (*format == '*')
			one->widht = va_arg(arg, int) - one->prec;
		else
			while (ft_isdigit(*format))
				one->widht = one->widht * 10 + (*format++ - '0') - one->prec;
	}
	return (format);
}

char	*ft_parse_prec(char *format, va_list arg, t_parse *one)
{
	one->q = 0;
	if (*format == '.')
	{
		one->q = -1;
		if (*format == '.' && *(format + 1) == '.')
			one->flag[5] = '1';
		one->nul = 1;
		if (*format++ == '*')
			one->prec = va_arg(arg, int);
		else if (ft_isdigit(*format))
			while (ft_isdigit(*format))
				one->prec = one->prec * 10 + (*format++ - '0');
		else
			one->prec = 0;
		if (one->prec < 0)
			one->prec = 1;
	}
	else
		one->pzero = 1;
	return (format);
}

char	*ft_parse_lenght(char *format, t_parse *one)
{
	if (*format == 'l' && *(format + 1) == 'l')
	{
		one->lenght = "ll";
		return (ft_parse_lenght(format += 2, one));
	}
	else if (*format == 'l')
		one->lenght = "l";
	else if (*format == 'h' && *(format + 1) == 'h')
	{
		one->lenght = "hh";
		return (ft_parse_lenght(format += 2, one));
	}
	else if (*format == 'h')
		!one->lenght ? one->lenght = "h" : 0;
	else if (*format == 'L')
		one->lenght = "L";
	else if (*format == 'j')
		one->lenght = "j";
	else if (*format == 'z')
		one->lenght = "z";
	else
		return (format);
	return (ft_parse_lenght(format += 1, one));
}

char	*ft_parse_type(char *format, t_parse *one)
{
	if (*format == 'c')
		one->type = 'c';
	else if (*format == 's')
		one->type = 's';
	else if (*format == 'p')
		one->type = 'p';
	else if (*format == 'd' || *format == 'i')
		one->type = 'd';
	else if (*format == 'o')
		one->type = 'o';
	else if (*format == 'u')
		one->type = 'u';
	else if (*format == 'U')
		one->type = 'U';
	else if (*format == 'x')
		one->type = 'x';
	else if (*format == 'X')
		one->type = 'X';
	else if (*format == '%')
		one->type = '%';
	else if (*format == 'f')
		one->type = 'f';
	else
		return (format);
	return (format += 1);
}
