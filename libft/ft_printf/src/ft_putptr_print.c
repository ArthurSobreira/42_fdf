/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:45:11 by arsobrei          #+#    #+#             */
/*   Updated: 2023/09/25 12:18:40 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_print(unsigned long number, char *base)
{
	int	length;
	int	base_length;

	length = 0;
	base_length = ft_strlen(base);
	if (number == 0)
	{
		return (ft_putstr_print("(nil)"));
	}
	if (number >= (unsigned long)base_length)
	{
		length += ft_putptr_print((number / base_length), base);
	}
	else
	{
		length += ft_putstr_print("0x");
	}
	length += ft_putchar_print(base[number % base_length]);
	return (length);
}
