/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:23:42 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/12 16:54:58 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

short	valid_map_name(char *file_name)
{
	size_t	len;
	int		file_descriptor;

	len = ft_strlen(file_name);
	if (!ft_strnstr(file_name, ".fdf", len))
		return (FALSE);
	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor < 0)
	{
		close(file_descriptor);
		return (FALSE);
	}
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
			break;
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

void	not_valid_map(t_fdf *fdf, short exit_code)
{
	free(fdf->map);
	free(fdf);
	handle_error(exit_code);
}
