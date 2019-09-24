/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:21:52 by slimon            #+#    #+#             */
/*   Updated: 2019/05/25 15:07:29 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ucp;
	const char	*src_ucp;

	dst_ucp = dst;
	src_ucp = src;
	if (src_ucp < dst_ucp && dst_ucp < src_ucp + len)
	{
		dst_ucp += len;
		src_ucp += len;
		while (len-- > 0)
			*--dst_ucp = *--src_ucp;
	}
	else
		while (len-- > 0)
			*dst_ucp++ = *src_ucp++;
	return (dst);
}
