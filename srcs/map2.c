/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:06:30 by slimon            #+#    #+#             */
/*   Updated: 2019/09/20 19:46:44 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	count_strs(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

static void	check_bad_file(char **map_line)
{
	if (map_line[0] == NULL)
	{
		ft_putstr("No data found.\n");
		exit(0);
	}
}

static void	handle_bad_file(int last_gnl, int gnl_err)
{
	if (last_gnl != 1 || gnl_err == -1)
	{
		ft_putstr("No data found.\n");
		exit(0);
	}
}

static void	read_ll_helper(t_wireframe *model, char **map_line, int row,
										t_vert_table_row *vert_table_cur_row)
{
	t_ll_helper_vars	v;
	int					col;

	vert_table_cur_row->z_row = malloc(sizeof(int) * model->num_cols);
	vert_table_cur_row->color_row = malloc(sizeof(int) * model->num_cols);
	col = 0;
	while (col < model->num_cols)
	{
		vert_table_cur_row->z_row[col] = ft_atoi(map_line[col]);
		vert_table_cur_row->color_row[col] = DEFAULT_COLOR;
		if ((v.comma = ft_strchr(map_line[col], ',')) != NULL)
		{
			v.z_str = ft_strsub(map_line[col], 0, v.comma - map_line[col]);
			v.color_str = ft_strsub(v.comma + 3, 0, ft_strlen(v.comma) - 3);
			vert_table_cur_row->z_row[col] = ft_atoi(v.z_str);
			vert_table_cur_row->color_row[col] = ft_atoi_base(v.color_str, 16);
			free(v.z_str);
			free(v.color_str);
		}
		add_edge(&(t_add_edge_params){model, model->num_cols, model->num_verts,
					col, row});
		col++;
		model->num_verts++;
	}
}

void		read_into_linked_list(t_wireframe *model, int fd, char *line)
{
	char				**map_line;
	int					gnl_err;
	t_vert_table_row	*vert_table_cur_row;
	static int			last_gnl = 0;

	vert_table_cur_row = malloc(sizeof(t_vert_table_row));
	model->vert_table_1st_row = vert_table_cur_row;
	vert_table_cur_row->next = NULL;
	while ((gnl_err = get_next_line(fd, &line)) > 0)
	{
		map_line = ft_strsplit(line, ' ');
		check_bad_file(map_line);
		if (model->num_cols == 0)
			model->num_cols = count_strs(map_line);
		read_ll_helper(model, map_line, model->num_rows, vert_table_cur_row);
		vert_table_cur_row->next = malloc(sizeof(t_vert_table_row));
		vert_table_cur_row->next->prev = vert_table_cur_row;
		vert_table_cur_row = vert_table_cur_row->next;
		vert_table_cur_row->next = NULL;
		model->num_rows++;
		free(map_line);
		free(line);
		last_gnl = gnl_err;
	}
	handle_bad_file(last_gnl, gnl_err);
}
