/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:50:10 by jritchie          #+#    #+#             */
/*   Updated: 2019/03/22 14:14:46 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_hodor	*find_fd(t_hodor **lst, int fd)
{
	t_hodor	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->fdd == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_hodor *)malloc(sizeof(t_hodor))))
		return (NULL);
	if (!(temp->arr = ft_strnew(0)))
		return (NULL);
	temp->fdd = fd;
	temp->next = *lst;
	*lst = temp;
	return (temp);
}

static char		*get_line(char **tmp)
{
	int 	i;
	char	*p;
	char	*line;

	i = 0;
	if (!(p = ft_strdup(*tmp)))
		return (NULL);
	while (p[i] != '\0' && p[i] != '\n')
		i++;
	line = ft_strsub(*tmp, 0, i);
	ft_strdel(tmp);
	if (i < ft_strlen(p))
	{
		if (!(*tmp = ft_strdup(ft_strchr(p, '\n') + 1)))
			return (NULL);
	}
	else
	{
		if (!(*tmp = ft_strnew(0)))
			return (NULL);
	}
	ft_strdel(&p);
	return (line);
}

static char		*ft_strjoinfree(char **data, char *buf)
{
	char	*res;
	int		i;

	i = ft_strlen(*data) + ft_strlen(buf);
	if (!(res = ft_strnew(i)))
		return (NULL);
	ft_strcpy(res, *data);
	ft_strcat(res, buf);
	ft_strdel(data);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static t_hodor	*list;
	t_hodor			*work;
	int				a;
	char			temp[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, temp, 0) < 0)
		return (-1);
	if (!(work = find_fd(&list, fd)))
		return (-1);
	while ((a = read(fd, temp, BUFF_SIZE)) > 0)
	{
		temp[a] = '\0';
		work->arr = ft_strjoinfree(&work->arr, temp);
		if (ft_strchr(work->arr, '\n'))
			break ;
	}
	if (!(ft_strlen(work->arr)))
		return (0);
	*line = get_line(&work->arr);
	return (1);
}
