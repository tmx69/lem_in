/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:26:05 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/25 11:15:55 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	cast_unsigned(uintmax_t n, va_list arg, t_parse *one)
{
	if (one->lenght)
	{
		if (one->lenght[0] == 'l' && one->lenght[1] == 'l')
			n = va_arg(arg, unsigned long long);
		else if (one->lenght[0] == 'l')
			n = va_arg(arg, unsigned long);
		else if (one->lenght[0] == 'h' && one->lenght[1] == 'h')
			n = (unsigned char)va_arg(arg, unsigned int);
		else if (one->lenght[0] == 'h')
			n = (unsigned short)va_arg(arg, unsigned int);
		else if (one->lenght[0] == 'j')
			n = va_arg(arg, uintmax_t);
		else if (one->lenght[0] == 'z')
			n = va_arg(arg, size_t);
	}
	else
		n = va_arg(arg, unsigned int);
	return (n);
}

intmax_t	cast_signed(intmax_t n, va_list arg, t_parse *one)
{
	if (one->lenght)
	{
		if (one->lenght[0] == 'l' && one->lenght[1] == 'l')
			n = va_arg(arg, long long);
		else if (one->lenght[0] == 'l')
			n = va_arg(arg, long);
		else if (one->lenght[0] == 'h' && one->lenght[1] == 'h')
			n = (char)va_arg(arg, int);
		else if (one->lenght[0] == 'h')
			n = (short)va_arg(arg, int);
		else if (one->lenght[0] == 'j')
			n = va_arg(arg, intmax_t);
		else if (one->lenght[0] == 'z')
			n = va_arg(arg, size_t);
	}
	else
		n = va_arg(arg, int);
	return (n);
}
