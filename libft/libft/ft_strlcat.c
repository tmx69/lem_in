/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:46:47 by jritchie          #+#    #+#             */
/*   Updated: 2018/11/29 13:31:48 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	i;

	x = ft_strlen(dst);
	y = ft_strlen((char *)src);
	if (size <= x)
		return (y + size);
	i = 0;
	while (src[i] && i < (size - x - 1))
	{
		dst[x + i] = src[i];
		i++;
	}
	dst[i + x] = '\0';
	return (x + y);
}
