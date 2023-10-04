/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:15:50 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/04 18:42:32 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 600
# define WINDOW_NAME "FDF - 42"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}			t_point;

typedef struct s_img
{
	void	*mlx_image;
	char	*adress;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fdf
{
    void    *mlx_ptr;
    void    *win_ptr;
	t_img	img;
}           t_fdf;


void	handle_error(short error_code);
void	pixel_put(t_fdf *fdf, int x, int y, int color);
int		handle_keypress(int key, t_fdf *fdf);
void	clear_all(t_fdf *fdf);
void	render_background(t_fdf *fdf, int color);
void	bresenham(t_fdf *fdf, t_point inital_point, t_point end_point);

#endif
