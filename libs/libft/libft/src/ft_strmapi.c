/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:27:03 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/02 09:27:03 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	lenght;
	size_t	index;
	char	*result;

	if (s == NULL)
	{
		return (NULL);
	}
	lenght = ft_strlen(s);
	result = (char *)malloc((lenght + 1) * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}
	index = 0;
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}
