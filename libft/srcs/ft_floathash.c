/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floathash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:33:40 by rywisozk          #+#    #+#             */
/*   Updated: 2019/02/25 17:14:16 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*hashf(char *a, t_parse *one)
{
	int		i;

	a = print_left_f(a, one);
	if (one->flag[2] && one->sign != 1)
	{
		a = ft_strjoin_free_second(" ", a);
		if (one->pm == 1)
		{
			i = ft_strlen(a) - 1;
			a[i] = '\0';
		}
	}
	else if (one->flag[2])
		a[0] = ' ';
	return (a);
}
