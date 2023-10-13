/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:33:39 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/13 19:34:44 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	scale_map(t_map *map)
{
	float	scale_factor;
	float	scale_x;
	float	scale_y;

	scale_x = (float)WINDOW_WIDTH / (float)map->width;
	scale_y = (float)WINDOW_HEIGHT / (float)map->height;
	if (scale_x < scale_y)
		scale_factor = scale_x;
	else
		scale_factor = scale_y;
	if (scale_factor < 3)
		return (2);
	return (scale_factor / 2);
}
