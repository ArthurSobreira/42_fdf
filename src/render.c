/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:43 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/06 14:19:08 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_fdf *fdf)
{
	render_background(fdf, 0x1a1a1a);
	// bresenham(fdf, (t_point){20, 20, 0}, (t_point){(WINDOW_WIDTH / 2), 20, 0});
	// bresenham(fdf, (t_point){20, 20, 0}, (t_point){20, (WINDOW_HEIGHT / 2), 0});
	bresenham2(fdf, (t_point){20, 20, 0}, (t_point){(WINDOW_WIDTH / 2), 20, 0});
	bresenham2(fdf, (t_point){20, 20, 0}, (t_point){20, (WINDOW_HEIGHT / 2), 0});
	//bresenham(fdf, (t_point){(WINDOW_WIDTH -  20), 20, 0}, (t_point){(WINDOW_WIDTH / 2), 20, 0});
	//bresenham(fdf, (t_point){(WINDOW_WIDTH - 20), 20, 0}, (t_point){200, 400, 0});
	
	// bresenham(fdf, (t_point){20, 20, 0}, (t_point){500, 100, 0});
	// bresenham(fdf, (t_point){20, 20, 0}, (t_point){500, 200, 0});
	// bresenham(fdf, (t_point){20, 20, 0}, (t_point){500, 300, 0});
	// bresenham(fdf, (t_point){20, 20, 0}, (t_point){500, 400, 0});

	// bresenham(fdf, (t_point){500, 400, 0}, (t_point){899, 20, 0});
	// bresenham(fdf, (t_point){20, 580, 0}, (t_point){700, 300, 0});
	// bresenham(fdf, (t_point){20, 580, 0}, (t_point){500, 200, 0});
	// bresenham(fdf, (t_point){20, 580, 0}, (t_point){500, 100, 0});

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
