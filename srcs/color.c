/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 03:31:56 by slimon            #+#    #+#             */
/*   Updated: 2019/09/15 01:10:19 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	percent(int start, int end, int cur)
{
	float place;
	float dist;

	place = cur - start;
	dist = end - start;
	if (dist == 0)
		return (1);
	else
		return (place / dist);
}

static int		interpolate_color(int start_color, int end_color, float percent)
{
	return ((1 - percent) * start_color + percent * end_color);
}

int				ip_color(t_vec3f v1, t_vec3f v2, t_point delta, t_point cur)
{
	float	percentage;
	int		red;
	int		green;
	int		blue;

	if (v1.color == v2.color)
		return (v1.color);
	if (delta.x > delta.y)
		percentage = percent(v1.x, v2.x, cur.x);
	else
		percentage = percent(v1.y, v2.y, cur.y);
	red = interpolate_color((v1.color >> 16) & 0xFF, (v2.color >> 16) & 0xFF,
							percentage);
	green = interpolate_color((v1.color >> 8) & 0xFF, (v2.color >> 8) & 0xFF,
								percentage);
	blue = interpolate_color(v1.color & 0xFF, v2.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
