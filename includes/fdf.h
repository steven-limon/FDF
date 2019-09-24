/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:54:01 by slimon            #+#    #+#             */
/*   Updated: 2019/09/23 06:06:50 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include "mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include "keys_consts.h"

# define WIDTH 1024
# define HEIGHT 500
# define SCALE 2
# define DEFAULT_COLOR 0xFF0000

typedef struct				s_mlx
{
	void					*ctx;
	void					*win;
}							t_mlx;

typedef struct				s_point
{
	int						x;
	int						y;
}							t_point;

typedef struct				s_vec3f
{
	double					x;
	double					y;
	double					z;
	int						color;
}							t_vec3f;

typedef struct				s_mat44f
{
	float					m00;
	float					m01;
	float					m02;
	float					m03;
	float					m10;
	float					m11;
	float					m12;
	float					m13;
	float					m20;
	float					m21;
	float					m22;
	float					m23;
	float					m30;
	float					m31;
	float					m32;
	float					m33;
}							t_mat44f;

typedef struct				s_frustum_params
{
	float					b;
	float					t;
	float					l;
	float					r;
	float					n;
	float					f;
	float					fov;
	float					aspect_ratio;
	t_vec3f					min_world;
	t_vec3f					max_world;
	t_vec3f					min_camera;
	t_vec3f					max_camera;
	float					max_x;
	float					max_y;
	float					max;
}							t_frustum_params;

typedef struct				s_draw_line
{
	int						dx;
	int						dy;
	int						sx;
	int						sy;
	int						err;
	int						err2;
}							t_draw_line;

typedef struct				s_vec3f_pair
{
	int						v1_index;
	int						v2_index;
}							t_vec3f_pair;

typedef struct				s_vert_table_row
{
	int						*z_row;
	int						*color_row;
	struct s_vert_table_row	*next;
	struct s_vert_table_row	*prev;
}							t_vert_table_row;

typedef struct				s_edge_table
{
	t_vec3f_pair			*edge;
	struct s_edge_table		*next;
}							t_edge_table;

typedef struct				s_wireframe
{
	char					proj_type;
	int						num_rows;
	int						num_cols;
	float					x_scale;
	float					y_scale;
	float					z_scale;
	int						num_edges;
	int						num_verts;
	t_vec3f					*vert_table;
	t_vec3f					*proj_verts;
	t_vert_table_row		*vert_table_1st_row;
	t_edge_table			*edge_table_head;
	float					x_rot;
	float					y_rot;
	float					z_rot;
	t_vec3f					pos;
	t_mat44f				*model_transforms;
	t_mat44f				*model_mat;
	t_mat44f				*view_mat;
	t_mat44f				*proj_mat;
}							t_wireframe;

typedef struct				s_fdf
{
	t_wireframe				*model;
	t_mlx					*mlx;
	float					fov;
}							t_fdf;

typedef struct				s_add_edge_params
{
	t_wireframe				*model;
	int						num_cols;
	int						i;
	int						col;
	int						row;
}							t_add_edge_params;

typedef struct				s_ll_helper_vars
{
	char					*comma;
	char					*z_str;
	char					*color_str;
}							t_ll_helper_vars;

/*
** map.c
*/
void						load_map(t_wireframe *model, char *path);

/*
** map2.c
*/
void						read_into_linked_list(t_wireframe *model, int fd,
													char *line);

/*
** edges.c
*/
void						add_edge(t_add_edge_params *vars);

/*
** projection.c
*/
void						ortho(t_frustum_params *f, t_mat44f *m);
void						pers(t_frustum_params *f, t_mat44f *m);
void						proj_vertices(t_wireframe *model, t_mat44f *mat_mvp,
								int image_width_half, int image_height_half);

/*
** camera.c
*/
void						look_at(t_mat44f *m, t_vec3f *v);

/*
** matrix_transforms1.c
*/
void						make_translation_mat(t_mat44f *m, t_vec3f *v);
void						identity_mat(t_mat44f *m);
void						unif_scale_mat(t_mat44f *m, float s);
void						non_unif_scale_mat(t_mat44f *m, t_vec3f *v);

/*
** matrix_transforms2.c
*/
void						rot_x(t_mat44f *m, int deg_full);
void						rot_y(t_mat44f *m, int deg_full);
void						rot_z(t_mat44f *m, int deg_full);

/*
** vector1.c
*/
float						magnitude(t_vec3f *v);
t_vec3f						norm(t_vec3f *v);
t_vec3f						cross(t_vec3f *v1, t_vec3f *v2);
t_vec3f						add_vec(t_vec3f *v1, t_vec3f *v2);
t_vec3f						sub_vec(t_vec3f *v1, t_vec3f *v2);

/*
** vector2.c
*/
t_vec3f						dir_vec(t_vec3f *a, t_vec3f *b);
float						dot_vec(t_vec3f *v1, t_vec3f *v2);
void						set_vec(t_vec3f *v, float x, float y, float z);

/*
** matrix.c
*/
void						mult_pos_and_matrix(t_vec3f *in, t_vec3f *out,
												t_mat44f *m);
void						mat_mult(t_mat44f *m1, t_mat44f *m2, t_mat44f *res);
void						copy_mat(t_mat44f *m, t_mat44f *copy);

/*
** color.c
*/
int							ip_color(t_vec3f v1, t_vec3f v2, t_point delta,
										t_point p1);

/*
** draw.c
*/
void						draw(t_fdf *fdf);

/*
** hooks.c
*/
# define KEY_PRESS_EVENT 2
# define WINDOW_CLOSE_EVENT 17

void						fdf_hooks(t_fdf *fdf, t_mlx *mlx);

/*
** callbacks.c
*/
# define MLX_UTILS_H
# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define MOUSE_MOVE 6

int							key_press_cb(int keycode, void *param);
int							loop_cb(t_fdf *fdf);
int							exit_cb(t_fdf *fdf);

/*
** controls.c
*/
# define ROT_DEF 1.25
# define TR_DEF 5
# define ZOOM_DEF 3

void						rotate(int key, t_fdf *fdf);
void						translate(int key, t_fdf *fdf);
void						zoom(int key, t_fdf *fdf);
void						elevation(int key, t_fdf *fdf);

/*
** transformations.c
*/
void						set_model_transforms(t_wireframe *model);
void						set_model_mat(t_wireframe *model);
void						set_view_mat(t_wireframe *model);
void						set_proj_mat(t_fdf *fdf);
void						set_ortho_mat(t_fdf *fdf);

/*
** transformations*.c
*/
void						set_ortho_mat(t_fdf *fdf);

#endif
