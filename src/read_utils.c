/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:23:42 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/11 15:55:37 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	valid_map_name(char *file_name)
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
