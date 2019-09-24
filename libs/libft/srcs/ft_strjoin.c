/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:05:56 by slimon            #+#    #+#             */
/*   Updated: 2019/05/26 22:20:55 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description:
** Allocates (with malloc(3)) and returns a “fresh” string end- ing with ’\0’,
** result of the concatenation of s1 and s2. If the allocation fails the
** function returns NULL.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ns;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ns = ft_strnew(ft_strlen(s1) - 1 + ft_strlen(s2));
	if (ns == NULL)
		return (NULL);
	ft_strcpy(ns, s1);
	ft_strcpy(ns + ft_strlen(s1), s2);
	return (ns);
}
