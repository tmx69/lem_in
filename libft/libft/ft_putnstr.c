/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:27:06 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/22 18:06:57 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnst(char const *s, size_t num)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s)
	{
		s2 = (char *)s;
		while (i < num)
		{
			ft_putchar(s2[i]);
			i++;
		}
	}
	return (i);
}
