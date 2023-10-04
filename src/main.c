/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:00:26 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/04 11:05:22 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	(void)argv;
	if (argc != 2)
		handle_error(1);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (fdf == NULL)
		handle_error(2);
	fdf->mlx_ptr = mlx_init();
	if (fdf->mlx_ptr == NULL)
		handle_error(3);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, \
							WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	if (fdf->win_ptr == NULL)
	{
		free(fdf->win_ptr);
		handle_error(4);
	}
	fdf->img.mlx_image = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH, \
														WINDOW_HEIGHT);
	fdf->img.adress = mlx_get_data_addr(fdf->img.mlx_image, \
			&fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	render_background(fdf, 0x1a1a1a);
	mlx_key_hook(fdf->win_ptr, &handle_keypress, fdf);
	mlx_hook(fdf->win_ptr, DestroyNotify, KeyReleaseMask, mlx_loop_end,
		fdf->mlx_ptr);
	mlx_loop(fdf->mlx_ptr);
	clear_all(fdf);
	return (0);
}
