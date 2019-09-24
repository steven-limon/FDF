/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:35:57 by slimon            #+#    #+#             */
/*   Updated: 2019/09/23 05:46:24 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <float.h>

void	set_model_transforms(t_wireframe *model)
{
	t_mat44f			m_rot_x;
	t_mat44f			m_rot_y;
	t_mat44f			m_rot_z;
	t_mat44f			tmp_mat;
	t_mat44f			rot_mat;

	rot_x(&m_rot_x, model->x_rot);
	rot_y(&m_rot_y, model->y_rot);
	rot_z(&m_rot_z, model->z_rot);
	mat_mult(&m_rot_x, &m_rot_y, &tmp_mat);
	mat_mult(&tmp_mat, &m_rot_z, &rot_mat);
	make_translation_mat(&tmp_mat,
						&(t_vec3f){-model->num_cols * model->x_scale * 0.5,
								-model->num_rows * model->y_scale * 0.5, 0, 0});
	mat_mult(&rot_mat, &tmp_mat, &m_rot_x);
	non_unif_scale_mat(&tmp_mat, &(t_vec3f){model->x_scale, model->y_scale,
				model->z_scale, 0});
	mat_mult(&m_rot_x, &tmp_mat, model->model_transforms);
}

void	set_model_mat(t_wireframe *model)
{
	make_translation_mat(model->model_mat,
						&(t_vec3f){model->pos.x, model->pos.y,
									model->pos.z, 0});
}

void	set_view_mat(t_wireframe *model)
{
	make_translation_mat(model->view_mat, &(t_vec3f){0, 0, -40, 0});
}

void	set_proj_mat(t_fdf *fdf)
{
	t_frustum_params	f;
	float				scale;

	f.aspect_ratio = WIDTH / (float)HEIGHT;
	f.n = 0.1;
	f.f = 1000;
	f.fov = fdf->fov;
	scale = tan(f.fov * 0.5 * M_PI / 180) * f.n;
	f.r = f.aspect_ratio * scale;
	f.l = -f.r;
	f.t = scale;
	f.b = -f.t;
	pers(&f, fdf->model->proj_mat);
}
