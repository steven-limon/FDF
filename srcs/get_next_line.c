/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:56:17 by slimon            #+#    #+#             */
/*   Updated: 2019/08/26 23:14:47 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** o Write a function that returns a line read from a file descriptor.
**
** o What we call a “line” is a succession of characters that end with
**  ’\n’ (ascii code 0x0a) or with End Of File (EOF).
**
** o The first parameter is the file descriptor that will be used to read.
**
** o The second parameter is the address of a pointer to a character
**	 that will be used to save the line read from the file descriptor.
**
** o The return value can be 1, 0 or -1 depending on whether a line
**   has been read, when the reading has been completed, or if an
**   error has happened respectively.
**
** o Your function get_next_line must return its result without ’\n’.
**
** o Calling your function get_next_line in a loop will then allow you
**   to read the text available on a file descriptor one line at a
**   time until the end of the text, no matter the size of either the
**   text or one of its lines.
**
** o Make sure that your function behaves well when it reads from a
**   file, from the standard output, from a redirection etc.
**
** o In you header file get_next_line.h you must have at least the
**   prototype of the function get_next_line and a macro that allows
**   to choose the size of the reading
**
** o We consider that get_nexta_line has an undefined behavior if,
**   between two calls, the same file descriptor designs two distinct
**   files although the reading from the first file was not completed.
**
** o We consider also that a call to lseek(2) will never take place
**   between two calls of the function get_next_line on the same file
**   descriptor.
**
** o Finally we consider that get_next_line has an undefined behavior
**   when reading from a binary file. However, if you wish, you can
**   make this behavior coherent.
*/

#include <libft.h>
#include "get_next_line.h"

static int	ft_realloc(char **mem, int mem_size, int n)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(sizeof(char) * (n + mem_size))))
		return (-1);
	if (mem_size != 0)
		ft_strcpy(tmp, *mem);
	ft_memdel((void **)mem);
	*mem = tmp;
	return (1);
}

static int	ft_strgrow(char **s, int n)
{
	int s_len;

	if (*s == NULL)
		s_len = 0;
	else
		s_len = ft_strlen(*s);
	if (!(ft_realloc(s, s_len, n + 1)))
		return (-1);
	else
		return (1);
}

static int	return_line(char **buff_fd, char **line)
{
	int		end;
	char	*tmp;
	char	*b;

	end = 0;
	tmp = 0;
	b = *buff_fd;
	while (b[end] != '\0' && b[end] != '\n')
		end++;
	*line = ft_strsub(b, 0, end);
	if (b[end] == '\n')
		tmp = ft_strsub(b, end + 1, ft_strlen(b) - end - 1);
	ft_memdel((void **)buff_fd);
	*buff_fd = tmp;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*buff[MAX_FILES];
	int				length;
	int				bytes_read;

	if (fd < 0 || fd >= MAX_FILES || line == NULL ||
		!ft_strgrow(&buff[fd], BUFF_SIZE))
		return (-1);
	length = ft_strlen(buff[fd]);
	while ((bytes_read = read(fd, &buff[fd][length], BUFF_SIZE)) > 0)
	{
		if (ft_strchr(buff[fd], '\n'))
			break ;
		else if (!ft_strgrow(&buff[fd], BUFF_SIZE))
			return (-1);
		length += BUFF_SIZE;
	}
	if (bytes_read == 0 && (buff[fd][0] == '\0' || buff[fd] == NULL))
		return (0);
	else if (bytes_read == -1 || !return_line(&buff[fd], line))
		return (-1);
	else
		return (1);
}
