/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_transform_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:33:39 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/18 18:18:00 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

float	get_scale_factor(t_map *map)
{
	float	scale_factor;
	float	scale_x;
	float	scale_y;

	scale_x = (float)WINDOW_WIDTH / (float)map->width;
	scale_y = (float)WINDOW_HEIGHT / (float)map->height;
	if (scale_x < scale_y)
		scale_factor = scale_x;
	else
		scale_factor = scale_y;
	if (scale_factor < 3)
		return (scale_factor);
	return (scale_factor / 1.2);
}

void	centralize(t_fdf *fdf, t_point *initial_point, t_point *end_point)
{
	initial_point->x += fdf->cam->x_offset;
	initial_point->y += fdf->cam->y_offset;
	end_point->x += fdf->cam->x_offset;
	end_point->y += fdf->cam->y_offset;
}

void	scale_map(t_fdf *fdf, t_point *initial_point, t_point *end_point)
{
	initial_point->x *= fdf->cam->scale;
	initial_point->y *= fdf->cam->scale;
	end_point->x *= fdf->cam->scale;
	end_point->y *= fdf->cam->scale;
}

void	isometric(t_fdf *fdf, t_point *initial_point, t_point *end_point)
{
	t_point	new_initial;
	t_point	new_end;

	new_initial.x = (initial_point->x - initial_point->y) * cos(COS_30);
	new_initial.y = (initial_point->x + initial_point->y) * sin(SEN_30) - \
		initial_point->z * fdf->cam->multi_factor;
	new_end.x = (end_point->x - end_point->y) * cos(COS_30);
	new_end.y = (end_point->x + end_point->y) * sin(SEN_30) - end_point->z \
		* fdf->cam->multi_factor;
	initial_point->x = new_initial.x;
	initial_point->y = new_initial.y;
	end_point->x = new_end.x;
	end_point->y = new_end.y;
}

void	oblique(t_fdf *fdf, t_point *initial_point, t_point *end_point)
{
	t_point	new_initial;
	t_point	new_end;
	float	scale;

	scale = 1.545;
	new_initial.x = (initial_point->x + 0.5 * \
		(initial_point->z * -fdf->cam->multi_factor)) * scale * cos(COS_30);
	new_initial.y = (initial_point->y + 0.5 * \
		(initial_point->z * -fdf->cam->multi_factor)) * scale * sin(SEN_30);
	new_end.x = (end_point->x + 0.5 * \
		(end_point->z * -fdf->cam->multi_factor)) * scale * cos(COS_30);
	new_end.y = (end_point->y + 0.5 * \
		(end_point->z * -fdf->cam->multi_factor)) * scale * sin(SEN_30);
	initial_point->x = new_initial.x;
	initial_point->y = new_initial.y;
	end_point->x = new_end.x;
	end_point->y = new_end.y;
}
