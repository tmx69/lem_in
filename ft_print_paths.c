/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:09:19 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/15 17:21:37 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_rooms(t_farm *rooms)
{
	t_number *tmp;

	tmp = rooms->head;
	while (tmp)
	{
		ft_printf("room: %s, parent: %s, visited: %d\n",
		tmp->n, tmp->parent, tmp->visited);
		tmp = tmp->next;
	}
}

void	print_room(t_number *rooms)
{
	t_number *tmp;

	tmp = rooms;
	while (tmp)
	{
		ft_printf("room: %s, parent: %s, visited: %d\n",
		tmp->n, tmp->parent, tmp->visited);
		tmp = tmp->next;
	}
}

void	print_road(t_number *road)
{
	t_number	*tmp;
	int			i;

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

void	print_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		ft_printf("%s\n", arr[i++]);
}

void	print_route(char *s)
{
	int i;

	i = 0;
	if (s && s != NULL)
	{
		while (s && s[i] != ' ')
		{
			ft_printf("%c", s[i]);
			i++;
			if (s[i] == 'L' || s[i] == '\0')
				break ;
		}
	}
	ft_printf(" ");
}

int		ft_strlnlen(char *s, int size)
{
	while (s[size])
	{
		size++;
	}
	return (size);
}
