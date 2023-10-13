/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:03:33 by arsobrei          #+#    #+#             */
/*   Updated: 2023/07/26 11:21:20 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	index = 0;
	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	while (index < n)
	{
		if (s1_temp[index] < s2_temp[index])
		{
			return (-1);
		}
		else if (s1_temp[index] > s2_temp[index])
		{
			return (1);
		}
		index++;
	}
	return (0);
}
