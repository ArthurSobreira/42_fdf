/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:17:07 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/06 14:16:44 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	pixel = fdf->img.adress + (y * fdf->img.line_length + x \
								* (fdf->img.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	bresenham2(t_fdf *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	i_line = 0;
	while (i_line++ < max_steps)
	{
		if (start.x > 0 && start.y > 0 && start.x < WINDOW_WIDTH && start.y < \
				WINDOW_HEIGHT)
			pixel_put(fdf, start.x, start.y, (0xffffff * (i_line / 4)));
		start.x += x_step;
		start.y += y_step;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.mlx_image, 0, 0);
}

void	bresenham(t_fdf *fdf, t_point inital_point, t_point end_point)
{	
	int	delta_y;
	int	delta_x;
	int	initial_x;
	int	initial_y;
	int	error;
	int	x_increment;
	int	y_increment;
	int	verify;

	delta_x = ft_abs(end_point.x - inital_point.x);
	delta_y = ft_abs(end_point.y - inital_point.y);
	initial_x = inital_point.x;
	initial_y = inital_point.y;
	error = 0;

	if (end_point.x >= inital_point.x)
		x_increment = 1;
	else
		x_increment = -1;
	
	if (end_point.y >= inital_point.y)
		y_increment = 1;
	else
		y_increment = -1;
	
	verify = verify_octant(&delta_x, &delta_y, &initial_x, &initial_y);

	while ((initial_x <= end_point.x) && (initial_y <= end_point.y))
	{
		if (verify)
			pixel_put(fdf, initial_y, initial_x, (0xffffff * (initial_x / 4)));
		else
			pixel_put(fdf, initial_x, initial_y, (0xffffff * (initial_x / 4)));
		initial_x += x_increment;
		error += (2 * delta_y);
		if (error >= delta_x)
		{
			initial_y += y_increment;
			error -= (2 * delta_x);
		}
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.mlx_image, 0, 0);
}
