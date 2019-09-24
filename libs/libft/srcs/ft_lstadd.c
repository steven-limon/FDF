/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:53:17 by slimon            #+#    #+#             */
/*   Updated: 2019/05/28 14:14:50 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description: Adds the element new at the beginning of the list.
**
** Param. #1: The address of a pointer to the first link of a list.
** Param. #2: The link to add at the beginning of the list.
** Return value: None.
** Libc functions: None.
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
