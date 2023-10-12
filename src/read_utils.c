/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:23:42 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/12 19:23:18 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**init_matrix(int width, int height)
{
	t_point	**matrix;
	int		i;
	int		j;

	matrix = malloc(width * sizeof(t_point *));
	if (matrix == NULL)
		handle_error(8);
	i = 0;
	while (i < width)
	{
		matrix[i] = malloc(height * sizeof(t_point));
		if (matrix[i] == NULL)
			handle_error(8);
		j = 0;
		while (j < height)
		{
			matrix[i][j].x = 0;
			matrix[i][j].y = 0;
			matrix[i][j].z = 0;
			matrix[i][j].color = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

short	valid_map_name(char *file_name)
{
	size_t	len;
	int		file_descriptor;
	char	*first_line;

	len = ft_strlen(file_name);
	if (!ft_strnstr(file_name, ".fdf", len))
		return (FALSE);
	file_descriptor = open(file_name, O_RDONLY);
	first_line = get_next_line(file_descriptor);
	if (first_line == NULL)
		return (FALSE);
	if (file_descriptor < 0)
	{
		close(file_descriptor);
		return (FALSE);
	}
	free(first_line);
	close(file_descriptor);
	return (TRUE);
}

short	valid_width(int file_descriptor, int width)
{
	char	*line;
	char	**split_line;
	int		temp_width;
	short	valid;

	temp_width = 0;
	valid = 1;
	while (1)
	{
		line = get_next_line(file_descriptor);
		if ((line == NULL) && (!ft_isprint(*line)))
			break ;
		split_line = ft_split(line, ' ');
		while ((split_line[temp_width]) && \
				(ft_strncmp(split_line[temp_width], "\n", \
				ft_strlen(split_line[temp_width])) != 0))
			temp_width++;
		if (temp_width != width)
			valid = 0;
		temp_width = 0;
		free_split(split_line);
		free(line);
	}
	close(file_descriptor);
	return (valid);
}

void	free_split(char **split_line)
{
	size_t	index;

	index = 0;
	while (split_line[index] != NULL)
	{
		free(split_line[index]);
		index++;
	}
	free(split_line);
}

void	not_valid_map(t_fdf *fdf, t_map *map)
{
	free(map);
	free(fdf);
	handle_error(7);
}
