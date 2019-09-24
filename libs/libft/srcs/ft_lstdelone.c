/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:41:36 by slimon            #+#    #+#             */
/*   Updated: 2019/05/27 20:01:52 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description: Takes as a parameter a link’s pointer address and
** frees the memory of the link’s content using the function del given
** as a parameter, then frees the link’s memory using free(3). The
** memory of next must not be freed under any circumstance. Finally,
** the pointer to the link that was just freed must be set to NULL
** (quite similar to the function ft_memdel in the mandatory part).
**
** Param. #1: The content to put in the new link.
** Param. #2: The size of the content of the new link.
**
** Return value: The new link.
**
** Libc functions: malloc(3), free(3)
*/

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst == NULL || *alst == NULL)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
