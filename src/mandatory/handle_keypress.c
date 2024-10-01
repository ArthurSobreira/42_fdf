/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:41:14 by arsobrei          #+#    #+#             */
/*   Updated: 2024/10/01 18:09:39 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_z_scale(int key, t_fdf *fdf);

int	handle_keypress(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		clear_all(fdf, 0);
	else if (key == XK_x || key == XK_z)
		handle_z_scale(key, fdf);
	return (0);
}

static void	handle_z_scale(int key, t_fdf *fdf)
{
	if (key == XK_x)
	{
		if (fdf->map->max_z < 20)
			fdf->cam->multi_factor += 1;
		else
			fdf->cam->multi_factor += 0.01;
	}
	else if (key == XK_z)
	{
		if (fdf->map->max_z < 20)
			fdf->cam->multi_factor -= 1;
		else
			fdf->cam->multi_factor -= 0.01;
	}
}
