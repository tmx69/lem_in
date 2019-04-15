/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:37:55 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/01 14:36:34 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	long long int	n2;

	n2 = (long long int)n;
	if (n2 < 0)
	{
		ft_putchar('-');
		n2 = -n2;
	}
	if (n2 < 10)
	{
		ft_putchar(n2 + 48);
	}
	else
	{
		ft_putnbr(n2 / 10);
		ft_putnbr(n2 % 10);
	}
}
