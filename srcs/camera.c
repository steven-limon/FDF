/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:42:28 by slimon            #+#    #+#             */
/*   Updated: 2019/09/20 19:41:05 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	look_at_helper(t_mat44f *m, t_vec3f camera_dir, t_vec3f *cam_pos)
{
	m->m20 = camera_dir.x;
	m->m21 = camera_dir.y;
	m->m22 = camera_dir.z;
	m->m23 = -(camera_dir.x * cam_pos->x) - (camera_dir.y * cam_pos->y) -
					(camera_dir.z * cam_pos->z);
	m->m30 = 0;
	m->m31 = 0;
	m->m32 = 0;
	m->m33 = 1;
}

void		look_at(t_mat44f *m, t_vec3f *cam_pos)
{
	t_vec3f up;
	t_vec3f camera_right;
	t_vec3f tmp;
	t_vec3f camera_dir;

	tmp = sub_vec(cam_pos, &(t_vec3f){0, 0, 0, 0});
	camera_dir = norm(&tmp);
	tmp = cross(&(t_vec3f){0, 1, 0, 0}, &camera_dir);
	camera_right = norm(&tmp);
	up = cross(&camera_dir, &camera_right);
	m->m00 = camera_right.x;
	m->m01 = camera_right.y;
	m->m02 = camera_right.z;
	m->m03 = -(camera_right.x * cam_pos->x) - (camera_right.y * cam_pos->y) -
					(camera_right.z * cam_pos->z);
	m->m10 = up.x;
	m->m11 = up.y;
	m->m12 = up.z;
	m->m13 = -(up.x * cam_pos->x) - (up.y * cam_pos->y) - (up.z * cam_pos->z);
	look_at_helper(m, camera_dir, cam_pos);
}
