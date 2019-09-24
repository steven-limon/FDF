/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 03:19:47 by slimon            #+#    #+#             */
/*   Updated: 2019/09/23 05:59:22 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3f	dir_vec(t_vec3f *a, t_vec3f *b)
{
	return (sub_vec(b, a));
}

float	dot_vec(t_vec3f *v1, t_vec3f *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->x * v2->y);
}

void	set_vec(t_vec3f *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}
