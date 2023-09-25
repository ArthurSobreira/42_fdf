/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:27:29 by arsobrei          #+#    #+#             */
/*   Updated: 2023/07/26 11:33:10 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	index;
	char	*first_occ;

	len_little = ft_strlen(little);
	first_occ = NULL;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	index = 0;
	while ((big[index]) && (len_little <= len))
	{
		if (ft_memcmp(&big[index], little, len_little) == 0)
		{
			first_occ = (char *)&big[index];
			return (first_occ);
		}
		index++;
		len--;
	}
	return (first_occ);
}
