/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_aftr_chr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 10:42:22 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/12 13:25:16 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_str_aftr_chr(char *arr, char c)
{
	char	*str;
	int		i;

	i = 0;
	arr = ft_strchr(arr, c);
	if (arr)
	{
		arr++;
		while (arr[i])
			i++;
		str = (char *)malloc(sizeof(char) * (i + 1));
		str[i] = '\0';
		while (--i >= 0)
			str[i] = arr[i];
		return (str);
	}
	// ft_strdel(&arr);
	return (NULL);
}
