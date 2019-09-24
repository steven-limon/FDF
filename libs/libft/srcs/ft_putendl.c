/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:19:52 by slimon            #+#    #+#             */
/*   Updated: 2019/05/27 20:46:34 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description: Outputs the string s to the standard output followed by a ’\n’.
** Param #1 The string to output.
** Return: None
** Libc Funcs: write(2)
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s == NULL)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}
