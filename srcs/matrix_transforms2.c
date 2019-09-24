/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transforms2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:34:33 by slimon            #+#    #+#             */
/*   Updated: 2019/09/14 22:49:31 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(t_mat44f *m, int deg_full)
{
	int deg;

	if (deg_full >= 0)
		deg = deg_full % 360;
	else
		deg = -(abs(deg_full) % 360);
	m->m00 = 1;
	m->m01 = 0;
	m->m02 = 0;
	m->m03 = 0;
	m->m10 = 0;
	m->m11 = cos(deg * M_PI / 180);
	m->m12 = -sin(deg * M_PI / 180);
	m->m13 = 0;
	m->m20 = 0;
	m->m21 = sin(deg * M_PI / 180);
	m->m22 = cos(deg * M_PI / 180);
	m->m23 = 0;
	m->m30 = 0;
	m->m31 = 0;
	m->m32 = 0;
	m->m33 = 1;
}

void	rot_y(t_mat44f *m, int deg_full)
{
	int deg;

	if (deg_full >= 0)
		deg = deg_full % 360;
	else
		deg = -(abs(deg_full) % 360);
	m->m00 = cos(deg * M_PI / 180);
	m->m01 = 0;
	m->m02 = sin(deg * M_PI / 180);
	m->m03 = 0;
	m->m10 = 0;
	m->m11 = 1;
	m->m12 = 0;
	m->m13 = 0;
	m->m20 = -sin(deg * M_PI / 180);
	m->m21 = 0;
	m->m22 = cos(deg * M_PI / 180);
	m->m23 = 0;
	m->m30 = 0;
	m->m31 = 0;
	m->m32 = 0;
	m->m33 = 1;
}

void	rot_z(t_mat44f *m, int deg_full)
{
	int deg;

	if (deg_full >= 0)
		deg = deg_full % 360;
	else
		deg = -(abs(deg_full) % 360);
	m->m00 = cos(deg * M_PI / 180);
	m->m01 = -sin(deg * M_PI / 180);
	m->m02 = 0;
	m->m03 = 0;
	m->m10 = sin(deg * M_PI / 180);
	m->m11 = cos(deg * M_PI / 180);
	m->m12 = 0;
	m->m13 = 0;
	m->m20 = 0;
	m->m21 = 0;
	m->m22 = 1;
	m->m23 = 0;
	m->m30 = 0;
	m->m31 = 0;
	m->m32 = 0;
	m->m33 = 1;
}
