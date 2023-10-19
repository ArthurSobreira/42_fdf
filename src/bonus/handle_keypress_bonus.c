/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:41:14 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/19 12:32:50 by arsobrei         ###   ########.fr       */
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
	else if (key == XK_w || key == XK_s || key == XK_a || \
				key == XK_d || key == XK_q || key == XK_e)
		handle_rotate(key, fdf);
	else if (key == XK_r)
		reset_all(fdf);
	else if (key == XK_1)
		fdf->cam->projection = ISOMETRIC;
	else if (key == XK_2)
		fdf->cam->projection = OBLIQUE;
	else if (key == XK_3)
		fdf->cam->projection = TOP_VIEW;
	return (0);
}
