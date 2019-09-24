/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:37:16 by slimon            #+#    #+#             */
/*   Updated: 2019/05/27 20:35:04 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description: Allocates (with malloc(3)) and returns a “fresh”
** link. The variables content and content_size of the new link are
** initialized by copy of the parameters of the function. If the pa-
** rameter content is nul, the variable content is initialized to NULL
** and the variable content_size is initialized to 0 even if the
** parameter content_size isn’t. The variable next is initialized to
** NULL. If the allocation fails, the function returns NULL.
**
** Param. #1: The content to put in the new link.
** Param. #2: The size of the content of the new link.
**
** Return value: The new link.
**
** Libc functions: malloc(3), free(3)
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	else
	{
		new_lst->content = ft_zeromemalloc(content_size);
		if (new_lst->content == NULL)
		{
			free(new_lst);
			return (NULL);
		}
		ft_memcpy(new_lst->content, content, content_size);
		new_lst->content_size = content_size;
	}
	new_lst->next = NULL;
	return (new_lst);
}
