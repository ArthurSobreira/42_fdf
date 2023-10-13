/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:24:11 by arsobrei          #+#    #+#             */
/*   Updated: 2023/07/25 19:02:19 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		last_index;
	char	*last_occ;

	last_index = ft_strlen(s);
	last_occ = NULL;
	while (last_index >= 0)
	{
		if (s[last_index] == (unsigned char) c)
		{
			last_occ = (char *)&s[last_index];
			return (last_occ);
		}
		last_index--;
	}
	return (last_occ);
}
