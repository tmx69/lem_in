/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:39:19 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/16 15:20:47 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
#define LEM_H
# include "libft/includes/ft_printf.h"

typedef struct	s_number
{
	char			*n;
	char			**road;
	int				size_road;
	int				visited;
	int				links;
	char			*parent;
	struct s_number	*next;
}				t_number;

typedef struct	s_farm
{
	t_number		*head;
	t_number		*tail;
	int				size;
}				t_farm;

typedef struct	s_num
{
		char	*start;
		char	*end;
		int		max_paths;
		char	*curr;
		int		ants;
		int		len;
		int		i;
		int 	j;
		int		count_r;
		int		cnt_r;
		int		min_r;
		int		count;
}				t_num;

int		ft_solve(char **paths, t_num one);
void	make_road(t_farm *rooms, t_farm *roads, char ***links, t_num one);
void	new_room(t_farm **rooms, char *val, char *prnt, int vis);
void	new_road(t_farm **roads, char **val);
t_farm	*new_struct(t_farm *rooms, t_farm *new_s);
void	print_rooms(t_farm *rooms);
void	print_road(t_number *road);
int		check_paths(char **links, t_num one, t_farm *rooms);
char	**del_link(char **links, t_number *room, t_num one);
void	print_arr(char **arr);
char	**del(char **links, int i);
void	print_room(t_number *rooms);
t_number	*sort_roads(t_number *roads);
void	ft_init(t_farm *rooms, t_farm *roads);
void	print_route(char *s);
int		ft_strlnlen(char *s, int size);
char	*del_up_to_space(char *s, t_num *one);
void 	print_lem2(char **s,t_number *roads, t_num one, t_farm *road);
void	print_lem(t_number *roads, t_num one, t_farm *road);
char	*del_h(char *s, int count, char *str);
void	list_del1(t_number **alst);
#endif