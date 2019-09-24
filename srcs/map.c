/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:56:10 by slimon            #+#    #+#             */
/*   Updated: 2019/09/15 22:19:52 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	cleanup_linked_list(t_wireframe *model)
{
	t_vert_table_row *head;

	head = model->vert_table_1st_row;
	while (head)
	{
		free(head->z_row);
		free(head->color_row);
		head = head->next;
	}
}

static void	read_into_vertex_arr(t_wireframe *model)
{
	t_vert_table_row	*vert_table_cur_row;
	int					v;
	int					i;
	int					j;

	v = 0;
	j = -1;
	model->vert_table = malloc(sizeof(t_vec3f) * model->num_verts);
	vert_table_cur_row = model->vert_table_1st_row;
	while (++j < model->num_rows)
	{
		i = -1;
		while (++i < model->num_cols)
		{
			model->vert_table[v].x = i * model->x_scale;
			model->vert_table[v].y = j * model->y_scale;
			model->vert_table[v].z =
				vert_table_cur_row->z_row[i] * model->z_scale;
			model->vert_table[v].color = vert_table_cur_row->color_row[i];
			v++;
		}
		vert_table_cur_row = vert_table_cur_row->next;
	}
	cleanup_linked_list(model);
}

void		load_map(t_wireframe *model, char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("No file ");
		ft_putstr(path);
		ft_putchar('\n');
		exit(0);
	}
	read_into_linked_list(model, fd, 0);
	read_into_vertex_arr(model);
	close(fd);
}
