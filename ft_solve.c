/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:07:44 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/16 15:40:39 by rywisozk         ###   ########.fr       */
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
	char *before;
	char *after;

	i = 0;
	n = 0;
	nb = 0;
	while (i < one.len)
	{
		before = ft_get_str_bfr_chr(links[i], '-');
		after = ft_get_str_aftr_chr(links[i], '-');
		if (ft_strequ(before, one.start) ||
			ft_strequ(after, one.start))
			n++;
		if (ft_strequ(before, one.end) ||
			ft_strequ(after, one.end))
			nb++;
		i++;
	}
	nb = nb <= n ? nb : n;
	i = find_min_visited(rooms, one);
	nb = i <= nb ? i : nb;
	// free(before);
	// free(after);
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

void	free_str(t_number *rooms)
{
	t_number	*temp;
	int			i;

	i = 0;
	while (rooms)
	{
		temp = rooms->next;
		free(rooms);
		rooms = temp;
	}
	rooms = NULL;
}

t_farm	del_paths(t_farm paths, int i)
{
	t_number	*temp;
	t_number	*road;

	i--;
	road = paths.head;
	while (i)
	{
		road = road->next;
		i--;
	}
	// while (road)
	// {
	// 	temp = road;
	// 	if (temp->next)
	// 		road = temp->next;
	// 	ft_printf("sss");
	// 	free(temp);
	// 	if (road->next)
	// 		road = road->next;
	// 	else
	// 		road = NULL;
	// }
	road->next = NULL;
	return (paths);
}

t_farm	choose_paths(t_farm paths, int ants)
{
	t_number	*road;
	int			i;
	int			prev;
	int			res;

	i = 1;
	road = paths.head;
	prev = 1000000;
	res = (ants / i) - 1 + road->size_road;
	road = road->next;
	i++;
	while (road && res < prev)
	{
		prev = res;
		res = (ants / i) - 1 + road->size_road;
		ft_printf("res: %d\n", res);
		ft_printf("prev: %d\n", prev);
		if (res >= prev)
		{
			i--;
			break ;
		}
		road = road->next;
		if (road)
			i++;
	}
	// ft_printf("i: %d\n", i);
	paths = del_paths(paths, i);
	return (paths);
}
void	list_del1(t_number **alst)
{
	t_number *tmp;
	t_number *swap;

	tmp = *alst;
	if (tmp == NULL)
		return ;
	while (tmp)
	{
		swap = tmp->next;
		free(tmp);
		tmp = swap;
	}
	*alst = NULL;
}
int		ft_solve(char **links, t_num one)
{
	t_farm	rooms;
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
			// free_str(rooms.head);
			// free_str(roads.head);
			// free(rooms.tail);
			check_paths(links, one, &rooms);
			make_road(&rooms, &roads, &links, one);
		}
	roads.head = sort_roads(roads.head);
	// ft_printf("ants: %d\n", one.ants);
	// ft_printf("nb of roads: %d\n", roads.size);
	// print_road(roads.head);
	if (roads.size > 1)
		roads = choose_paths(roads, one.ants);
	// print_road(roads.head);
	print_lem(roads.head, one, &roads);
	
	list_del1(&rooms.head);
	// free_arr(&links);
	// free_str(rooms.head);
	// free_str(roads.head);
	// print_lem(roads, one);
	return (0);
}
