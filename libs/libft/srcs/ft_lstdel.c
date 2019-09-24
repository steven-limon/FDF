/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:49:11 by slimon            #+#    #+#             */
/*   Updated: 2019/05/28 14:42:38 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description: Takes as a parameter the address of a pointer to a link
** and frees the memory of this link and every successors of that link
** using the functions del and free(3). Finally the pointer to the
** link that was just freed must be set to NULL (quite similar to the
** function ft_memdel from the mandatory part).
**
** Param. #1: The address of a pointer to the first link of a list
** that needs to be freed.
**
** Return value: None.
**
** Libc functions: free(3)
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *head;

	if (alst == NULL || *alst == NULL)
		return ;
	head = *alst;
	while (*alst)
	{
		next = *alst;
		*alst = (*alst)->next;
		del(next->content, next->content_size);
		free(next);
	}
	head = NULL;
}
