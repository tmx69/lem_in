/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_road.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:10:47 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/16 18:36:00 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		check_path(t_number **rooms, int vis, char *parent, t_num one)
{
	t_number	*temp;
	t_number	*buf;

	temp = *rooms;
	while (*rooms)
	{
		if (ft_strequ((*rooms)->parent, parent) && (*rooms)->visited > vis)
		{
			buf = *rooms;
			parent = (*rooms)->n;
			vis = (*rooms)->visited;
			if (ft_strequ(one.end, (*rooms)->n))
			{
				*rooms = temp;
				return (1);
			}
		}
		if ((*rooms)->next)
			*rooms = (*rooms)->next;
		else
			break ;
	}
	buf->visited = 0;
	*rooms = temp;
	return (0);
}

void	new_path(t_number **rooms, char ***road, char *parent, t_num one)
{
	int i;
	int	vis;

	vis = 1;
	i = 1;
	while (*rooms)
	{
		if (ft_strequ((*rooms)->parent, parent) && (*rooms)->visited > vis)
		{
			(*road)[i] = ft_strdup((*rooms)->n);
			i++;
			parent = (*rooms)->n;
			vis = (*rooms)->visited;
			(*rooms)->visited = 0;
			if (ft_strequ((*rooms)->n, one.end))
				(*road)[i] = NULL;
		}
		*rooms = (*rooms)->next;
	}
}

int		ft_make(t_number *rooms, t_num one, char ***road)
{
	int			vis;
	char		*parent;
	t_number	*tmp;

	if (!rooms)
		return (0);
	tmp = rooms;
	(*road)[0] = ft_strdup(rooms->n);
	parent = rooms->n;
	vis = rooms->visited;
	rooms = rooms->next;
	while (rooms)
	{
		if (ft_strequ(rooms->parent, parent) && rooms->visited > vis)
		{
			if (check_path(&rooms, vis, parent, one))
			{
				new_path(&rooms, &(*road), parent, one);
				return (1);
			}
			else
				rooms = tmp;
		}
		rooms = rooms->next;
	}
	return (0);
}

int		check_valid(t_farm *rooms, char **road, t_num one)
{
	int			i;
	t_number	*tmp;

	tmp = rooms->head;
	i = 0;
	while (road[i + 1])
		i++;
	if (ft_strequ(road[i], one.end))
	{
		if (ft_strequ(tmp->parent, one.start))
			return (1);
	}
	return (0);
}

void	make_road(t_farm *rooms, t_farm *roads, t_num one)
{
	int			i;
	char		**road;
	t_number	*temp;
	t_farm		new_s;

	new_struct(rooms, &new_s);
	temp = new_s.head;
	road = (char **)malloc(sizeof(char *) * 100);
	i = 0;
	while (temp->visited == 1)
	{
		if ((ft_make(temp, one, &road)))
		{
			if (check_valid(&new_s, road, one))
				new_road(&roads, road);
			i++;
		}
		else
			temp = temp->next;
		if (i == one.max_paths)
		{
			i = 0;
			temp = temp->next;
		}
	}
	list_del1(&temp);
}
