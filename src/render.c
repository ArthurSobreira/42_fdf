/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:43 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/11 15:56:53 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_fdf *fdf)
{
	render_background(fdf, WINDOW_BACKGROUND);
	// int x1, y1, x2, y2;

    // int interval = 50;

    // for (x1 = 10; x1 < WINDOW_WIDTH; x1 += interval)
    // {
    //     for (y1 = 10; y1 < WINDOW_HEIGHT; y1 += interval)
    //     {
	// 		render_background(fdf, WINDOW_BACKGROUND);
    //         for (x2 = 10; x2 < WINDOW_WIDTH; x2 += interval)
    //         {
    //             for (y2 = 10; y2 < WINDOW_HEIGHT; y2 += interval)
    //             {
    //                 bresenham(fdf, (t_point){x1, y1, 0, 0x5f59ff}, \
	// 								(t_point){x2, y2, 0, 0x5f59ff});
    //             }
	// 			mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
	// 							fdf->img.mlx_image, 0, 0);
    //         }
    //     }
    // }
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
								fdf->img.mlx_image, 0, 0);
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
	}
}
