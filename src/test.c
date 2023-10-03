/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:14:19 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/03 18:15:01 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define RED_PIXEL 0xff0000
#define BLUE_PIXEL 0x0000ff
#define GREEN_PIXEL 0x00ff00

typedef	struct s_rect
{
	int	x;
    int	y;
    int width;
    int height;
    int color;
}		t_rect;

void	pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->img.adress + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}

void	clear_window(t_fdf *data)
{
	int	x;
	int	y;

	// Verify if window has been destroyed
	if (data->win_ptr != NULL)
	{	
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			x = 0;
			while (x < WINDOW_WIDTH)
			{
				pixel_put(data, x, y, 0x1a1a1a);
				x++;
			}
			++y;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_image, 0, 0);
	}
}

int	render_x(t_fdf *data, int iter, int color)
{
	int	index;

	// Clear the window if there is anything on it
	clear_window(data);

	// Verify if window has been destroyed
	if (data->win_ptr != NULL)
	{
		index = 0;
		while (index++ <= iter)
			pixel_put(data, ((WINDOW_WIDTH / 2) + index), ((WINDOW_HEIGHT / 2) + index), (color * (index + 10)));
		index = 0;
		while (index++ <= iter)
			pixel_put(data, ((WINDOW_WIDTH / 2) - index), ((WINDOW_HEIGHT / 2) + index), (color * (index + 10)));		
		index = 0;
		while (index++ <= iter)
			pixel_put(data, ((WINDOW_WIDTH / 2) + index), ((WINDOW_HEIGHT / 2) - index), (color * (index + 10)));
		index = 0;
		while (index++ <= iter)
			pixel_put(data, ((WINDOW_WIDTH / 2) - index), ((WINDOW_HEIGHT / 2) - index), (color * (index + 10)));			
	}
	return (0);
}

int	render_plus(t_fdf *data, int iter, int color)
{
	int	index;

	// Clear the window if there is anything on it
	clear_window(data);

	// Verify if window has been destroyed
	if (data->win_ptr != NULL)
	{
		index = 0;
		while (index++ <= iter)
			pixel_put(data, ((WINDOW_WIDTH / 2) + index), (WINDOW_HEIGHT / 2), (color * (index + 10)));
		index = 0;
		while (index++ <= iter)
			pixel_put(data, ((WINDOW_WIDTH / 2) - index), (WINDOW_HEIGHT / 2), (color * (index + 10)));		
		index = 0;
		while (index++ <= iter)
			pixel_put(data, (WINDOW_WIDTH / 2), ((WINDOW_HEIGHT / 2) + index), (color * (index + 10)));
		index = 0;
		while (index++ <= iter)
			pixel_put(data, (WINDOW_WIDTH / 2), ((WINDOW_HEIGHT / 2) - index), (color * (index + 10)));			
	}
	return (0);
}

int	render_rect(t_fdf *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
        return (1);

	// Clear the window if there is anything on it
	clear_window(data);

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
		{
            pixel_put(data, j, i, (rect.color * j));
			j++;
		}
        ++i;
    }
	return (0);
}

void	render_background(t_fdf *data, int color)
{
	int	x;
	int	y;
	
	// Clear the window if there is anything on it
	clear_window(data);

	// Verify if window has been destroyed
	if (data->win_ptr != NULL)
	{	
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			x = 0;
			while (x < WINDOW_WIDTH)
			{
				pixel_put(data, x, y, color);
				x++;
			}
			++y;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_image, 0, 0);
	}	
}

int	handle_keypress(int key, t_fdf *data)
{
	if (key == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	else if (key == XK_Up)
		render_x(data, 200, RED_PIXEL);
	else if (key == XK_Down)
		render_x(data, 100, RED_PIXEL);
	else if (key == XK_Right)
		render_plus(data, 200, RED_PIXEL);
	else if (key == XK_Left)
		render_plus(data, 100, RED_PIXEL);
	else if (key == XK_1)
		render_background(data, 0x00ff00);
	else if (key == XK_2)
		render_rect(data, (t_rect){((WINDOW_WIDTH / 2) - 75), ((WINDOW_HEIGHT / 2) - 75),
		120, 120, RED_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_image, 0, 0);
	return (0);
}

void	clear_all(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_image);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->win_ptr = NULL;
	free(data->mlx_ptr);
}

int main(void)
{
	t_fdf	data;

	data.mlx_ptr = mlx_init();
	
	// Error Verification
	if (data.mlx_ptr == NULL)
		return (1);
	
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf - 42");
	
	// Error Verification
	if (data.win_ptr == NULL)
	{
		free (data.win_ptr);
		return (1);
	}
	
	// Create the image
	data.img.mlx_image = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	/*
	** After creating an image, we can call `mlx_get_fdf_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	data.img.adress = mlx_get_data_addr(data.img.mlx_image, &data.img.bits_per_pixel, \
										&data.img.line_length, &data.img.endian);

	// Coloring the background
	render_background(&data, 0x1a1a1a);

	// Hook for keypress
	mlx_key_hook(data.win_ptr, &handle_keypress, &data);

	// Hook for close window
	mlx_hook(data.win_ptr, DestroyNotify, ButtonReleaseMask, mlx_loop_end, data.mlx_ptr);	
	
	// Setup Loop
	mlx_loop(data.mlx_ptr);

	// Clear the display and free the memory
	clear_all(&data);

	return (0);
}
