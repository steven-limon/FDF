/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 03:22:59 by slimon            #+#    #+#             */
/*   Updated: 2019/09/14 23:02:10 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define SQR(x) ((x) * (x))

float	magnitude(t_vec3f *v)
{
	return (sqrt(SQR(v->x) + SQR(v->y) + SQR(v->z)));
}

t_vec3f	norm(t_vec3f *v)
{
	float	len;
	t_vec3f	n;

	len = magnitude(v);
	n.x = v->x / len;
	n.y = v->y / len;
	n.z = v->z / len;
	return (n);
}

t_vec3f	cross(t_vec3f *v1, t_vec3f *v2)
{
	t_vec3f r;

	r.x = v1->y * v2->z - v1->z * v2->y;
	r.y = v1->z * v2->x - v1->z * v2->z;
	r.z = v1->x * v2->y - v1->z * v2->x;
	return (r);
}

t_vec3f	sub_vec(t_vec3f *v1, t_vec3f *v2)
{
	t_vec3f r;

	r.x = v1->x - v2->x;
	r.y = v1->y - v2->y;
	r.z = v1->z - v2->z;
	return (r);
}

t_vec3f	add_vec(t_vec3f *v1, t_vec3f *v2)
{
	t_vec3f r;

	r.x = v1->x + v2->x;
	r.y = v1->y + v2->y;
	r.z = v1->z + v2->z;
	return (r);
}
