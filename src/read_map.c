/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:12:37 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/10 20:06:47 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	valid_map(char *file_name);
static int	get_width(char *map_name);
static int	get_height(char *map_name);

t_map	*read_map(char *map_name)
{
	t_map	*map;

	if (!valid_map(map_name))
		handle_error(1);
	map = init_map();
	if (map == NULL)
		handle_error(7);
	map->width = get_width(map_name);
	map->height = get_height(map_name);
	ft_printf("width: %d\n", map->width);
	ft_printf("height: %d\n", map->height);
	// map->matrix = get_matrix(map_name, map->x_max, map->y_max);
	return (map);
}

static int	get_width(char *map_name)
{
	int		file_descriptor;
	int		width;
	int		index;
	char	*line;
	char	**split_line;

	file_descriptor = open(map_name, O_RDONLY);
	width = 0;
	while (1)
	{
		line = get_next_line(file_descriptor);
		if ((line == NULL) && (!ft_isprint(*line)))
			break;
		split_line = ft_split(line, ' ');
		index = 0;
		while (split_line[index] != NULL)
		{
			if ((line == NULL) && (index == 0))
				width++;
			free(split_line[index]);
			index++;
		}
		free(split_line);
		free(line);
	}
	close(file_descriptor);
	return (width);
}

static int	get_height(char *map_name)
{
	int		file_descriptor;
	int		height;
	char	*line;

	file_descriptor = open(map_name, O_RDONLY);
	height = 0;
	while (1)
	{
		line = get_next_line(file_descriptor);
		if ((line == NULL) && (!ft_isprint(*line)))
			break;
		height++;
		free(line);	
	}
	close(file_descriptor);
	return (height);
}

static int	valid_map(char *file_name)
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
