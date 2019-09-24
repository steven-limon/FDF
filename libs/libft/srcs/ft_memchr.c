/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:15:05 by slimon            #+#    #+#             */
/*   Updated: 2019/05/25 15:27:17 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	t_byte	uc;

	i = 0;
	uc = (t_byte)c;
	while (i < n)
	{
		if (((t_byte *)s)[i] == uc)
			return ((t_byte *)s + i);
		i++;
	}
	return (NULL);
}
