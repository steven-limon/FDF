/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:55:04 by slimon            #+#    #+#             */
/*   Updated: 2019/05/20 20:16:11 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t src_len;
	size_t dest_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	j = 0;
	while (dest[i] && i < dstsize)
		i++;
	while (src[j] && i + j < dstsize - 1 && dstsize > dest_len + 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (dstsize != 0 && dest_len <= dstsize)
		dest[i + j] = '\0';
	return (i + src_len);
}
