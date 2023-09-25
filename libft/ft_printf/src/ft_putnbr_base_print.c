/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:09:59 by arsobrei          #+#    #+#             */
/*   Updated: 2023/09/25 12:18:48 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_print(long int number, char *base)
{
	int	length;
	int	base_length;

	length = 0;
	base_length = ft_strlen(base);
	if (number == -2147483648)
	{
		length += ft_putchar_print('-');
		length += ft_putchar_print('2');
		number = 147483648;
	}
	if (number < 0)
	{
		length += ft_putchar_print('-');
		number *= -1;
	}
	if (number >= base_length)
	{
		length += ft_putnbr_base_print((number / base_length), base);
	}
	length += ft_putchar_print(base[number % base_length]);
	return (length);
}
