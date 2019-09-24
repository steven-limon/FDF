/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:22:22 by slimon            #+#    #+#             */
/*   Updated: 2019/05/26 22:08:30 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*ns;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	if ((ns = ft_strnew(size)) == NULL)
		return (NULL);
	while (s[i])
	{
		ns[i] = f(i, s[i]);
		i++;
	}
	return (ns);
}
