/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:23:10 by slimon            #+#    #+#             */
/*   Updated: 2019/05/28 14:41:04 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	t_byte			*dst_bp;
	const t_byte	*src_bp;

	i = 0;
	dst_bp = (t_byte *)dst;
	src_bp = (const t_byte *)src;
	while (i < n)
	{
		dst_bp[i] = src_bp[i];
		if (src_bp[i] == (t_byte)c)
			return (dst_bp + i + 1);
		i++;
	}
	return (NULL);
}
