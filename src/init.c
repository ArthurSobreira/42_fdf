/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:31:22 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/10 10:35:29 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_bres(t_bres *bres_info, t_point initial_point, t_point end_point)
{
	if (bres_info == NULL)
		handle_error(6);
	bres_info->delta_x = end_point.x - initial_point.x;
	bres_info->delta_y = end_point.y - initial_point.y;
	bres_info->initial_x = initial_point.x;
	bres_info->initial_y = initial_point.y;
	bres_info->x_increment = 1;
	bres_info->y_increment = 1;
	bres_info->decision = 0;
	if (bres_info->delta_y < 0)
	{
		bres_info->y_increment = -1;
		bres_info->delta_y = ft_abs(bres_info->delta_y);
	}
	if (bres_info->delta_x < 0)
	{
		bres_info->x_increment = -1;
		bres_info->delta_x = ft_abs(bres_info->delta_x);
	}
}
