/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:52:00 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/19 16:45:31 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define HW 800

# include "minilibx_mms_20191025_beta/mlx.h"
# include "hook.h"
# include "colors.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_fractal
{
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	x_start;
	double	x_end;
	double	y_start;
	double	y_end;
	double	zoom;
	double	tmp;
	double	x_shift;
	double	y_shift;
	double	x;
	double	y;
	char	*name;
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		i;
	int		max_i;
	int		color;
	int		shade;
}				t_fractal;

void	put_pixel_image(int x, int y, t_fractal *d, int color);
void	description(int ac, char **av);
void	julia_plane(t_fractal *julia);
void	mand_plane(t_fractal *mBrot);
void	mandelbrot(t_fractal *mBrot);
void	which_fract(t_fractal *d);
void	dou_plane(t_fractal *dou);
void	julia(t_fractal *julia);
void	mlx_look(t_fractal *d);
void	douady(t_fractal *dou);
void	str_put(t_fractal *d);
void	zoom(t_fractal *d);
int		mouse_hook(int button, int x, int y, t_fractal *d);
int		ft_key_press(int keycode, t_fractal *d);
int		ft_strcmp(char *s1, char *s2);
int		ft_close(t_fractal *d);

#endif
