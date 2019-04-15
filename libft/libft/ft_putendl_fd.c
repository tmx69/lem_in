/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:53:19 by jritchie          #+#    #+#             */
/*   Updated: 2018/12/04 19:49:14 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char *s2;

	if (s)
	{
		s2 = (char *)s;
		while (*s2)
		{
			ft_putchar_fd(*s2, fd);
			s2++;
		}
		ft_putchar_fd('\n', fd);
	}
}
