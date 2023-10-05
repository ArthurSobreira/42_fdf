/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:17:07 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/05 10:20:32 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_fdf *fdf, t_point inital_point, t_point end_point)
{
	int	delta_y;
	int	delta_x;
	int	x;
	int	y;
	int	e;

	render_background(fdf, 0x1a1a1a);
	delta_y = end_point.y - inital_point.y;
	delta_x = end_point.x - inital_point.x;
	x = inital_point.x;
	y = inital_point.y;
	e = 0;
	while (x <= end_point.x)
	{
		pixel_put(fdf, x, y, (0x0000ff * (x / 4)));
		x = x + 1;
		e = e + (2 * delta_y);
		if (e >= delta_x)
		{
			y = y + 1;
			e = e - (2 * delta_x);
		}
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.mlx_image, 0, 0);
}

void	pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	pixel = fdf->img.adress + (y * fdf->img.line_length + x \
								* (fdf->img.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}