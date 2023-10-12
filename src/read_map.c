/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:12:37 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/12 16:58:25 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_width(char *map_name);
static int	get_height(char *map_name);

t_map	*read_map(char *map_name)
{
	t_map	*map;

	map = init_map();
	if (map == NULL)
		handle_error(7);
	map->width = get_width(map_name); // verificar se é maior que 2
	map->height = get_height(map_name); // verificar se é maior que 2		
	ft_printf("width: %d | height: %d\n", map->width, map->height);
	//map->matrix = init_matrix();
	// map->matrix = get_matrix(map_name, map->x_max, map->y_max);
	return (map);
}

static int	get_width(char *map_name)
{
	char	*line;
	char	**split_line;
	int		file_descriptor;
	int		width;
	int		index;

	file_descriptor = open(map_name, O_RDONLY);
	line = get_next_line(file_descriptor);
	split_line = ft_split(line, ' ');
	width = 0;
	index = 0;
	while (split_line[index])
	{
		if (ft_strncmp(split_line[index], "\n",\
					ft_strlen(split_line[index])))
			width++;
		index++;
	}
	free_split(split_line);
	free(line);
	if (!valid_width(file_descriptor, width))
		return (FALSE);
	return (width);
}

static int	get_height(char *map_name)
{
	int		file_descriptor;
	char	*line;
	int		height;

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
