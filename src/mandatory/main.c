/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:00:26 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/14 17:53:48 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	char	*map_name;
	t_fdf	*fdf;

	map_name = argv[1];
	if ((argc != 2) || (!valid_map_name(map_name)))
		handle_error(1);
	fdf = init_fdf(map_name);
	mlx_loop_hook(fdf->mlx_ptr, &render, fdf);
	mlx_hook(fdf->win_ptr, KeyPress, KeyPressMask, &handle_keypress, fdf);
	mlx_hook(fdf->win_ptr, DestroyNotify, KeyReleaseMask, mlx_loop_end,
		fdf->mlx_ptr);
	mlx_loop(fdf->mlx_ptr);
	clear_all(fdf, 0);
	return (0);
}
