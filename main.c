/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:34:59 by arsobrei          #+#    #+#             */
/*   Updated: 2023/09/28 10:30:39 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

#define MLX_ERROR 1
#define RED_PIXEL 0xff0000
#define BLUE_PIXEL 0x0000ff
#define GREEN_PIXEL 0x00ff00

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
}           t_data;

typedef	struct s_rect
{
	int	x;
    int	y;
    int width;
    int height;
    int color;
}		t_rect;

int	render_x(t_data *data, int iter)
{
	int	index;

	// Verify if window has been destroyed
	if (data->win_ptr != NULL)
	{
		// Clear the window if there is anything on it
		mlx_clear_window(data->mlx_ptr, data->win_ptr);

		index = 0;
		while (index <= iter)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2) + index, (WINDOW_HEIGHT / 2) + index, (BLUE_PIXEL * (index + 10)));
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2) + index, (WINDOW_HEIGHT / 2) - index, (BLUE_PIXEL * (index + 10)));
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2) - index, (WINDOW_HEIGHT / 2) - index, (BLUE_PIXEL * (index + 10)));
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2) - index, (WINDOW_HEIGHT / 2) + index, (BLUE_PIXEL * (index + 10)));
			index++;
		}
	}
	return (0);
}

int	render_plus(t_data *data, int iter)
{
	int	index;

	if (data->win_ptr != NULL)
	{
		// Clear the window if there is anything on it
		mlx_clear_window(data->mlx_ptr, data->win_ptr);

		index = 0;
		while (index <= iter)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2) + index, (WINDOW_HEIGHT / 2), (BLUE_PIXEL * (index + 10)));
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2) - index, (WINDOW_HEIGHT / 2), (BLUE_PIXEL * (index + 10)));
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) + index, (BLUE_PIXEL * (index + 10)));
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) - index, (BLUE_PIXEL * (index + 10)));			
			index++;
		}
	}
	return (0);
}

int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
        return (1);
		
	// Clear the window if there is anything on it
	mlx_clear_window(data->mlx_ptr, data->win_ptr);

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
		{
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, (rect.color * j));
			j++;
		}
        ++i;
    }
	return (0);
}

void	render_background(t_data *data, int color)
{
	int	x;
	int	y;
	
	if (data->win_ptr != NULL)
	{
		// Clear the window if there is anything on it
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			x = 0;
			while (x < WINDOW_WIDTH)
			{
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
				x++;
			}
			++y;
		}
	}	
}

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else if (key == XK_Up)
		render_x(data, 200);
	else if (key == XK_Down)
		render_x(data, 100);
	else if (key == XK_Right)
		render_plus(data, 200);
	else if (key == XK_Left)
		render_plus(data, 100);
	else if (key == XK_1)
		render_background(data, 0x00FF00);
	else if (key == XK_2)
		render_rect(data, (t_rect){((WINDOW_WIDTH / 2) - 75), ((WINDOW_HEIGHT / 2) - 75),
		120, 120, RED_PIXEL});
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	// Error Verification
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf - 42");
	// Error Verification
	if (data.win_ptr == NULL)
	{
		free (data.win_ptr);
		return (MLX_ERROR);
	}
	
	// Setup hooks
	mlx_loop_hook(data.mlx_ptr, &handle_keypress, &data);

	// Hook for close window
	mlx_hook(data.win_ptr, DestroyNotify, ButtonReleaseMask, close_window, &data);	
	
	// Hook for keypress
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);	

	// Setup Loop
	mlx_loop(data.mlx_ptr);

	// Exit the loop if there's no window left
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);

	return (0);
}

