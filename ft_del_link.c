/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:02:28 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/16 17:59:45 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		count_link(t_number *room)
{
	char		*link;
	t_number	*tmp;
	int			i;

	i = 0;
	tmp = room;
	link = tmp->parent;
	while (tmp)
	{
		if (ft_strequ(tmp->parent, link))
			i++;
		tmp = tmp->next;
	}
	if (i > 1)
		return (1);
	return (0);
}

char	**del(char **links, int i)
{
	char	**new1;
	char	**new2;
	int		j;

	j = 0;
	new2 = ft_strdup_two_dim(links + i + 1);
	new1 = ft_strdup_two_dim(links);
	while (new1[i])
		new1[i++] = new2[j++];
	new1[i - 1] = NULL;
	// free(new2);
	return (new1);
}

char	**find_del_link(char **links, t_number *room)
{
	char	*src1;
	char	*src2;
	int		i;

	i = 0;
	while (links[i])
	{
		src1 = ft_get_str_bfr_chr(links[i], '-');
		src2 = ft_get_str_aftr_chr(links[i], '-');
		if ((ft_strequ(src1, room->n) && ft_strequ(src2, room->parent))
		|| (ft_strequ(src2, room->n) && ft_strequ(src1, room->parent)))
		{
			links = del(links, i);
			free(src1);
			free(src2);
			return (links);
		}
		i++;
	free(src1);
	free(src2);
	}
	return (0);
}

int		check_parents(t_number *rooms)
{
	char		*tmp;
	t_number	*buf;
	int			i;

	i = 0;
	tmp = rooms->parent;
	buf = rooms;
	while (buf && ft_strequ(tmp, rooms->parent))
	{
		if (ft_strequ(rooms->n, buf->parent))
			i++;
		buf = buf->next;
	}
	if (i > 1)
		return (1);
	return (0);
}

char	**del_link(char **links, t_number *room, t_num one)
{
	t_number	*tmp;

	tmp = room;
	while (ft_strequ(tmp->parent, one.start))
		tmp = tmp->next;
	while (tmp)
	{
		if (count_link(tmp))
		{
			if (tmp && !check_parents(tmp))
				tmp = tmp->next;
			if (tmp)
				links = find_del_link(links, tmp);
			return (links);
		}
		else
			tmp = tmp->next;
	}
	return (links);
}
