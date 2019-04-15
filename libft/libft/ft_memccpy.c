/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:15:35 by jritchie          #+#    #+#             */
/*   Updated: 2018/12/05 16:49:27 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*src2;
	unsigned char	*dst2;

	c2 = (unsigned char)c;
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == c2)
		{
			dst2[i] = c2;
			return (dst2 + i + 1);
		}
		i++;
	}
	return (NULL);
}
