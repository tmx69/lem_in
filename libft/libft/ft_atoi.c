/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:45:34 by jritchie          #+#    #+#             */
/*   Updated: 2019/01/31 17:04:15 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				j;
	long long int	a;
	long long int	temp;

	i = 0;
	j = 0;
	a = 0;
	temp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		j = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = a;
		a = a * 10 + (str[i] - '0');
		if (temp > a)
			return (j == 1 ? 0 : -1);
		i++;
	}
	return (j == 1 ? a * -1 : a);
}
