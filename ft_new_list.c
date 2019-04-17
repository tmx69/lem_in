/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:09:57 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/16 18:33:52 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	new_room(t_farm **rooms, char *val, char *prnt, int vis)
{
	t_number *new;

	new = (t_number *)malloc(sizeof(t_number));
	new->next = NULL;
	new->n = val;
	new->parent = prnt;
	new->visited = vis;
	if (!(*rooms)->head)
		(*rooms)->head = new;
	if ((*rooms)->tail)
		(*rooms)->tail->next = new;
	(*rooms)->tail = new;
	(*rooms)->size++;
	// free(*rooms);
	// free(val);
}

void	new_road(t_farm **roads, char **val)
{
	t_number *new;

	new = (t_number *)malloc(sizeof(t_number));
	new->next = NULL;
	new->road = ft_strdup_two_dim(val);
	new->size_road = count_len(val);
	if (!(*roads)->head)
		(*roads)->head = new;
	if ((*roads)->tail)
		(*roads)->tail->next = new;
	(*roads)->tail = new;
	(*roads)->size++;
	// arrdel(val);
}

t_farm	*new_struct(t_farm *rooms, t_farm *new_s)
{
	t_number *tmp;

	new_s->size = 0;
	new_s->head = NULL;
	new_s->tail = NULL;
	tmp = rooms->head;
	while (tmp)
	{
		new_room(&new_s, tmp->n, tmp->parent, tmp->visited);
		tmp = tmp->next;
	}
	return (new_s);
}
