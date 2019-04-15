/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:49:56 by jritchie          #+#    #+#             */
/*   Updated: 2019/03/20 11:53:58 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	char *s2;

	s2 = (char *)s;
	if (s2)
	{
		while (*s2)
		{
			ft_putchar(*s2);
			s2++;
		}
		ft_putchar('\n');
	}
}
