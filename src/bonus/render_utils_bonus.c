/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:41:18 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/19 11:33:05 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	render_menu(t_fdf *fdf, int color)
{
	render_ascii_menu(fdf, color);
	render_scale_zoom_menu(fdf, color);
	render_move_menu(fdf, color);
	render_rotation_menu(fdf, color);
	render_project_menu(fdf, color);
}

void	render_menu_bar(t_fdf *fdf, int color)
{
	unsigned int	x;
	unsigned int	y;

	if (fdf->win_ptr != NULL)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			x = 0;
			while (x < 200)
			{
				if (x < 5 || x > 195 || y < 5 || y > 895)
					pixel_put(fdf, x, y, 0x010101);
				else
					pixel_put(fdf, x, y, color);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
								fdf->img.mlx_image, 0, 0);
	}
}

void	render_background(t_fdf *fdf, int color)
{
	unsigned int	x;
	unsigned int	y;

	if (fdf->win_ptr != NULL)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			x = 0;
			while (x < WINDOW_WIDTH)
			{
				pixel_put(fdf, x, y, color);
				if (x < 5 || x > 1295 || y < 5 || y > 895)
					pixel_put(fdf, x, y, 0x010101);
				else
					pixel_put(fdf, x, y, color);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
								fdf->img.mlx_image, 0, 0);
	}
}
