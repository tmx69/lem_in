/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_two_dim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:18:32 by jritchie          #+#    #+#             */
/*   Updated: 2019/03/25 11:25:44 by jritchie         ###   ########.fr       */
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
	str[i] = NULL;
	return (str);
}
