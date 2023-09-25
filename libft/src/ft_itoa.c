/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:24:31 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/02 09:24:31 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digits_counter(int number)
{
	int	lenght;

	lenght = 0;
	if (number <= 0)
	{
		lenght++;
	}
	while (number)
	{
		lenght++;
		number = number / 10;
	}
	return (lenght);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len_number;
	long	number;

	len_number = ft_digits_counter(n);
	number = n;
	result = (char *)malloc((len_number + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (number == 0)
		result[0] = '0';
	if (number < 0)
	{
		result[0] = '-';
		number *= -1;
	}
	result[len_number] = '\0';
	len_number--;
	while (number)
	{
		result[len_number] = (number % 10) + '0';
		number = number / 10;
		len_number--;
	}
	return (result);
}
