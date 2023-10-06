/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:20:16 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/06 12:09:12 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap(int *a, int *b)
{
	int	*temp;

	temp = a;
	*a = *b;
	*b = *temp;
}

short	verify_octant(int *dx, int *dy, int *ini_x, int *ini_y)
{
	short	verify;

	verify = 0;
	if (ft_abs(*dy) > ft_abs(*dx))
	{
		swap(dx, dy);
		swap(ini_x, ini_y);
		verify = 1;
	}
	return (verify);
}
