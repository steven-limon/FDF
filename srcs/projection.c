/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 02:54:27 by slimon            #+#    #+#             */
/*   Updated: 2019/09/23 05:55:54 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ortho(t_frustum_params *f, t_mat44f *m)
{
	m->m00 = 2 / (f->r - f->l);
	m->m01 = 0;
	m->m02 = 0;
	m->m03 = 0;
	m->m10 = 0;
	m->m11 = 2 / (f->t - f->b);
	m->m12 = 0;
	m->m13 = 0;
	m->m20 = 0;
	m->m21 = 0;
	m->m22 = -2 / (f->f - f->n);
	m->m23 = 0;
	m->m30 = -(f->r + f->l) / (f->r - f->l);
	m->m31 = -(f->t + f->b) / (f->t - f->b);
	m->m32 = -(f->f + f->n) / (f->f - f->n);
	m->m33 = 1;
}

void	pers(t_frustum_params *f, t_mat44f *m)
{
	m->m00 = 2 * f->n / (f->r - f->l);
	m->m01 = 0;
	m->m02 = 0;
	m->m03 = 0;
	m->m10 = 0;
	m->m11 = 2 * f->n / (f->t - f->b);
	m->m12 = 0;
	m->m13 = 0;
	m->m20 = (f->r + f->l) / (f->r - f->l);
	m->m21 = (f->t + f->b) / (f->t - f->b);
	m->m22 = -(f->f + f->n) / (f->f - f->n);
	m->m23 = -1;
	m->m30 = 0;
	m->m31 = 0;
	m->m32 = -2 * f->f * f->n / (f->f - f->n);
	m->m33 = 0;
}

void	proj_vertices(t_wireframe *model, t_mat44f *mat_mvp,
					int image_width_half, int image_height_half)
{
	t_vec3f		*vertices;
	t_vec3f		proj_vert;
	int			num_vertices;
	int			i;

	vertices = model->vert_table;
	num_vertices = model->num_verts;
	i = -1;
	while (++i < num_vertices)
	{
		mult_pos_and_matrix(&vertices[i], &proj_vert, mat_mvp);
		model->proj_verts[i].x = (proj_vert.x + 1) * image_width_half;
		model->proj_verts[i].y = (proj_vert.y + 1) * image_height_half;
		model->proj_verts[i].z = proj_vert.z;
		model->proj_verts[i].color = vertices[i].color;
	}
}
