/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:07:44 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/12 14:44:11 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		find_min_visited(t_farm *rooms, t_num one)
{
	t_number	*tmp;
	int			i;
	int			nb;

	nb = 100000;
	i = 1;
	tmp = rooms->head;
	while (tmp->next && !(ft_strequ(tmp->next->n, one.end)))
	{
		if (tmp->visited == tmp->next->visited)
			i++;
		else
		{
			if (nb > i)
				nb = i;
			i = 1;
		}
		tmp = tmp->next;
	}
	nb = nb == 0 ? 1 : nb;
	return (nb);
}

int		find_max_nb_paths(char **links, t_num one, t_farm *rooms)
{
	int i;
	int n;
	int nb;

	i = 0;
	n = 0;
	nb = 0;
	while (i < one.len)
	{
		if (ft_strequ(ft_get_str_bfr_chr(links[i], '-'), one.start) ||
			ft_strequ(ft_get_str_aftr_chr(links[i], '-'), one.start))
			n++;
		if (ft_strequ(ft_get_str_bfr_chr(links[i], '-'), one.end) ||
			ft_strequ(ft_get_str_aftr_chr(links[i], '-'), one.end))
			nb++;
		i++;
	}
	nb = nb <= n ? nb : n;
	i = find_min_visited(rooms, one);
	nb = i <= nb ? i : nb;
	return (nb);
}

int		check_same(t_number *roads, t_num one, int size)
{
	int			i;
	int			j;
	t_number	*temp;

	temp = roads;
	if (size < 2)
		return (0);
	while (temp)
	{
		i = 0;
		while (!ft_strequ(temp->road[i], one.end))
		{
			j = 0;
			while (temp->next && !ft_strequ(temp->next->road[j], one.end))
			{
				if (ft_strequ(temp->road[i], temp->next->road[j]))
					return (0);
				j++;
			}
			i++;
		}
		temp = temp->next;
	}
	return (1);
}

void	check_valid_paths(t_number *rooms, t_num one)
{
	t_number	*temp;
	int			flag;

	flag = 0;
	temp = rooms;
	while (temp)
	{
		if (ft_strequ(temp->n, one.end))
			flag = 1;
		temp = temp->next;
	}
	if (!flag)
		ft_error();
}

int		ft_solve(char **links, t_num one)
{
	t_farm	rooms;
	char	*r;
	t_farm	roads;

	ft_init(&rooms, &roads);
	one.curr = one.start;
	check_paths(links, one, &rooms);
	check_valid_paths(rooms.head, one);
	one.max_paths = find_max_nb_paths(links, one, &rooms);
	make_road(&rooms, &roads, &links, one);
	if (one.ants > 1)
		while (!check_same(roads.head, one, roads.size) && one.max_paths != 1)
		{
			links = del_link(links, rooms.head, one);
			one.len = count_len(links);
			ft_init(&rooms, &roads);
			one.curr = one.start;
			check_paths(links, one, &rooms);
			make_road(&rooms, &roads, &links, one);
		}
	roads.head = sort_roads(roads.head);
	print_road(roads.head);
	print_lem(roads.head, one, &rooms);
	return (0);
}
