/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:56:20 by slimon            #+#    #+#             */
/*   Updated: 2019/05/27 20:43:27 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description: Iterates the list lst and applies the function f to each link.
**
** Param. #1: A pointer to the first link of a list.
** Param. #2: The address of a function to apply to each link of a list.
**
** Return value: None.
**
** Libc functions: None.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst == NULL)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
