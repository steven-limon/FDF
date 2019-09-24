/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:24:25 by slimon            #+#    #+#             */
/*   Updated: 2019/09/23 05:56:52 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_draw_line(t_draw_line *v, t_vec3f v1, t_vec3f v2,
								t_vec3f *start)
{
	v->dx = abs((int)v2.x - (int)v1.x);
	v->dy = abs((int)v2.y - (int)v1.y);
	v->sx = (int)v2.x > (int)v1.x ? 1 : -1;
	v->sy = (int)v2.y > (int)v1.y ? 1 : -1;
	v->err = (v->dx > v->dy ? v->dx : -v->dy) / 2;
	start->x = v1.x;
	start->y = v1.y;
	start->color = v1.color;
}

static void	draw_line(t_vec3f v1, t_vec3f v2, t_mlx *mlx)
{
	int			color;
	t_draw_line	v;
	t_vec3f		start;

	setup_draw_line(&v, v1, v2, &start);
	while (1)
	{
		color = ip_color(start, v2, (t_point){v.dx, v.dy},
						(t_point){(int)v1.x, (int)v1.y});
		mlx_pixel_put(mlx->ctx, mlx->win, (int)v1.x, (int)v1.y, color);
		if ((int)v1.x == (int)v2.x && (int)v1.y == (int)v2.y)
			break ;
		v.err2 = v.err;
		if (v.err2 > -v.dx)
		{
			v.err -= v.dy;
			v1.x += v.sx;
		}
		if (v.err2 < v.dy)
		{
			v.err += v.dx;
			v1.y += v.sy;
		}
	}
}

static void	draw_edges(t_wireframe *model, t_mlx *mlx)
{
	t_vec3f			v1;
	t_vec3f			v2;
	t_edge_table	*edge_table_cur;
	int				i;
	int				num_edges;

	edge_table_cur = model->edge_table_head;
	num_edges = model->num_edges;
	i = -1;
	while (++i < num_edges)
	{
		v1 = (model->proj_verts[edge_table_cur->edge->v1_index]);
		v2 = (model->proj_verts[edge_table_cur->edge->v2_index]);
		if (v1.x >= 0 && v1.x < WIDTH && v1.y >= 0 && v1.y < HEIGHT &&
			v2.x >= 0 && v2.x < WIDTH && v2.y >= 0 && v2.y < HEIGHT &&
			v1.z >= -1 && v1.z <= 1 && v2.z >= -1 && v2.z <= 1)
			draw_line(v1, v2, mlx);
		edge_table_cur = edge_table_cur->next;
	}
}

void		draw(t_fdf *fdf)
{
	t_mat44f	mat_mvp;
	t_mat44f	mat_tmp;
	t_mat44f	mat_tmp2;
	t_wireframe	*model;

	model = fdf->model;
	set_model_transforms(model);
	set_model_mat(model);
	set_view_mat(model);
	if (model->proj_type == 'p')
	{
		set_proj_mat(fdf);
		mat_mult(model->proj_mat, model->view_mat, &mat_tmp);
		mat_mult(&mat_tmp, model->model_mat, &mat_mvp);
		mat_mult(&mat_mvp, model->model_transforms, &mat_tmp);
	}
	else
	{
		set_ortho_mat(fdf);
		mat_mult(model->proj_mat, model->view_mat, &mat_tmp2);
		mat_mult(&mat_tmp2, model->model_transforms, &mat_tmp);
	}
	proj_vertices(model, &mat_tmp, WIDTH * 0.5, HEIGHT * 0.5);
	mlx_clear_window(fdf->mlx->ctx, fdf->mlx->win);
	draw_edges(model, fdf->mlx);
}
