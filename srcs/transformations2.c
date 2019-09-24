/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 04:49:50 by slimon            #+#    #+#             */
/*   Updated: 2019/09/23 06:06:00 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <float.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

static void	ortho_helper2(t_fdf *fdf, t_frustum_params *f)
{
	t_wireframe model;

	model = fdf->model;
	mult_pos_and_matrix(&(f->min_world), &(f->min_camera), model->view_mat);
	mult_pos_and_matrix(&(f->max_world), &(f->max_camera), model->view_mat);
	f->max_x = MAX(fabs(f->min_camera.x), fabs(f->max_camera.x));
	f->max_y = MAX(fabs(f->min_camera.y), fabs(f->max_camera.y));
	f->max = MAX(f->max_x, f->max_y);
	f->r = f->max * WIDTH / (float)HEIGHT;
	f->t = f->max;
	f->l = -f->r;
	f->b = -f->t;
	f->n = 0.1;
	f->f = 100;
	ortho(f, model->proj_mat);
}

static void	ortho_helper(t_fdf *fdf, t_frustum_params *f, int i)
{
	t_vec3f				*vert_table;

	vert_table = fdf->model->vert_table;
	if (vert_table[i].x < f->min_world.x)
		f->min_world.x = vert_table[i].x;
	if (vert_table[i].y < f->min_world.y)
		f->min_world.y = vert_table[i].y;
	if (vert_table[i].z < f->min_world.z)
		f->min_world.z = vert_table[i].z;
	if (vert_table[i].x > f->max_world.x)
		f->max_world.x = vert_table[i].x;
	if (vert_table[i].y > f->max_world.y)
		f->max_world.y = vert_table[i].y;
	if (vert_table[i].z > f->max_world.z)
		f->max_world.z = vert_table[i].z;
}

void		set_ortho_mat(t_fdf *fdf)
{
	t_frustum_params	f;
	t_vec3f				*vert_table;
	int					num_verts;
	int					i;

	set_vec(&(f.max_world), FLT_MIN, FLT_MIN, FLT_MIN);
	set_vec(&(f.min_world), FLT_MAX, FLT_MAX, FLT_MAX);
	i = -1;
	num_verts = fdf->model->num_verts;
	while (++i < num_verts)
		ortho_helper(fdf, &f, i);
	ortho_helper2(fdf, &f);
}
