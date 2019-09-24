/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:52:12 by slimon            #+#    #+#             */
/*   Updated: 2019/05/20 18:49:00 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description:
** Allocates (with malloc(3)) and returns a “fresh” substring from the string
** given as argument. The substring begins at indexstart and is of size len.
** If start and len aren’t refer- ing to a valid substring, the behavior is
** undefined. If the allocation fails, the function returns NULL.
**
** Return:
** The substring.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;

	if (s == NULL)
		return (NULL);
	ns = ft_strnew(len);
	if (ns == NULL)
		return (NULL);
	ft_strncpy(ns, s + start, len);
	return (ns);
}
