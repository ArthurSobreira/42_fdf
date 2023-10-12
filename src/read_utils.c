/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:23:42 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/11 17:42:28 by arsobrei         ###   ########.fr       */
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
