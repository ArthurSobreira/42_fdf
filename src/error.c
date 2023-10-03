/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:01:03 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/03 19:54:10 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(short error_code)
{
	else if (error_code == 1)
		ft_printf("\033[31;3mInvalid parameter, try './fdf <path_to_map>'\033[0m\n");
	else if (error_code == 2)
		ft_printf("\033[31;3mError, unable to allocate fdf :(\033[0m\n");
	else if (error_code == 3)
		ft_printf("\033[31;3mError, unable to allocate mlx :(\033[0m\n");
	else if (error_code == 4)
		ft_printf("\033[31;3mError, unable to allocate window :(\033[0m\n");
	exit(error_code);
}
