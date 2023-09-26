/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:34:59 by arsobrei          #+#    #+#             */
/*   Updated: 2023/09/26 11:19:04 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

#include <X11/X.h>
#include <X11/keysym.h>

#define MLX_ERROR 1
#define RED_PIXEL 0xFF0000
typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
}           t_data;

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	render(t_data *data)
{
	int	index;

	// Verify if window has been destroyed
	if (data->win_ptr != NULL)
	{
		index = 1;
		while (index <= 100)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2) + index, (WINDOW_HEIGHT / 2) + index, RED_PIXEL);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2) + index, (WINDOW_HEIGHT / 2) - index, RED_PIXEL);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2) - index, (WINDOW_HEIGHT / 2) - index, RED_PIXEL);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2) - index, (WINDOW_HEIGHT / 2) + index, RED_PIXEL);
			index++;
		}
	}
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	// Error Verification
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	// Error Verification
	if (data.win_ptr == NULL)
	{
		free (data.win_ptr);
		return (MLX_ERROR);
	}
	
	// Setup hooks
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);	

	// Setup Loop
	mlx_loop(data.mlx_ptr);

	// Exit the loop if there's no window left
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);

	return (0);
}
