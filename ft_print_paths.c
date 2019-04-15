/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:09:19 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/12 18:22:55 by rywisozk         ###   ########.fr       */
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

char	*del_up_to_space(char *s, t_num *one)
{
	int		count;
	int		length;
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
	{
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
	}
	return(str);
}

void 	print_lem2(char **s,t_number *roads, t_num one, t_farm *road)
{
	int i;
	int	j;
	int	ValStart;
	j = 0;
	i = 0;
	// while(s[i])
	// {
	// 	printf("%s",s[i]);
	// 	printf("\n");
	// 	i++;
	// }
	// printf("\n");
	ValStart = 0;
	roads = road->head;
	one.cnt_r = one.count_r;
	while (one.ants > 0)
	{
		ValStart = 0;
		while (ValStart < one.count_r)
		{
			if (s[ValStart])
			{
				print_route(s[ValStart]);
				s[ValStart] = del_up_to_space(s[ValStart], &one);
			}
			ValStart++;
		}
		if (one.count_r <= one.ants)
		{
			if ((one.count_r + one.cnt_r) <= one.ants)
				one.count_r = one.count_r + one.cnt_r;
			else
				one.count_r++;
		}
		ft_printf("\n");
	}
}
void	print_lem(t_number *roads, t_num one, t_farm *road)
{
	int 		i;
	int			j;
	t_number	*tmp;
	j = 0;
	i = 1;
	char		**s;
	int c = 0;
	tmp = roads;
	road->head = roads;
	while (tmp)
	{
		one.count_r++;
		tmp = tmp->next;
	}
	// ft_printf("Ants:%d\n", one.ants);
	// ft_printf("count_road:%d\n", one.count_r);
	s = (char**)malloc(sizeof(char*) * 1000);
	c = 1;
	while (c <= one.ants)
	{
		s[j] = (char*)malloc(sizeof(char) * 10);
		i = 0;
		while (roads->road[i])
		{
			// printf("|%s|", roads->road[i]);
			if (i != 0)
			{
				s[j] = ft_strjoin(s[j], " ");
				s[j] = ft_strjoin(s[j], "L");
				s[j] = ft_strjoin(s[j], ft_itoa(c));
				s[j] = ft_strjoin(s[j], "-");
				s[j] = ft_strjoin(s[j], roads->road[i]);
			}
			else
			{
			s[j] = ft_strjoin("L", ft_itoa(c));
			s[j] = ft_strjoin(s[j], "-");
			s[j] = ft_strjoin(s[j], roads->road[i]);
			}
			i++;
		}
		j++;
		// printf("\n");
		c++;
			if (roads->next == NULL)
				roads = road->head;
			else
				roads = roads->next;
	}
	print_lem2(s, roads, one, road);
}
// void	print_lem(t_number *roads, t_num one, t_farm *road)
// {
// 	int 		i;
// 	int			j;
// 	t_number	*tmp;
// 	j = 0;
// 	i = 1;
// 	char		**s;
// 	char		**s1;
// 	int c = 0;
// 	int	b= 0;
// 	tmp = roads;
// 	road->head = roads;
// 	one.min_r = 2147483646;
// 	while (tmp)
// 	{
// 		one.count_r++;
// 		i = 0;
// 		while (tmp->road[i])
// 		{
// 			i++;
// 		}
// 		if (i < one.min_r)
// 			one.min_r = i;
// 		tmp = tmp->next;
// 	}
// 	ft_printf("Ants:%d\n", one.ants);
// 	ft_printf("count_road:%d\n", one.count_r);
// 	s = (char**)malloc(sizeof(char*) * 1000);
// 	c = 1;
// 	while (c <= one.ants)
// 	{
// 		s[j] = (char*)malloc(sizeof(char) * 10);
// 		i = 0;
// 		while (roads->road[i])
// 		{
// 			printf("|%s|", roads->road[i]);
// 			if (i != 0)
// 			{
// 				s[j] = ft_strjoin(s[j], " ");
// 				s[j] = ft_strjoin(s[j], "L");
// 				s[j] = ft_strjoin(s[j], ft_itoa(c));
// 				s[j] = ft_strjoin(s[j], "-");
// 				s[j] = ft_strjoin(s[j], roads->road[i]);
// 			}
// 			else
// 			{
// 			s[j] = ft_strjoin("L", ft_itoa(c));
// 			s[j] = ft_strjoin(s[j], "-");
// 			s[j] = ft_strjoin(s[j], roads->road[i]);
// 			}
// 			// j++;
// 			i++;
// 		}
// 		j++;
// 		printf("\n");
// 		c++;
// 		if (one.max_paths >= one.ants)
// 		{
// 			if (roads->next)
// 				roads = roads->next;
// 		}
// 	}

// 	print_lem2(s, roads, one, road);
// }

// void 	print_lem2(char **s,t_number *roads, t_num one, t_farm *road)
// {
// 	int i;
// 	int	j;
// 	int	ValStart;
// 	int ants;
// 	char **s1;
// 	int		*l;
// 	j = 0;
// 	i = 0;
// 	printf("\n");
// 	i = 0;
// 	ValStart = 0;
// 	roads = road->head;
// 	l = (int*)malloc(sizeof(int) * one.ants);
// 	ft_bzero(l, one.ants);
// 	one.count = 1;
// 	one.cnt_r = one.count_r;
// 	while (one.ants >= 0)
// 	{
// 		ValStart = 1;
// 		ants = one.count;
// 		ft_printf("|COUNT_R %d|", one.cnt_r);
// 		while (ValStart < one.cnt_r - 1)
// 		{
// 			if (roads->road[l[ValStart]] != '\0')
// 				print_ant(ants, roads->road[l[ValStart]]);
// 			else
// 			{
// 				one.ants--;
// 				one.count++;
// 			}
// 			if (roads->next == NULL)
// 				roads = road->head;
// 			else
// 				roads = roads->next;
// 			ValStart++;
// 			ants++;
// 		}
// 		i = 0;
// 		while (ValStart > 0)
// 		{
// 			l[i] += 1;
// 			ValStart--;
// 			i++;
// 		}
// 		if (one.cnt_r <= one.ants - 1)
// 		{
// 			one.cnt_r = one.cnt_r + one.count_r;
// 			// if ((one.cnt_r + one.count_r) < one.ants)
// 			// 	one.cnt_r = one.cnt_r + one.count_r;
// 			// else
// 			// {
// 			// 	while (one.cnt_r <= one.ants)
// 			// 		one.cnt_r++;
// 			// }
// 		}
// 		ft_printf("\n");
// 	}
// }
// void	print_lem(t_number *roads, t_num one, t_farm *road)
// {
// 	int 		i;
// 	int			j;
// 	t_number	*tmp;
// 	j = 0;
// 	i = 1;
// 	char		**s;
// 	char		**s1;
// 	int c = 0;
// 	int	b= 0;
// 	tmp = roads;
// 	road->head = roads;
// 	one.min_r = 2147483646;
// 	while (tmp)
// 	{
// 		one.count_r++;
// 		i = 0;
// 		while (tmp->road[i])
// 		{
// 			i++;
// 		}
// 		if (i < one.min_r)
// 			one.min_r = i;
// 		tmp = tmp->next;
// 	}
// 	ft_printf("Ants:%d\n", one.ants);
// 	ft_printf("count_road:%d\n", one.count_r);
// 	s = (char**)malloc(sizeof(char*) * 1000);
// 	c = 1;
// 	while (c <= one.ants)
// 	{
// 		s[j] = (char*)malloc(sizeof(char) * 10);
// 		i = 0;
// 		while (roads->road[i])
// 		{
// 			printf("|%s|", roads->road[i]);
// 			if (i != 0)
// 			{
// 				s[j] = ft_strjoin(s[j], " ");
// 				s[j] = ft_strjoin(s[j], "L");
// 				s[j] = ft_strjoin(s[j], ft_itoa(c));
// 				s[j] = ft_strjoin(s[j], "-");
// 				s[j] = ft_strjoin(s[j], roads->road[i]);
// 			}
// 			else
// 			{
// 			s[j] = ft_strjoin("L", ft_itoa(c));
// 			s[j] = ft_strjoin(s[j], "-");
// 			s[j] = ft_strjoin(s[j], roads->road[i]);
// 			}
// 			// j++;
// 			i++;
// 		}
// 		j++;
// 		printf("\n");
// 		c++;
// 		if (one.max_paths >= one.ants)
// 		{
// 			if (roads->next)
// 				roads = roads->next;
// 		}
// 	}

// 	print_lem2(s, roads, one, road);
// }
