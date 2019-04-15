/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:58:33 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/19 16:34:15 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count(long long *n, int *i, int *minus)
{
	if (*n < 0)
	{
		*n *= -1;
		*i = 2;
		*minus = -1;
	}
}

char		*ft_itoa(long long n)
{
	int			i;
	long long	n2;
	int			minus;
	char		*arr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	i = 1;
	minus = 1;
	ft_count(&n, &i, &minus);
	n2 = n;
	while (n /= 10)
		i++;
	if (!(arr = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		arr[i] = n2 % 10 + '0';
		n2 = n2 / 10;
	}
	if (minus == -1)
		arr[0] = '-';
	return (arr);
}

char		*ft_uitoa(uintmax_t n)
{
	int			i;
	uintmax_t	n2;
	char		*arr;

	i = 1;
	n2 = n;
	while (n /= 10)
		i++;
	if (!(arr = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		arr[i] = n2 % 10 + '0';
		n2 = n2 / 10;
	}
	return (arr);
}
