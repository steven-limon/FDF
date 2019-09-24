/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:22:58 by slimon            #+#    #+#             */
/*   Updated: 2019/09/23 05:49:43 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_model(t_wireframe *model, char proj_type)
{
	if (proj_type == 'p')
		model->proj_type = 'p';
	else
		model->proj_type = 'o';
	model->model_transforms = malloc(sizeof(t_mat44f));
	model->model_mat = malloc(sizeof(t_mat44f));
	model->view_mat = malloc(sizeof(t_mat44f));
	model->proj_mat = malloc(sizeof(t_mat44f));
	model->x_rot = -150;
	model->y_rot = -150;
	model->z_rot = 180;
	model->pos.x = 0;
	model->pos.y = 0;
	model->pos.z = 0;
	model->x_scale = SCALE;
	model->y_scale = SCALE;
	model->z_scale = 1;
	model->num_verts = 0;
	model->num_rows = 0;
	model->num_cols = 0;
	model->num_edges = 0;
}

int			main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_fdf		fdf;
	t_wireframe	model;

	if (argc != 3)
	{
		ft_putstr("Usage : ./fdf [map.fdf]  [p | o]\n");
		return (0);
	}
	fdf.mlx = &mlx;
	fdf.model = &model;
	fdf.fov = 90;
	if (argv[2][0] == 'o')
		setup_model(&model, 'o');
	if (argv[2][0] == 'p')
		setup_model(&model, 'p');
	load_map(&model, argv[1]);
	model.proj_verts = malloc(sizeof(t_vec3f) * model.num_verts);
	mlx.ctx = mlx_init();
	mlx.win = mlx_new_window(mlx.ctx, WIDTH, HEIGHT, "fdf");
	fdf_hooks(&fdf, &mlx);
	mlx_loop(mlx.ctx);
	return (0);
}
