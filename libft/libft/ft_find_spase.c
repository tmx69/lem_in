/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_spase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:13:02 by jritchie          #+#    #+#             */
/*   Updated: 2019/03/22 15:21:11 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find_spase(char *arr)
{
	char	*str;
	int		i;

	i = 0;
	while (arr[i] != ' ')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	while (--i >= 0)
		str[i] = arr[i];
	return (str);
}
