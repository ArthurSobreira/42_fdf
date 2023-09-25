/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:58:56 by arsobrei          #+#    #+#             */
/*   Updated: 2023/07/25 18:46:58 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	char	*first_occ;

	index = 0;
	first_occ = NULL;
	while (index <= ft_strlen(s))
	{
		if (s[index] == (unsigned char) c)
		{
			first_occ = (char *)&s[index];
			return (first_occ);
		}
		index++;
	}
	return (first_occ);
}
