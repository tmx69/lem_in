/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:32:29 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/12 11:39:51 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_arr(char ***arr)
{
	int i;

	i = count_len(*arr);
	while (i > 0)
	{
		ft_strdel(&(*arr)[i]);
		i--;
	}
	free(*arr);
	*arr = NULL;
}
