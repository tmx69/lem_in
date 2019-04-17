/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:09:19 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/11 15:16:35 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_rooms(t_farm *rooms)
{
	t_number *tmp;

	tmp = rooms->head;
	while (tmp)
	{
		ft_printf("room: %s, parent: %s, visited: %d\n", tmp->n, tmp->parent, tmp->visited);
		tmp = tmp->next;
	}
}

void	print_room(t_number *rooms)
{
	t_number *tmp;

	tmp = rooms;
	while (tmp)
	{
		ft_printf("room: %s, parent: %s, visited: %d\n", tmp->n, tmp->parent, tmp->visited);
		tmp = tmp->next;
	}
}

void	print_road(t_number *road)
{
	t_number *tmp;
	int i;

	tmp = road;
	while (tmp)
	{
		i = 0;
		ft_printf("size_road: %d | ", tmp->size_road);
		ft_printf("road: ");
		ft_printf("%s", tmp->road[i++]);
		while (tmp->road[i])
			ft_printf("-%s", tmp->road[i++]);
		tmp = tmp->next;
		ft_printf("\n");
	}
}

void	print_lem(t_number *roads, t_num one)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (one.ants)
	{
		while (j < one.max_paths)
		{
			ft_printf("L%d-%s", i, roads->road[0]);
			ft_printf(" ");
			i++;
			roads = roads->next;
			j++;
		}
		one.ants--;
	}
}
