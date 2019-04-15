/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:32:17 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/11 19:34:12 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	ft_init(t_farm *rooms, t_farm *roads)
{
	rooms->size = 0;
	rooms->head = NULL;
	rooms->tail = NULL;
	roads->size = 0;
	roads->head = NULL;
	roads->tail = NULL;
}

int		count_len(char **links)
{
	int i;

	i = 0;
	while (links[i])
		i++;
	return (i);
}

int		compare(int i, int j)
{
	return (i <= j ? 1 : 0);
}

t_number	*sort_roads(t_number *roads)
{
	int			overflow;
	char		**tmp;
	t_number	*start;

	start = roads;
	while (roads->next)
	{
		if (compare(roads->size_road, roads->next->size_road) == 0)
		{
			overflow = roads->size_road;
			tmp = roads->road;
			roads->size_road = roads->next->size_road;
			roads->road = roads->next->road;
			roads->next->size_road = overflow;
			roads->next->road = tmp;
			roads = start;
		}
		else
			roads = roads->next;
	}
	roads = start;
	return (start);
}
