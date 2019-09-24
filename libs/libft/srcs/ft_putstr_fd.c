/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:16:12 by slimon            #+#    #+#             */
/*   Updated: 2019/05/27 20:46:14 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description: Outputs the string s to the file descriptor fd.
** Param. #1: The string to output.
** Param. #2: The file descriptor.
** Return value: None.
** Libc functions: write(2).
*/

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
