/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:20:40 by jritchie          #+#    #+#             */
/*   Updated: 2018/12/07 18:40:06 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	length(char *s1, char c)
{
	int j;

	j = 0;
	while (s1[j] != c && s1[j] != '\0')
	{
		j++;
	}
	return (j);
}

static void	*ft_freemem(char **a, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		free(a[l]);
		i++;
	}
	free(a);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	len;
	size_t	x;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	x = ft_len((char *)s, c);
	if (!(s) || !(arr = (char **)malloc(sizeof(char*) * x + 1)))
		return (NULL);
	while (len < x)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (!(arr[len++] = ft_strsub(s, i, length((char *)s + i, c))))
			return (ft_freemem(arr, len));
		i = length((char *)s + i, c) + i;
	}
	arr[len] = NULL;
	return (arr);
}
