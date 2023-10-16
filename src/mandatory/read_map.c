/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:12:37 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/16 15:26:39 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_matrix(t_map *map, char **split_line, int height);
static void	get_matrix(t_map *map, char *map_name);
static int	get_width(char *map_name);
static int	get_height(char *map_name);

t_map	*read_map(t_fdf *fdf, char *map_name)
{
	t_map	*map;

	map = init_map();
	if (map == NULL)
		handle_error(7);
	map->height = get_height(map_name);
	map->width = get_width(map_name);
	if ((!map->width) || (map->width < 2) || (map->height < 2))
		clear_invalid_map(fdf, map);
	map->matrix = init_matrix(map->width, map->height);
	if (map->matrix == NULL)
		handle_error(8);
	get_matrix(map, map_name);
	center_to_origin(map);
	return (map);
}

static int	get_width(char *map_name)
{
	char	*line;
	char	**split_line;
	int		file_descriptor;
	int		width;

	file_descriptor = open(map_name, O_RDONLY);
	line = get_next_line(file_descriptor);
	split_line = ft_split(line, ' ');
	width = 0;
	while ((split_line[width]) && \
			(ft_strncmp(split_line[width], "\n", \
			ft_strlen(split_line[width])) != 0))
		width++;
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
			break ;
		height++;
		free(line);
	}
	close(file_descriptor);
	return (height);
}

static void	get_matrix(t_map *map, char *map_name)
{
	int		file_descriptor;
	char	*line;
	char	**split_line;
	int		height;

	file_descriptor = open(map_name, O_RDONLY);
	height = 0;
	while (1)
	{
		line = get_next_line(file_descriptor);
		if ((line == NULL) && (!ft_isprint(*line)))
			break ;
		split_line = ft_split(line, ' ');
		fill_matrix(map, split_line, height);
		free_split(split_line);
		free(line);
		height++;
	}
}

static void	fill_matrix(t_map *map, char **split_line, int height)
{
	int	index;

	index = 0;
	while (index < map->width)
	{
		map->matrix[height][index].x = (float)index;
		map->matrix[height][index].y = (float)height;
		map->matrix[height][index].z = (float)ft_atoi(split_line[index]);
		if (map->matrix[height][index].z > map->max_z)
			map->max_z = map->matrix[height][index].z;
		if (ft_strchr(split_line[index], ','))
			map->matrix[height][index].color = ft_atoi_base(\
					ft_strchr(split_line[index], 'x') + 1, HEXA_BASE);
		else
			map->matrix[height][index].color = 0xffffff;
		index++;
	}
}
