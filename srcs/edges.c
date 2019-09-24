/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:25:49 by slimon            #+#    #+#             */
/*   Updated: 2019/09/20 19:28:24 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void			add_edge_helper2(t_wireframe *model, int v1_index,
									int v2_index, t_edge_table *edge_table_cur)
{
	edge_table_cur->edge = malloc(sizeof(t_vec3f_pair));
	edge_table_cur->edge->v1_index = v1_index;
	edge_table_cur->edge->v2_index = v2_index;
	model->num_edges++;
}

static t_edge_table	*add_edge_helper(t_edge_table *edge_table_cur)
{
	edge_table_cur->next = malloc(sizeof(t_edge_table));
	edge_table_cur = edge_table_cur->next;
	edge_table_cur->next = NULL;
	return (edge_table_cur);
}

void				add_edge(t_add_edge_params *vars)
{
	static t_edge_table	*edge_table_cur = NULL;
	int					i;

	i = vars->i;
	if (vars->row != 0)
	{
		edge_table_cur = add_edge_helper(edge_table_cur);
		add_edge_helper2(vars->model, i, i - vars->num_cols, edge_table_cur);
	}
	if (vars->col - 1 >= 0)
	{
		if (edge_table_cur == NULL)
		{
			edge_table_cur = malloc(sizeof(t_edge_table));
			edge_table_cur->next = NULL;
			vars->model->edge_table_head = edge_table_cur;
		}
		else
			edge_table_cur = add_edge_helper(edge_table_cur);
		add_edge_helper2(vars->model, i, i - 1, edge_table_cur);
	}
}
