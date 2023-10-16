/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:30:28 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/16 15:34:43 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_all(t_fdf *fdf, short exit_code)
{
	clear_matrix(fdf->map->matrix, fdf->map->height);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.mlx_image);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	free(fdf->map);
	free(fdf->cam);
	free(fdf);
	handle_error(exit_code);
}

void	clear_matrix(t_point **matrix, int height)
{
	int	index;

	index = 0;
	while (index < height)
	{
		free(matrix[index]);
		index++;
	}
	free(matrix);
}

void	clear_invalid_map(t_fdf *fdf, t_map *map)
{
	free(map);
	free(fdf);
	handle_error(7);
}
