/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:42:02 by arsobrei          #+#    #+#             */
/*   Updated: 2023/07/27 19:26:03 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			ind;

	if ((dest == NULL) && (src == NULL))
	{
		return (NULL);
	}
	if (src > dest)
	{
		ind = 0;
		while (ind < n)
		{
			((unsigned char *)dest)[ind] = ((unsigned char *)src)[ind];
			ind++;
		}
	}
	else if (src < dest)
	{
		ind = n;
		while (ind > 0)
		{
			((unsigned char *)dest)[ind - 1] = ((unsigned char *)src)[ind - 1];
			ind--;
		}
	}
	return (dest);
}
