/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:41:14 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/16 18:51:37 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	handle_keypress(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		clear_all(fdf, 0);
	else if (key == XK_equal)
		fdf->cam->scale += 0.2;
	else if (key == XK_minus)
		fdf->cam->scale -= 0.2;
	else if (key == XK_x)
		fdf->cam->multi_factor += 0.2;
	else if (key == XK_z)
		fdf->cam->multi_factor -= 0.2;
	else if (key == XK_Up)
		fdf->cam->y_offset += 10;
	else if (key == XK_Down)
		fdf->cam->y_offset -= 10;
	else if (key == XK_Left)
		fdf->cam->x_offset += 10;
	else if (key == XK_Right)
		fdf->cam->x_offset -= 10;
	else if (key == XK_i)
		fdf->cam->projection = "ISO";
	else if (key == XK_t)
		fdf->cam->projection = "TOP";
	return (0);
}
