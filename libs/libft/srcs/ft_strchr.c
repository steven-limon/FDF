/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:53:25 by slimon            #+#    #+#             */
/*   Updated: 2019/05/26 22:09:42 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*sp;

	sp = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (sp + i);
		i++;
	}
	if ((char)c == '\0')
		return (sp + i);
	return (NULL);
}
