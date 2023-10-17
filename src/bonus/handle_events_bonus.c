/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:41:14 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/17 13:36:04 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void handle_scale(int key, t_fdf *fdf);
static void	handle_z_scale(int key, t_fdf *fdf);
static void	handle_movement(int key, t_fdf *fdf);

int	handle_keypress(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		clear_all(fdf, 0);
	else if (key == XK_equal || key == XK_minus)
		handle_scale(key, fdf);
	else if (key == XK_x || key == XK_z)
		handle_z_scale(key, fdf);
	else if (key == XK_Up || key == XK_Down || \
				key == XK_Left || key == XK_Right)
		handle_movement(key, fdf);
	else if (key == XK_1)
		fdf->cam->projection = "ISO";
	else if (key == XK_2)
		fdf->cam->projection = "TOP";
	return (0);
}

static void handle_scale(int key, t_fdf *fdf)
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

static void	handle_z_scale(int key, t_fdf *fdf)
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

static void	handle_movement(int key, t_fdf *fdf)
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
