/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:41:18 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/16 17:11:24 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	render_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					25, 20, 0xffffff, "     __________  ______");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					25, 30, 0xffffff, "    / ____/ __ \\/ ____/");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					25, 40, 0xffffff, "   / /_  / / / / /_    ");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					25, 50, 0xffffff, "  / __/ / /_/ / __/    ");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					25, 60, 0xffffff, " /_/   /_____/_/       ");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 75, 0xffffff, "_________________________");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 100, 0xffffff, "Increase Scale Z - 'x'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 120, 0xffffff, "Decrease Scale Z - 'z'");
}

void	render_menu_bar(t_fdf *fdf, int color)
{
	unsigned int	x;
	unsigned int	y;

	if (fdf->win_ptr != NULL)
	{
		y = 0;
		while (y++ < WINDOW_HEIGHT)
		{
			x = 0;
			while (x++ < 200)
			{
				if (x < 5 || x > 195 || y < 5 || y > 795)
					pixel_put(fdf, x, y, 0x010101);
				else
					pixel_put(fdf, x, y, color);
			}
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
		while (y++ < WINDOW_HEIGHT)
		{
			x = 200;
			while (x++ < WINDOW_WIDTH)
				pixel_put(fdf, x, y, color);
		}
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
								fdf->img.mlx_image, 0, 0);
	}
}
