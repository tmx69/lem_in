/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:12:51 by jritchie          #+#    #+#             */
/*   Updated: 2018/12/04 18:22:58 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (s)
	{
		i = 0;
		j = ft_strlen((char *)s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[i] != '\0')
			j--;
		if (!(str = ft_strnew(j - i + 1)))
			return (0);
		k = 0;
		while (i <= j)
		{
			str[k++] = s[i++];
		}
		str[k] = '\0';
		return (str);
	}
	return (NULL);
}
