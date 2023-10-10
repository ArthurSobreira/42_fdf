/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:12:37 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/10 17:45:29 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static short	valid_map(char *file_name);

t_map	*read_map(char *map_name)
{
	t_map	*map;

	if (!valid_map(map_name))
		handle_error(1);
	map = init_map();
	return (map);
}

static short	valid_map(char *file_name)
{
	int	file_descriptor;

	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor < 0)
	{
		close(file_descriptor);
		return (0);
	}
	close(file_descriptor);
	return (1);
}
