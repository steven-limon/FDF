/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:22:36 by slimon            #+#    #+#             */
/*   Updated: 2019/05/25 15:31:54 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prototype
** Description: Outputs the char c to the file descriptor fd.
** Param. #1: The character to output.
** Param. #2: The file descriptor.
** Return value
** None.
** Libc functions
** write(2).
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
