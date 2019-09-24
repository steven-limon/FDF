/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:57:50 by slimon            #+#    #+#             */
/*   Updated: 2019/05/26 22:07:23 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description:
** Allocates (with malloc(3)) and returns a copy of the string given as argument
** without whitespaces at the beginning or at the end of the string. Will be
** considered as whitespaces the following characters ’ ’, ’\n’ and ’\t’.
** If s has no whites- paces at the beginning or at the end, the function
** returns a copy of s. If the allocation fails the function returns NULL.
** Param 1: The string to be trimed.
** Return: The “fresh” trimmed string or a copy of s.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start_i;
	int		end_i;
	char	*ns;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start_i = i;
	i = ft_strlen(s);
	while ((s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t') && i > 0)
		i--;
	end_i = (i == 0) ? ft_strlen(s) : i;
	if (!(ns = ft_strnew(end_i - start_i)))
		return (NULL);
	i = -1;
	while ((end_i - start_i) > ++i)
		ns[i] = s[start_i + i];
	ns[i] = '\0';
	return (ns);
}
