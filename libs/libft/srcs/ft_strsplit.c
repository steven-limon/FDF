/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:57:15 by slimon            #+#    #+#             */
/*   Updated: 2019/05/26 22:27:44 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description: Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) ob- tained by
** spliting s using the character c as a delimiter. If the allocation fails the
** function returns NULL.
**
** Example : ft_strsplit("*hello*fellow***students*", ’*’) re- turns the array
** ["hello", "fellow", "students"].
**
** Param. #1 The string to split.
** Param. #2 The delimiter character.
**
** Return: value The array of “fresh” strings result of the split.
**
** Libc functions: malloc(3), free(3)
*/

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	size_t	words;
	char	**aos;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = ft_wordcount(s, c);
	aos = (char **)malloc(sizeof(char *) * (words + 1));
	if (aos == NULL)
		return (NULL);
	aos[words] = NULL;
	while (words > 0)
	{
		s = s + ft_skip_c(s, c);
		aos[i] = ft_strsub(s, 0, ft_skip_until_c(s, c));
		s = ft_strchr(s, c);
		i++;
		words--;
	}
	return (aos);
}
