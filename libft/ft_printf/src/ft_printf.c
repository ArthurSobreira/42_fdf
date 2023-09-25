/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:13:26 by arsobrei          #+#    #+#             */
/*   Updated: 2023/09/25 12:19:19 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list args, char current_format);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	index;
	int		length;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	index = 0;
	length = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			length += ft_check_format(args, format[index]);
		}
		else
			length += ft_putchar_print(format[index]);
		index++;
	}
	va_end(args);
	return (length);
}

static int	ft_check_format(va_list args, char current_format)
{
	int	c;

	c = 0;
	if (current_format == 'c')
		c += ft_putchar_print((char)va_arg(args, int));
	else if (current_format == 's')
		c += ft_putstr_print(va_arg(args, char *));
	else if (current_format == 'p')
		c += ft_putptr_print(va_arg(args, unsigned long), HEXA_LOW_BASE);
	else if (current_format == 'd' || current_format == 'i')
		c += ft_putnbr_base_print(va_arg(args, int), DECIMAL_BASE);
	else if (current_format == 'u')
		c += ft_putnbr_base_print(va_arg(args, unsigned int), DECIMAL_BASE);
	else if (current_format == 'x')
		c += ft_putnbr_base_print(va_arg(args, unsigned int), HEXA_LOW_BASE);
	else if (current_format == 'X')
		c += ft_putnbr_base_print(va_arg(args, unsigned int), HEXA_UP_BASE);
	else if (current_format == '%')
		c += ft_putchar_print('%');
	return (c);
}
