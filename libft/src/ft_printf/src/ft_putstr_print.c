/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:09:06 by arsobrei          #+#    #+#             */
/*   Updated: 2023/09/25 11:47:06 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_print(char *str)
{
	int	length;

	if (str == NULL)
	{
		return (ft_putstr_print("(null)"));
	}
	length = ft_strlen(str);
	write(1, str, length);
	return (length);
}
