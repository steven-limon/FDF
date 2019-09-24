/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:35:29 by slimon            #+#    #+#             */
/*   Updated: 2019/09/20 18:58:42 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t needle_len;

	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (haystack[++i] && needle_len <= len--)
		if (haystack[i] == *needle)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && j++ < needle_len)
				if (j == needle_len)
					return (((char *)haystack) + i);
		}
	return (NULL);
}
