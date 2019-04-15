/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:47:15 by jritchie          #+#    #+#             */
/*   Updated: 2018/12/05 20:18:37 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *arr;

	if (size == (size_t)(-1))
		return (NULL);
	if (!(arr = (char *)malloc(size + 1)))
	{
		return (NULL);
	}
	else
		ft_memset(arr, '\0', size + 1);
	return (arr);
}
