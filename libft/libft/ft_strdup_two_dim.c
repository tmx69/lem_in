/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_two_dim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:18:32 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/16 13:45:34 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_two_dim(char **s1)
{
	char	**str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(str = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = ft_strdup(s1[i]);
		i++;
	}
	// str[i] = NULL;
	// free_arr(&s1);
	return (str);
}
