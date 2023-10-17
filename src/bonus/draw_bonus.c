/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:17:07 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/17 11:21:21 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	if ((x < 0) || (y < 0) || (x > WINDOW_WIDTH) || (y > WINDOW_HEIGHT))
		handle_error(5);
	pixel = fdf->img.adress + (y * fdf->img.line_length + x \
								* (fdf->img.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	bresenham(t_fdf *fdf, t_point inital_point, t_point end_point)
{
	float	temp_delta_x;
	float	temp_delta_y;

	temp_delta_x = end_point.x - inital_point.x;
	temp_delta_y = end_point.y - inital_point.y;
	if (ft_abs(temp_delta_x) > ft_abs(temp_delta_y))
	{
		if (inital_point.x > end_point.x)
			bresenham_high(fdf, end_point, inital_point);
		else
			bresenham_high(fdf, inital_point, end_point);
	}
	else
	{
		if (inital_point.y > end_point.y)
			bresenham_low(fdf, end_point, inital_point);
		else
			bresenham_low(fdf, inital_point, end_point);
	}
}

void	bresenham_high(t_fdf *fdf, t_point initial_point, t_point end_point)
{
	t_bres	bres;

	init_bres(&bres, initial_point, end_point);
	bres.decision = (2 * bres.delta_y) - bres.delta_x;
	while (bres.initial_x <= end_point.x)
	{
		if ((bres.initial_x >= 0) && (bres.initial_y >= 0) && \
		(bres.initial_x < WINDOW_WIDTH) && (bres.initial_y < WINDOW_HEIGHT))
			pixel_put(fdf, bres.initial_x, bres.initial_y, \
										initial_point.color);
		if (bres.decision > 0)
		{
			bres.initial_y += bres.y_increment;
			bres.decision += (2 * (bres.delta_y - bres.delta_x));
		}
		else
			bres.decision += (2 * bres.delta_y);
		bres.initial_x++;
	}
}

void	bresenham_low(t_fdf *fdf, t_point initial_point, t_point end_point)
{
	t_bres	bres;

	init_bres(&bres, initial_point, end_point);
	bres.decision = (2 * bres.delta_x) - bres.delta_y;
	while (bres.initial_y <= end_point.y)
	{
		if ((bres.initial_x >= 0) && (bres.initial_y >= 0) && \
		(bres.initial_x < WINDOW_WIDTH) && (bres.initial_y < WINDOW_HEIGHT))
			pixel_put(fdf, bres.initial_x, bres.initial_y, \
										initial_point.color);
		if (bres.decision > 0)
		{
			bres.initial_x += bres.x_increment;
			bres.decision += (2 * (bres.delta_x - bres.delta_y));
		}
		else
			bres.decision += (2 * bres.delta_x);
		bres.initial_y++;
	}
}
