/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeromemalloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:28:27 by slimon            #+#    #+#             */
/*   Updated: 2019/05/27 20:39:22 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_zeromemalloc(size_t size)
{
	size_t	i;
	t_byte	*mem;

	i = 0;
	mem = (t_byte *)malloc(sizeof(t_byte) * size);
	if (mem == NULL)
		return (NULL);
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
