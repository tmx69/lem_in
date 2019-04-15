/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:51:22 by jritchie          #+#    #+#             */
/*   Updated: 2018/11/29 16:42:52 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	l;
	unsigned char	*ch;
	size_t			i;

	i = 0;
	l = c;
	ch = (unsigned char *)b;
	while (i < n)
	{
		ch[i] = l;
		i++;
	}
	return (ch);
}
