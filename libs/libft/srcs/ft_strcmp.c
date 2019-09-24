/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:59:56 by slimon            #+#    #+#             */
/*   Updated: 2019/05/28 14:40:47 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	const t_byte	*uc_s1;
	const t_byte	*uc_s2;

	i = 0;
	uc_s1 = (const t_byte *)s1;
	uc_s2 = (const t_byte *)s2;
	while (uc_s1[i] && uc_s2[i])
	{
		if (uc_s1[i] != uc_s2[i])
			break ;
		i++;
	}
	return (uc_s1[i] - uc_s2[i]);
}
