/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:01:03 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/10 13:55:42 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(short exit_code)
{
	if (exit_code == 0)
		ft_printf("\033[32;3mFDF closed, Thank You :)\033[0m\n");
	else if (exit_code == 1)
		ft_printf("\033[31;3mError, invalid parameter :(\033[0m\n");
	else if (exit_code == 2)
		ft_printf("\033[31;3mError, unable to allocate fdf :(\033[0m\n");
	else if (exit_code == 3)
		ft_printf("\033[31;3mError, unable to allocate mlx :(\033[0m\n");
	else if (exit_code == 4)
		ft_printf("\033[31;3mError, unable to allocate window :(\033[0m\n");
	else if (exit_code == 5)
		ft_printf("\033[31;3mError, pixel outside window range :(\033[0m\n");
	else if (exit_code == 6)
		ft_printf("\033[31;3mError, unable to use bresenham :(\033[0m\n");
	exit(exit_code);
}
