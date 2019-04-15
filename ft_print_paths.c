/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:09:19 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/15 17:01:42 by rywisozk         ###   ########.fr       */
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

char	*del_h(char *s, int count, char *str)
{
	int length;

	length = ft_strlnlen(s, count);
	str = (char *)malloc(sizeof(char) * length);
	length = 0;
	while (s[count])
	{
		str[length] = s[count];
		length++;
		count++;
	}
	str[length] = '\0';
	return (str);
}

char	*del_up_to_space(char *s, t_num *one)
{
	int		count;
	char	*str;

	count = 0;
	while (s[count])
	{
		if (s[count] == ' ' && s[count + 1] != ' ')
		{
			count++;
			break ;
		}
		count++;
	}
	if (s[count] == '\0')
	{
		str = NULL;
		free(s);
		one->ants = one->ants - 1 ;
	}
	else
		str = del_h(s, count, str);
	return(str);
}

void 	print_lem2(char **s,t_number *roads, t_num one, t_farm *road)
{
	int	i;
	int	valstart;

	roads = road->head;
	one.cnt_r = road->size;
	i = one.ants;
	while (one.ants > 0)
	{
		valstart = 0;
		while (valstart < road->size)
		{
			if (s[valstart])
			{
				print_route(s[valstart]);
				s[valstart] = del_up_to_space(s[valstart], &one);
			}
			valstart++;
		}
			if ((road->size + one.cnt_r) <= i)
				road->size = road->size + one.cnt_r;
			else
				road->size++;
		ft_printf("\n");
	}
}

char *prnt_lem(t_num one, char *s, t_number *roads, int c)
{
	one.i = 0;
	while (roads->road[one.i])
	{
		if (one.i != 0)
		{
			s = ft_strjoin(s, " ");
			s = ft_strjoin(s, "L");
			s = ft_strjoin(s, ft_itoa(c));
			s = ft_strjoin(s, "-");
			s = ft_strjoin(s, roads->road[one.i]);
		}
		else
		{
			s = ft_strjoin("L", ft_itoa(c));
			s = ft_strjoin(s, "-");
			s = ft_strjoin(s, roads->road[one.i]);
		}
		one.i++;
	}
	return (s);
}

void	print_lem(t_number *roads, t_num one, t_farm *road)
{
	int		c;
	char	**s;

	one.j = 0;
	ft_printf("count_road:%d\n", road->size);
	ft_printf("Ants:%d\n", one.ants);
	s = (char**)malloc(sizeof(char*) * 1000);
	c = 1;
	while (c <= one.ants)
	{
		s[one.j] = (char*)malloc(sizeof(char) * 10);
		s[one.j] = prnt_lem(one, s[one.j], roads, c);
		one.j++;
		c++;
		if (roads->next == NULL)
			roads = road->head;
		else
			roads = roads->next;
	}
	print_lem2(s, roads, one, road);
	free(s);
}
