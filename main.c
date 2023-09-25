/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:34:59 by arsobrei          #+#    #+#             */
/*   Updated: 2023/09/25 19:46:54 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
}           t_data;

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		color = 0xFF0000;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf muito pika");
	img_ptr = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	mlx_pixel_put(mlx_ptr, img_ptr, 400, 300, color);

	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

	mlx_loop(mlx_ptr);

	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
