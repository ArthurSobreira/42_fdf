/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:39:24 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/02 19:14:07 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	last_index;
	size_t	first_index;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
	first_index = 0;
	while ((s1[first_index]) && (ft_strchr(set, s1[first_index])))
	{
		first_index++;
	}
	last_index = ft_strlen(s1);
	while ((last_index) && (ft_strchr(set, s1[last_index - 1])))
	{
		last_index--;
	}
	return (ft_substr(s1, first_index, last_index - first_index));
}
