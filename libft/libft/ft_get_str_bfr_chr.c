/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_bfr_chr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:26:49 by jritchie          #+#    #+#             */
/*   Updated: 2019/03/27 14:13:22 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_str_bfr_chr(char *arr, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (arr[i] != c && arr[i])
		i++;
	if (arr[i] != c)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	while (--i >= 0)
		str[i] = arr[i];
	return (str);
}
