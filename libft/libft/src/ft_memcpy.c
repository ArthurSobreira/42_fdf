/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:29:59 by arsobrei          #+#    #+#             */
/*   Updated: 2023/07/27 18:09:49 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	index = 0;
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	if ((dest == NULL) && (src == NULL))
	{
		return (NULL);
	}
	while (index < n)
	{
		temp_dest[index] = temp_src[index];
		index++;
	}
	return (dest);
}
