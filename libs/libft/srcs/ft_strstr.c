/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:19:14 by slimon            #+#    #+#             */
/*   Updated: 2019/05/26 21:58:10 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int needle_len;

	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (haystack[++i])
		if (haystack[i] == *needle)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && j++ < needle_len)
				if (j == needle_len)
					return (((char *)haystack) + i);
		}
	return (NULL);
}
