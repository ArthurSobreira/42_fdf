/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:15:50 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/14 19:22:28 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <stdio.h> // DELETA ISSO

# define WINDOW_WIDTH 1100
# define WINDOW_HEIGHT 800
# define WINDOW_NAME "FDF - 42"
# define WINDOW_BACKGROUND 0x1a1a1a

# define HEXA_BASE 16
# define TRUE  1
# define FALSE 0

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
	int		width;
	int		height;
}			t_map;

typedef struct s_cam
{
	float	scale;
	float	x_offset;
	float	y_offset;
}			t_cam;

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
	t_cam	*cam;
}			t_fdf;

void	handle_error(short error_code);
void	pixel_put(t_fdf *fdf, int x, int y, int color);
int		handle_keypress(int key, t_fdf *fdf);
void	clear_all(t_fdf *fdf, short exit_code);
void	render_background(t_fdf *fdf, int color);
void	render(t_fdf *fdf);

void	init_bres(t_bres *bres_info, t_point initial_point, t_point end_point);
void	bresenham(t_fdf *fdf, t_point inital_point, t_point end_point);
void	bresenham_low(t_fdf *fdf, t_point initial_point, t_point end_point);
void	bresenham_high(t_fdf *fdf, t_point initial_point, t_point end_point);

t_fdf	*init_fdf(char *map_name);
void	init_mlx_image(t_fdf *fdf);

t_point	**init_matrix(int map_width, int map_height);
void	clear_matrix(t_point **matrix, int width);

t_map	*init_map(void);
t_map	*read_map(t_fdf *fdf, char *map_name);
short	valid_map_name(char *file_name);
short	valid_width(int file_descriptor, int width);
void	free_split(char **split_line);
void	not_valid_map(t_fdf *fdf, t_map *map);

t_cam	*init_cam(t_map *map);
float	get_scale_factor(t_map *map);
void	scale_map(t_fdf *fdf, t_point *initial_point, t_point *end_point);
void	centralize(t_fdf *fdf, t_point *initial_point, t_point *end_point);
void	isometric(t_point *initial_point, t_point *end_point);

#endif
