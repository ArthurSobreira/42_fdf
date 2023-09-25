/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:30:56 by arsobrei          #+#    #+#             */
/*   Updated: 2023/09/25 15:40:47 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// Include lib header
# include "../../libft.h"

// Macros Definitions
# define DECIMAL_BASE "0123456789"
# define HEXA_LOW_BASE "0123456789abcdef"
# define HEXA_UP_BASE "0123456789ABCDEF"

// Functions Prototypes
int	ft_printf(const char *format, ...);
int	ft_putchar_print(char c);
int	ft_putnbr_base_print(long int number, char *base);
int	ft_putptr_print(unsigned long number, char *base);
int	ft_putstr_print(char *str);

#endif