/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:41:14 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/04 18:41:58 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		mlx_loop_end(fdf->mlx_ptr);
	else if (key == XK_1)
		bresenham(fdf, (t_point){20, 20, 0}, (t_point){500, 100, 0});
	else if (key == XK_2)
		bresenham(fdf, (t_point){20, 20, 0}, (t_point){500, 200, 0});
	else if (key == XK_3)
		bresenham(fdf, (t_point){20, 20, 0}, (t_point){500, 300, 0});
	else if (key == XK_4)
		bresenham(fdf, (t_point){20, 20, 0}, (t_point){500, 400, 0});
	else if (key == XK_5)
		bresenham(fdf, (t_point){20, 20, 0}, (t_point){500, 500, 0});
	else if (key == XK_6)
		bresenham(fdf, (t_point){200, 20, 0}, (t_point){50, 50, 0});
	return (0);
}
