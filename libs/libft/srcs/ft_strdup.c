/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:22:52 by slimon            #+#    #+#             */
/*   Updated: 2019/05/25 15:17:42 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		count;
	int		i;
	char	*new_s;

	count = 0;
	i = 0;
	while (s1[count])
		count++;
	new_s = (char *)malloc(sizeof(char) * count + 1);
	if (new_s == 0)
		return (0);
	while (i < count)
	{
		new_s[i] = s1[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
