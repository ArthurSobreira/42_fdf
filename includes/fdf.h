/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:15:50 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/10 17:30:49 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 600
# define WINDOW_NAME "FDF - 42"
# define WINDOW_BACKGROUND 0x1a1a1a

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_point;

typedef struct s_bres
{
	float	delta_x;
	float	delta_y;
	int		initial_x;
	int		initial_y;
	int		decision;
	int		x_increment;
	int		y_increment;
}			t_bres;

typedef struct s_map
{
	t_point	**matrix;
	int		x_max;
	int		y_max;
}			t_map;

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
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map;
}			t_fdf;

void	handle_error(short error_code);
void	pixel_put(t_fdf *fdf, int x, int y, int color);
int		handle_keypress(int key, t_fdf *fdf);
void	clear_all(t_fdf *fdf);
void	render_background(t_fdf *fdf, int color);
void	render(t_fdf *fdf);

void	init_bres(t_bres *bres_info, t_point initial_point, t_point end_point);
void	bresenham(t_fdf *fdf, t_point inital_point, t_point end_point);
void	bresenham_low(t_fdf *fdf, t_point initial_point, t_point end_point);
void	bresenham_high(t_fdf *fdf, t_point initial_point, t_point end_point);

t_fdf	*init_fdf(char *map_name);
t_map	*init_map(void);

t_map	*read_map(char *map_name);

#endif
