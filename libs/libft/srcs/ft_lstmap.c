/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:58:40 by slimon            #+#    #+#             */
/*   Updated: 2019/05/28 14:15:09 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description: Iterates a list lst and applies the function f to each
** link to create a “fresh” list (using malloc(3)) resulting from the
** successive applications of f. If the allocation fails, the
** function returns NULL.
**
** Param. #1: A pointer’s to the first link of a list.
** Param. #2: The address of a function to apply to each link of a list.
**
** Return value: The new list.
**
** Libc functions: malloc(3), free(3).
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *p_lst;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_lst = f(lst);
	p_lst = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		p_lst->next = f(lst);
		p_lst = p_lst->next;
	}
	return (new_lst);
}
