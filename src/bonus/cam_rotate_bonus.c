/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:54:45 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/19 11:20:17 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x(t_fdf *fdf, t_point *initial_p, t_point *end_p, float angle)
{
	t_point	new_initial;
	t_point	new_end;
	float	cos_ang;
	float	sin_ang;

	cos_ang = cos(angle);
	sin_ang = sin(angle);
	new_initial.y = initial_p->y * cos_ang - \
				(initial_p->z * fdf->cam->multi_factor) * sin_ang;
	new_initial.z = initial_p->y * sin_ang + \
				(initial_p->z * fdf->cam->multi_factor) * cos_ang;
	new_end.y = end_p->y * cos_ang - \
				(end_p->z * fdf->cam->multi_factor) * sin_ang;
	new_end.z = end_p->y * sin_ang + \
				(end_p->z * fdf->cam->multi_factor) * cos_ang;
	initial_p->y = new_initial.y;
	initial_p->z = new_initial.z;
	end_p->y = new_end.y;
	end_p->z = new_end.z;
}

void	rotate_y(t_point *initial_point, t_point *end_point, float angle)
{
	t_point	new_initial;
	t_point	new_end;
	float	cos_ang;
	float	sin_ang;

	cos_ang = cos(angle);
	sin_ang = sin(angle);
	new_initial.x = initial_point->x * cos_ang + \
				initial_point->z * sin_ang;
	new_initial.z = initial_point->x * sin_ang + \
				initial_point->z * cos_ang;
	new_end.x = end_point->x * cos_ang + \
				end_point->z * sin_ang;
	new_end.z = end_point->x * sin_ang + \
				end_point->z * cos_ang;
	initial_point->x = new_initial.x;
	initial_point->z = new_initial.z;
	end_point->x = new_end.x;
	end_point->z = new_end.z;
}

void	rotate_z(t_point *initial_point, t_point *end_point, float angle)
{
	t_point	new_initial;
	t_point	new_end;
	float	cos_ang;
	float	sin_ang;

	cos_ang = cos(angle);
	sin_ang = sin(angle);
	new_initial.x = initial_point->x * cos_ang - \
				initial_point->y * sin_ang;
	new_initial.y = initial_point->x * sin_ang + \
				initial_point->y * cos_ang;
	new_end.x = end_point->x * cos_ang - \
					end_point->y * sin_ang;
	new_end.y = end_point->x * sin_ang + \
					end_point->y * cos_ang;
	initial_point->x = new_initial.x;
	initial_point->y = new_initial.y;
	end_point->x = new_end.x;
	end_point->y = new_end.y;
}
