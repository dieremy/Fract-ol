/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:52:00 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/10 10:52:05 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define HW 1000

# if __APPLE__

#  include "minilibx/minilibx_mac/mlx.h"
#  include "hook_mac.h"

# elif __linux__

#  include "minilibx/minilibx-linux/mlx.h"
#  include "minilibx/minilibx-linux/mlx_int.h"
#  include "hook_linux.h"

# endif

# include "colors.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h> 
# include <string.h>

# define NUM_THREADS 8

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
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
	double	scaling;
	float	x;
	float	y;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		i;
	int		max_i;
	int		color;
	int		shade;
	char	*name;
}				t_fractal;

void	put_pixel_image(int x, int y, t_fractal *d, int color);
void    *plotting_fractal(void *void_data);
void	julia_plane(t_fractal *julia);
void	mandelbrot(t_fractal *mBrot);
void	mand_plane(t_fractal *mBrot);
void	dou_plane(t_fractal *dou);
void	which_fract(t_fractal *d);
void	julia(t_fractal *julia);
void	mlx_look(t_fractal *d);
void	description(char **av);
void	douady(t_fractal *dou);
void	str_put(t_fractal *d);
void	zoom(t_fractal *d);
int		mouse_hook(int button, int x, int y, t_fractal *d);
int		ft_key_press(int keycode, t_fractal *d);
int		ft_strcmp(char *s1, char *s2);
int		ft_close(t_fractal *d);

#endif
