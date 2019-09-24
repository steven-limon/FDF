/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:25:10 by slimon            #+#    #+#             */
/*   Updated: 2019/05/28 14:41:20 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	const t_byte	*uc_s1;
	const t_byte	*uc_s2;

	i = 0;
	uc_s1 = (const t_byte *)s1;
	uc_s2 = (const t_byte *)s2;
	while ((uc_s1[i] || uc_s2[i]) && i < n)
	{
		if (uc_s1[i] != uc_s2[i])
			return (uc_s1[i] - uc_s2[i]);
		i++;
	}
	return (0);
}
