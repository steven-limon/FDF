/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:02:56 by slimon            #+#    #+#             */
/*   Updated: 2019/05/26 22:27:59 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			words++;
			if (!(s = ft_strchr(s, c)))
				return (words);
		}
	}
	return (words);
}
