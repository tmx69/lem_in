/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:28:20 by jritchie          #+#    #+#             */
/*   Updated: 2019/03/22 17:08:13 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_symbol(char *arr, char c)
{
	int i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == c)
			return (1);
		i++;
	}
	return (0);
}
