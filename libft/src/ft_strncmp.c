/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:45:32 by arsobrei          #+#    #+#             */
/*   Updated: 2023/07/20 18:20:44 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((s1[index]) && (s1[index] == s2[index]) && (index < n))
	{
		index++;
	}
	if (index == n)
	{
		return (0);
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
