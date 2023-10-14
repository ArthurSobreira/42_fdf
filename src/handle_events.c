/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:41:14 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/14 19:14:13 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		clear_all(fdf, 0);
	else if (key == XK_1)
	{
		fdf->cam->scale += (float)1;
		printf("escala: %f\n", fdf->cam->scale);
	}
	else if (key == XK_2)
	{
		fdf->cam->scale -= (float)1;
		printf("escala: %f\n", fdf->cam->scale);
	}
	else if (key == XK_Up)
	{
		fdf->cam->y_offset -= (float)10;
		printf("y_offset: %f\n", fdf->cam->y_offset);
	}
	else if (key == XK_Down)
	{
		fdf->cam->y_offset += (float)10;
		printf("y_offset: %f\n", fdf->cam->y_offset);
	}
	else if (key == XK_Left)
	{
		fdf->cam->x_offset -= (float)10;
		printf("x_offset: %f\n", fdf->cam->x_offset);
	}
	else if (key == XK_Right)
	{
		fdf->cam->x_offset += (float)10;
		printf("x_offset: %f\n", fdf->cam->x_offset);
	}
	return (0);
}

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
