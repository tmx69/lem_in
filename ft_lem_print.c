/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:01:45 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/17 13:45:52 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

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
    str = NULL;
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
		free(s);
		s = NULL;
		str = NULL;
		one->ants = one->ants - 1;
	}
	else
		str = del_h(s, count, str);
	ft_strdel(&s);
	// free(s);
	// s= NULL;
	return (str);
}

void	print_lem2(char **s,t_number *roads, t_num one, t_farm *road)
{
	int	i;
	int	valstart;

	roads = road->head;
	one.cnt_r = road->size;
	i = one.ants;
	// ft_printf("ONE _C%d\n", one.cnt_r);
	// ft_printf("road SIZE%d\n", road->size);
	while (one.ants > 0)
	{
		valstart = 0;
		// ft_printf("ROAD_SIZE|%d|\n", road->size);
		while (valstart < road->size)
		{
			if (s[valstart])
			{
				// ft_printf("valstart|%d|\n", valstart);
				// ft_printf("VALSTARt:%d\n", valstart);
				// ft_printf("|%s|\n", s[valstart]);
				print_route(s[valstart]);
				s[valstart] = del_up_to_space(s[valstart], &one);
			}
			valstart++;
		}
		// ft_printf("|%s|\n", s[0]);
		if (one.ants > 1)
		{
			if ((road->size + one.cnt_r) <= i)
				road->size = road->size + one.cnt_r;
			else
				road->size++;
		}
		ft_printf("\n");
	}
}

char    *prnt_lem(t_num one, char *s, t_number *roads, int c)
{
	one.i = 0;
	while (roads->road[one.i])
	{
		if (one.i != 0)
		{
			s = ft_strjoin_free_first(s, " ");
			s = ft_strjoin_free_first(s, "L");
			s = ft_strjoin_free(s, ft_itoa(c));
			s = ft_strjoin_free_first(s, "-");
			s = ft_strjoin_free_first(s, roads->road[one.i]);
		}
		else
		{
			s = ft_strjoin_free_second("L", ft_itoa(c));
			s = ft_strjoin_free_first(s, "-");
			s = ft_strjoin_free_first(s, roads->road[one.i]);
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
	roads = road->head;
	ft_printf("count_road:%d\n", road->size);
	ft_printf("Ants:%d\n", one.ants);
	s = (char**)malloc(sizeof(char*) * one.ants + 1);
	c = 1;
	while (c <= one.ants)
	{
		// s[one.j] = (char*)malloc(sizeof(char));
		// one.j++;
		s[one.j] = prnt_lem(one, s[one.j], roads, c);
		one.j++;
		c++;
		if (roads->next == NULL)
			roads = road->head;
		else
			roads = roads->next;
	}
	s[one.j] = NULL;
		one.i = 0;
	// ft_printf("SIZE%d", road->size);
	// while (s[one.i])
	// {
	// 	ft_printf("%s\n",s[one.i]);
	// 	one.i++;
	// }
	print_lem2(s, roads, one, road);
	// one.i = 0;
	// one.i = 0;
	// ft_printf("\n");
	// while (roads->road[one.i])
	// {
	// 	ft_printf("%s\n",roads->road[one.i]);
	// 	one.i++;
	// }

	// ft_printf("%s\n",roads->road[one.i]);
	// one.i = 0;
	// while (s[one.i])
	// {
	// 	free(s[one.i]);
	// 	s[one.i] = NULL;
	// 	one.i++;
	// }
	// free(s);
	// s = NULL;
}