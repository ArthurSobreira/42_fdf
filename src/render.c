/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:43 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/14 19:48:15 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line_render(t_fdf *fdf, t_point initial_point, t_point end_point);

void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	render_background(fdf, WINDOW_BACKGROUND);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				line_render(fdf, fdf->map->matrix[y][x], \
								fdf->map->matrix[y][x + 1]);
			if (y < fdf->map->height - 1)
				line_render(fdf, fdf->map->matrix[y][x], \
								fdf->map->matrix[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
								fdf->img.mlx_image, 0, 0);
}

static void	line_render(t_fdf *fdf, t_point initial_point, t_point end_point)
{
	scale_map(fdf, &initial_point, &end_point);
	isometric(&initial_point, &end_point);
	centralize(fdf, &initial_point, &end_point);
	bresenham(fdf, initial_point, end_point);
}

void	render_background(t_fdf *fdf, int color)
{
	unsigned int	x;
	unsigned int	y;

	if (fdf->win_ptr != NULL)
	{
		y = 0;
		while (y++ < WINDOW_HEIGHT)
		{
			x = 0;
			while (x++ < WINDOW_WIDTH)
				pixel_put(fdf, x, y, color);
		}
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
								fdf->img.mlx_image, 0, 0);
	}
}
