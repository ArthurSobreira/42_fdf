/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:31:22 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/17 13:23:30 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(char *map_name)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (fdf == NULL)
		clear_all(fdf, 2);
	fdf->map = read_map(fdf, map_name);
	fdf->mlx_ptr = mlx_init();
	if (fdf->mlx_ptr == NULL)
		clear_all(fdf, 3);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, \
		WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	if (fdf->win_ptr == NULL)
	{
		clear_all(fdf, 4);
		free(fdf->win_ptr);
	}
	init_mlx_image(fdf);
	fdf->cam = init_cam(fdf->map);
	return (fdf);
}

t_cam	*init_cam(t_map *map)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (cam == NULL)
		handle_error(9);
	cam->scale = get_scale_factor(map);
	cam->x_offset = (WINDOW_WIDTH / 2) + 100;
	cam->y_offset = (WINDOW_HEIGHT / 2);
	cam->multi_factor = 1;
	if (map->max_z < 50)
		cam->multi_factor = 10;
	else if (map->max_z > 300)
		cam->multi_factor = 0.05;
	return (cam);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		handle_error(7);
	map->matrix = NULL;
	map->width = 0;
	map->height = 0;
	map->max_z = 0;
	return (map);
}

void	init_mlx_image(t_fdf *fdf)
{
	fdf->img.mlx_image = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH, \
													WINDOW_HEIGHT);
	fdf->img.adress = mlx_get_data_addr(fdf->img.mlx_image, \
		&fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
}

void	init_bres(t_bres *bres_info, t_point initial_point, t_point end_point)
{
	if (bres_info == NULL)
		handle_error(6);
	bres_info->delta_x = end_point.x - initial_point.x;
	bres_info->delta_y = end_point.y - initial_point.y;
	bres_info->initial_x = initial_point.x;
	bres_info->initial_y = initial_point.y;
	bres_info->x_increment = 1;
	bres_info->y_increment = 1;
	bres_info->decision = 0;
	if (bres_info->delta_y < 0)
	{
		bres_info->y_increment = -1;
		bres_info->delta_y = ft_abs(bres_info->delta_y);
	}
	if (bres_info->delta_x < 0)
	{
		bres_info->x_increment = -1;
		bres_info->delta_x = ft_abs(bres_info->delta_x);
	}
}
