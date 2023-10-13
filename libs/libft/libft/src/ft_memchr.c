/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:41:35 by arsobrei          #+#    #+#             */
/*   Updated: 2023/07/26 16:02:40 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	char			*first_occ;
	unsigned char	*temp_s;
	unsigned char	temp_c;

	index = 0;
	first_occ = NULL;
	temp_s = (unsigned char *) s;
	temp_c = (unsigned char) c;
	while (index < n)
	{
		if (temp_s[index] == temp_c)
		{
			first_occ = (void *)&temp_s[index];
			return (first_occ);
		}
		index++;
	}
	return (first_occ);
}
