/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:45:29 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/02 11:44:44 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	result_index;
	size_t	index;
	char	*result;

	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result_index = 0;
	index = 0;
	while (s1[index])
	{
		result[result_index] = s1[index];
		index++;
		result_index++;
	}
	index = 0;
	while (s2[index])
	{
		result[result_index] = s2[index];
		index++;
		result_index++;
	}
	result[result_index] = '\0';
	return (result);
}
