/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:57:01 by slimon            #+#    #+#             */
/*   Updated: 2019/05/26 22:28:34 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*ns;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	ns = ft_strnew(size);
	if (ns == NULL)
		return (NULL);
	while (s[i])
	{
		ns[i] = f(s[i]);
		i++;
	}
	return (ns);
}
