/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:18:09 by jritchie          #+#    #+#             */
/*   Updated: 2018/12/07 17:48:59 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		b;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j] && needle[j] != '\0')
		{
			b = i;
			while (haystack[b] == needle[j] && needle[j] != '\0')
			{
				if (needle[j + 1] == '\0' && haystack[b] == needle[j])
					return ((char*)haystack + (b - j));
				b++;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
