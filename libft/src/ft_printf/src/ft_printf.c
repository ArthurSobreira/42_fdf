/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:13:26 by arsobrei          #+#    #+#             */
/*   Updated: 2023/09/25 11:46:02 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	int	ct;

	ct = 0;
	if (current_format == 'c')
		ct += ft_putchar_print((char)va_arg(args, int));
	else if (current_format == 's')
		ct += ft_putstr_print(va_arg(args, char *));
	else if (current_format == 'p')
		ct += ft_putptr_print(va_arg(args, unsigned long), HEXA_LOW_BASE);
	else if (current_format == 'd' || current_format == 'i')
		ct += ft_putnbr_base_print(va_arg(args, int), DECIMAL_BASE);
	else if (current_format == 'u')
		ct += ft_putnbr_base_print(va_arg(args, unsigned int), DECIMAL_BASE);
	else if (current_format == 'x')
		ct += ft_putnbr_base_print(va_arg(args, unsigned int), HEXA_LOW_BASE);
	else if (current_format == 'X')
		ct += ft_putnbr_base_print(va_arg(args, unsigned int), HEXA_UP_BASE);
	else if (current_format == '%')
		ct += ft_putchar_print('%');
	return (ct);
}
