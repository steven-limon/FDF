/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 01:17:57 by slimon            #+#    #+#             */
/*   Updated: 2019/09/23 05:57:57 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Define callbacks.
*/

#include "fdf.h"

int		key_press_cb(int keycode, void *param)
{
	if (keycode == KP_4 || keycode == KP_8
		|| keycode == KP_6 || keycode == KP_2
		|| keycode == KP_7 || keycode == KP_9)
		rotate(keycode, param);
	else if (keycode == KEY_W || keycode == KEY_A
			|| keycode == KEY_S || keycode == KEY_D
			|| keycode == KEY_Q || keycode == KEY_E)
		translate(keycode, param);
	else if (keycode == KP_PLUS || keycode == KP_MINUS)
		zoom(keycode, param);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT
			|| keycode == KEY_UP || keycode == KEY_DOWN)
		elevation(keycode, param);
	else if (keycode == MAIN_PAD_ESC)
		exit(0);
	return (0);
}

int		loop_cb(t_fdf *fdf)
{
	draw(fdf);
	return (0);
}

int		exit_cb(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx->ctx, fdf->mlx->win);
	exit(0);
}
