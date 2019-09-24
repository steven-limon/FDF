/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 03:30:28 by slimon            #+#    #+#             */
/*   Updated: 2019/09/14 22:57:50 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			mult_pos_and_matrix(t_vec3f *in, t_vec3f *out, t_mat44f *m)
{
	float w;

	out->x = in->x * m->m00 + in->y * m->m10 + in->z * m->m20 + m->m30;
	out->y = in->x * m->m01 + in->y * m->m11 + in->z * m->m21 + m->m31;
	out->z = in->x * m->m02 + in->y * m->m12 + in->z * m->m22 + m->m32;
	w = in->x * m->m03 + in->y * m->m13 + in->z * m->m23 + m->m33;
	if (w != 1)
	{
		out->x /= w;
		out->y /= w;
		out->z /= w;
	}
}

void			copy_mat(t_mat44f *copy, t_mat44f *m)
{
	copy->m00 = m->m00;
	copy->m01 = m->m01;
	copy->m02 = m->m02;
	copy->m03 = m->m03;
	copy->m10 = m->m10;
	copy->m11 = m->m11;
	copy->m12 = m->m12;
	copy->m13 = m->m13;
	copy->m20 = m->m20;
	copy->m21 = m->m21;
	copy->m22 = m->m22;
	copy->m23 = m->m23;
	copy->m30 = m->m30;
	copy->m31 = m->m31;
	copy->m32 = m->m32;
	copy->m33 = m->m33;
}

static void		mat_mult2(t_mat44f *m2, t_mat44f *m1, t_mat44f *res)
{
	res->m20 = m1->m20 * m2->m00 + m1->m21 * m2->m10 + m1->m22 * m2->m20 +
		m1->m23 * m2->m30;
	res->m21 = m1->m20 * m2->m01 + m1->m21 * m2->m11 + m1->m22 * m2->m21 +
		m1->m23 * m2->m31;
	res->m22 = m1->m20 * m2->m02 + m1->m21 * m2->m12 + m1->m22 * m2->m22 +
		m1->m23 * m2->m32;
	res->m23 = m1->m20 * m2->m03 + m1->m21 * m2->m13 + m1->m22 * m2->m23 +
		m1->m23 * m2->m33;
	res->m30 = m1->m30 * m2->m00 + m1->m31 * m2->m10 + m1->m32 * m2->m20 +
		m1->m33 * m2->m30;
	res->m31 = m1->m30 * m2->m01 + m1->m31 * m2->m11 + m1->m32 * m2->m21 +
		m1->m33 * m2->m31;
	res->m32 = m1->m30 * m2->m02 + m1->m31 * m2->m12 + m1->m32 * m2->m22 +
		m1->m33 * m2->m32;
	res->m33 = m1->m30 * m2->m03 + m1->m31 * m2->m13 + m1->m32 * m2->m23 +
		m1->m33 * m2->m33;
}

void			mat_mult(t_mat44f *m2, t_mat44f *m1, t_mat44f *res)
{
	res->m00 = m1->m00 * m2->m00 + m1->m01 * m2->m10 + m1->m02 * m2->m20 +
		m1->m03 * m2->m30;
	res->m01 = m1->m00 * m2->m01 + m1->m01 * m2->m11 + m1->m02 * m2->m21 +
		m1->m03 * m2->m31;
	res->m02 = m1->m00 * m2->m02 + m1->m01 * m2->m12 + m1->m02 * m2->m22 +
		m1->m03 * m2->m32;
	res->m03 = m1->m00 * m2->m03 + m1->m01 * m2->m13 + m1->m02 * m2->m23 +
		m1->m03 * m2->m33;
	res->m10 = m1->m10 * m2->m00 + m1->m11 * m2->m10 + m1->m12 * m2->m20 +
		m1->m13 * m2->m30;
	res->m11 = m1->m10 * m2->m01 + m1->m11 * m2->m11 + m1->m12 * m2->m21 +
		m1->m13 * m2->m31;
	res->m12 = m1->m10 * m2->m02 + m1->m11 * m2->m12 + m1->m12 * m2->m22 +
		m1->m13 * m2->m32;
	res->m13 = m1->m10 * m2->m03 + m1->m11 * m2->m13 + m1->m12 * m2->m23 +
		m1->m13 * m2->m33;
	mat_mult2(m2, m1, res);
}
