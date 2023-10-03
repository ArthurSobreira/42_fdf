/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:15:50 by arsobrei          #+#    #+#             */
/*   Updated: 2023/10/03 19:57:42 by arsobrei         ###   ########.fr       */
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
# define WINODW_NAME "FDF - 42"

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
void	render_background(t_fdf *fdf, int color);
void	clear_all(t_fdf *fdf);

#endif
