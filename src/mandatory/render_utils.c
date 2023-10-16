/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:41:18 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/16 14:37:20 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			x = 0;
			while (x++ < WINDOW_WIDTH)
				pixel_put(fdf, x, y, color);
		}
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
								fdf->img.mlx_image, 0, 0);
	}
}
