/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:41:14 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/12 15:35:01 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		clear_all(fdf, 0);
	return (0);
}

void	clear_all(t_fdf *fdf, short exit_code)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.mlx_image);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	free(fdf->map);
	free(fdf);
	handle_error(exit_code);
}
