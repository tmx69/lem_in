/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:01:30 by jritchie          #+#    #+#             */
/*   Updated: 2019/02/25 13:26:57 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *data, char *buf)
{
	char	*res;
	size_t	i;

	i = ft_strlen(data) + ft_strlen(buf);
	if (!(res = ft_strnew(i)))
		return (NULL);
	ft_strcpy(res, data);
	ft_strcat(res, buf);
	ft_strdel(&data);
	ft_strdel(&buf);
	return (res);
}

char	*ft_strjoin_free_first(char *data, char *buf)
{
	char	*res;
	size_t	i;

	i = ft_strlen(data) + ft_strlen(buf);
	if (!(res = ft_strnew(i)))
		return (NULL);
	ft_strcpy(res, data);
	ft_strcat(res, buf);
	ft_strdel(&data);
	return (res);
}

char	*ft_strjoin_free_second(char *data, char *buf)
{
	char	*res;
	size_t	i;

	i = ft_strlen(data) + ft_strlen(buf);
	if (!(res = ft_strnew(i)))
		return (NULL);
	ft_strcpy(res, data);
	ft_strcat(res, buf);
	ft_strdel(&buf);
	return (res);
}
