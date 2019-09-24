/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 03:35:13 by slimon            #+#    #+#             */
/*   Updated: 2019/09/23 05:50:42 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(int key, t_fdf *fdf)
{
	t_wireframe	*model;

	model = fdf->model;
	if (key == KP_4)
		model->z_rot += ROT_DEF;
	else if (key == KP_6)
		model->z_rot -= ROT_DEF;
	else if (key == KP_8)
		model->x_rot += ROT_DEF;
	else if (key == KP_2)
		model->x_rot -= ROT_DEF;
	else if (key == KP_7)
		model->y_rot += ROT_DEF;
	else if (key == KP_9)
		model->y_rot -= ROT_DEF;
}

void	translate(int key, t_fdf *fdf)
{
	t_wireframe	*model;

	model = fdf->model;
	if (key == KEY_D)
		model->pos.x += TR_DEF;
	else if (key == KEY_A)
		model->pos.x -= TR_DEF;
	else if (key == KEY_S)
		model->pos.y += TR_DEF;
	else if (key == KEY_W)
		model->pos.y -= TR_DEF;
	else if (key == KEY_Q)
		model->pos.z += TR_DEF;
	else if (key == KEY_E)
		model->pos.z -= TR_DEF;
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == KP_PLUS && fdf->fov > 40)
		fdf->fov -= ZOOM_DEF;
	else if (key == KP_MINUS && fdf->fov < 150)
		fdf->fov += ZOOM_DEF;
}

void	elevation(int key, t_fdf *fdf)
{
	t_wireframe	*model;

	model = fdf->model;
	if (key == KEY_DOWN)
		model->z_scale -= 0.15;
	else if (key == KEY_UP)
		model->z_scale += 0.15;
}
