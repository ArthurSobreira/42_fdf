/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:01:13 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/16 18:04:53 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	render_ascii_menu(t_fdf *fdf, int color)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					25, 20, color, "     __________  ______");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					25, 30, color, "    / ____/ __ \\/ ____/");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					25, 40, color, "   / /_  / / / / /_    ");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					25, 50, color, "  / __/ / /_/ / __/    ");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					25, 60, color, " /_/   /_____/_/       ");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 75, color, "_________________________");
}

void	render_scale_zoom_menu(t_fdf *fdf, int color)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 100, color, "Increase Scale Z - 'x'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 120, color, "Decrease Scale Z - 'z'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 150, color, "Zoom in - '+'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 170, color, "Zoom out - '-'");
}

void	render_move_menu(t_fdf *fdf, int color)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 200, color, "Move Up - 'Arrow Up'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 220, color, "Move Down - 'Arrow Down'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 240, color, "Move Left - 'Arrow Left'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, \
					20, 260, color, "Move Right - 'Arrow Right'");
}
