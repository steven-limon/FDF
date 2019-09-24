/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 00:15:11 by slimon            #+#    #+#             */
/*   Updated: 2019/09/20 19:09:19 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Define hooks
*/

#include "fdf.h"

void	fdf_hooks(t_fdf *fdf, t_mlx *mlx)
{
	mlx_hook(mlx->win, KEY_PRESS_EVENT, 0, key_press_cb, fdf);
	mlx_expose_hook(mlx->win, loop_cb, fdf);
	mlx_hook(mlx->win, WINDOW_CLOSE_EVENT, 0, exit_cb, fdf);
	mlx_loop_hook(mlx->ctx, loop_cb, fdf);
}
