/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:21:03 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/16 16:09:55 by rywisozk         ###   ########.fr       */
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
		one->ants = one->ants - 1 ;
	}
	else
		str = del_h(s, count, str);
	free(s);
	s = NULL;
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
	ft_printf("count_road:%d\n", road->size);
	ft_printf("Ants:%d\n", one.ants);
	s = (char**)malloc(sizeof(char*) * 1000);
	c = 1;
	while (c <= one.ants)
	{
		// s[one.j] = (char*)malloc(sizeof(char));
		s[one.j] = prnt_lem(one, s[one.j], roads, c);
		one.j++;
		c++;
		if (roads->next == NULL)
			roads = road->head;
		else
			roads = roads->next;
	}
	print_lem2(s, roads, one, road);
	one.i = 0;
	while (s[one.i])
	{
		free(s[one.i]);
		s[one.i] = NULL;
		one.i++;
	}
	free(s);
	s = NULL;
}
