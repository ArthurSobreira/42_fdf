/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:25:17 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/18 12:26:49 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	handle_scale(int key, t_fdf *fdf)
{
	if (key == XK_equal)
	{
		if (fdf->map->max_z < 50)
			fdf->cam->scale += 1;
		else
			fdf->cam->scale += 0.2;
	}
	else if (key == XK_minus)
	{
		if (fdf->map->max_z < 50)
			fdf->cam->scale -= 1;
		else
			fdf->cam->scale -= 0.2;
	}
}

void	handle_z_scale(int key, t_fdf *fdf)
{
	if (key == XK_x)
	{
		if (fdf->map->max_z > 300)
			fdf->cam->multi_factor += 0.02;
		else if (fdf->map->max_z < 20)
			fdf->cam->multi_factor += 1;
		else
			fdf->cam->multi_factor += 0.2;
	}
	else if (key == XK_z)
	{
		if (fdf->map->max_z > 300)
			fdf->cam->multi_factor -= 0.02;
		else if (fdf->map->max_z < 20)
			fdf->cam->multi_factor -= 1;
		else
			fdf->cam->multi_factor -= 0.2;
	}
}

void	handle_movement(int key, t_fdf *fdf)
{
	if (key == XK_Up)
		fdf->cam->y_offset += 10;
	else if (key == XK_Down)
		fdf->cam->y_offset -= 10;
	else if (key == XK_Left)
		fdf->cam->x_offset += 10;
	else if (key == XK_Right)
		fdf->cam->x_offset -= 10;
}

void	reset_all(t_fdf *fdf)
{
	fdf->cam->scale = get_scale_factor(fdf->map);
	fdf->cam->x_offset = (WINDOW_WIDTH / 2) + 100;
	fdf->cam->y_offset = (WINDOW_HEIGHT / 2);
	fdf->cam->multi_factor = 1;
	if (fdf->map->max_z < 50)
		fdf->cam->multi_factor = 10;
	else if (fdf->map->max_z > 300)
		fdf->cam->multi_factor = 0.05;
	fdf->cam->projection = "ISO";
}