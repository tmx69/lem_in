/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:38:39 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/15 10:45:17 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	get_start_end(char *line, int fd, t_num *one)
{
	while (!ft_strequ(line, "##start"))
		if (get_next_line(fd, &line) <= 0)
			ft_error();
	get_next_line(fd, &line);
	if (!(one->start = ft_get_str_bfr_chr(line, ' ')))
		ft_error();
	while (!ft_strequ(line, "##end"))
		if (get_next_line(fd, &line) <= 0)
			ft_error();
	get_next_line(fd, &line);
	if (!(one->end = ft_get_str_bfr_chr(line, ' ')))
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
	// free_arr(&s1);
	return (str);
}


char	**ft_read(int fd, t_num *one)
{
	char	*line;
	int		i;
	char	**paths;
	char	**new;

	line = NULL;
	i = 0;
	paths = (char **)malloc(sizeof(char *) * 20000);
	get_next_line(fd, &line);
	one->ants = ft_atoi(line);
	// free(line);
	get_start_end(line, fd, one);
	// free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '#' && line[0] != 'L')
		{
			while (!ft_check_symbol(line, '-'))
			{
				// free(line);
				get_next_line(fd, &line);
			}
			paths[i++] = ft_strdup(line);
		}
		// free(line);
	}
	if (!i)
		ft_error();
	paths[i] = NULL;
	// new = ft_strdup_two_dim_free(paths);
	// free_arr(&paths);
	one->len = i;
	return (paths);
}

int		main(int argc, char **argv)
{
	char	*file;
	char	**links;
	int		fd;
	t_num	one;

	// if (argv[1])
	// 	ft_error();
	// links = ft_read(0, &one);
	file = argv[1];
		fd = open(file, O_RDONLY);
		links = ft_read(fd, &one);
	check_hash_l(links);
	if (one.ants <= 0)
		ft_error();
	ft_solve(links, one);

	return (0);
}
