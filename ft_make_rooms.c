/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:03:42 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/16 15:14:14 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		visited(t_number *rooms, char *room, t_num one)
{
	t_number *tmp;

	tmp = rooms;
	while (tmp)
	{
		if (ft_strequ(room, tmp->n))
		{
			if (!ft_strequ(room, one.end) && tmp->visited != one.i - 1)
				return (1);
			else
				return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		find_link(t_farm **rooms, char *link, char *room, t_num one)
{
	char *before;
	char *after;

	before = ft_get_str_bfr_chr(link, '-');
	after = ft_get_str_aftr_chr(link, '-');
	if (ft_strequ(room, before) && !ft_strequ(".", link) &&
		!ft_strequ(".", link))
	{
		if (!visited((*rooms)->head, after, one))
		{
			free(before);
			free(after);
			return (2);
		}
	}
	else if (ft_strequ(room, after) && !ft_strequ(".", link) &&
			!ft_strequ(".", link))
	{
		if (!visited((*rooms)->head, before, one))
		{
			free(before);
			free(after);
			return (1);
		}
	}
	// free(link);
	free(before);
	free(after);
	return (0);
}

void	mark_visit(char **lnks)
{
	char *arr;

	arr = ft_strnew(2);
	arr[0] = '.';
	// ft_strdel(&(*lnks));
	*(lnks) = arr;
}

char	*make_queue(t_farm **rooms, char ***lnks, t_num one)
{
	int		i;
	t_farm	*temp;

	i = 0;
	temp = *rooms;
	while (i < one.len)
	{
		if (find_link(&temp, (*lnks)[i], one.curr, one) == 1 &&
		!ft_strequ(one.curr, one.end))
		{
			new_room(&temp, ft_get_str_bfr_chr((*lnks)[i], '-'),
			one.curr, one.i);
			mark_visit(&(*lnks)[i]);
		}
		else if (find_link(&temp, (*lnks)[i], one.curr, one) == 2 &&
		!ft_strequ(one.curr, one.end))
		{
			new_room(&temp, ft_get_str_aftr_chr((*lnks)[i], '-'),
			one.curr, one.i);
			mark_visit(&(*lnks)[i]);
		}
		i++;
	}
	return (temp->head->n);
}

int		check_paths(char **links, t_num one, t_farm *rooms)
{
	int			i;
	char		**temp;
	t_number	*tmp;

	i = 0;
	one.i = 1;
	temp = ft_strdup_two_dim(links);
	// temp = links;
	one.curr = make_queue(&rooms, &temp, one);
	one.i++;
	tmp = (*rooms).head;
	while (i < one.len)
	{
		make_queue(&rooms, &temp, one);
		if (!tmp || !tmp->next)
			break ;
		tmp = tmp->next;
		one.curr = tmp->n;
		if (tmp->visited == one.i)
			one.i++;
		i++;
	}
	// i = 0;
	// while (temp[i])
	// {
	// // 	ft_strdel(&temp[i]);
	// 	free(temp[i]);
	// 	i++;
	// }
	// free(temp);
	// temp = NULL;
	// free(tmp);
	// free_arr(&temp);
	// free(rooms->head);
	return (1);
}
