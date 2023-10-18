/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:41:14 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/18 12:42:35 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	handle_keypress(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		clear_all(fdf, 0);
	else if (key == XK_equal || key == XK_minus)
		handle_scale(key, fdf);
	else if (key == XK_x || key == XK_z)
		handle_z_scale(key, fdf);
	else if (key == XK_Up || key == XK_Down || \
				key == XK_Left || key == XK_Right)
		handle_movement(key, fdf);
	else if (key == XK_r)
		reset_all(fdf);
	else if (key == XK_1)
		fdf->cam->projection = "ISO";
	else if (key == XK_2)
		fdf->cam->projection = "TOP";
	return (0);
}
