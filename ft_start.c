/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:38:39 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/16 18:32:04 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	get_start_end(char **file, t_num *one)
{
	int i;

	i = 0;
	while (file[i])
	{
		if (ft_strequ(file[i], "##end"))
		{
			i++;
			one->end = ft_get_str_bfr_chr(file[i], ' ');
		}
		if (ft_strequ(file[i], "##start"))
		{
			i++;
			one->start = ft_get_str_bfr_chr(file[i], ' ');
		}
		i++;
	}
	if (!one->start && !one->end)
		ft_error();
}

void	check_hash_l(char **paths)
{
	int		i;
	char	*bfr;
	char	*aftr;

	i = 0;
	while (paths[i])
	{
		bfr = ft_get_str_bfr_chr(paths[i], '-');
		aftr = ft_get_str_aftr_chr(paths[i], '-');
		if (bfr[0] == '#' || bfr[0] == 'L' || aftr[0] == '#' || aftr[0] == 'L')
			ft_error();
		i++;
	}
}

char	**ft_strdup_two_dim_free(char **s1)
{
	char	**str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(str = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = ft_strdup(s1[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_strjoin_two_dim(char **dst, char *src)
{
	int len;
	int i;
	char **new;

	i = 0;
	len = count_len(dst);
	new = (char **)malloc(sizeof(char *) * (len + 2));
	while (i < len)
	{
		new[i] = ft_strdup(dst[i]);
		i++;
	}
	new[i++] = src;
	new[i] = NULL;
	if (dst)
	{
		arrdel(dst);
		free(dst);
		dst = NULL;
	}
	return (new);
}

char	**ft_read(int fd, char **file)
{
	int i;
	char *line;

	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
		file = ft_strjoin_two_dim(file, line);
	
	return (file);
}


char	**ft_parse(char **file, t_num *one)
{
	int		i;
	int		j;
	char	**paths;

	i = 0;
	j = 0;
	paths = NULL;
	one->ants = ft_atoi(file[i]);
	get_start_end(file, one);
	i++;
	while (file[i])
	{
		if (file[i][0] != '#' && file[i][0] != 'L')
		{
			while (!ft_check_symbol(file[i], '-'))
				i++;
			paths = ft_strjoin_two_dim(paths, ft_strdup(file[i]));
		}
		i++;
	}
	if (!i)
		ft_error();
	one->len = i;
	return (paths);
}

int		main(int argc, char **argv)
{
	char	**links;
	char	**file;
	char *op;
	t_num	one;
	int fd;

	file = NULL;
	// if (argv[1] || argc != 1)
	// 	ft_error();
	if (argc > 0)
		op = argv[1];
	fd = open(op, O_RDONLY);
	file = ft_read(fd, file);
	links = ft_parse(file, &one);
	arrdel(file);
	free(file);
	file = NULL;
	check_hash_l(links);
	if (one.ants <= 0)
		ft_error();
	ft_solve(links, one);
	arrdel(links);
	free(links);
	links = NULL;
	return (0);
}
