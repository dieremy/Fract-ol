#ifndef FRACTAL_H
# define FRACTAL_H

# define HEIGHT 1000
# define WIDTH 1000

# include "hook.h"
# include "colors.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*mlx_win;
	double	y0;
	double	x0;
	double	y_;
	double	x_;
}				t_fractal;

#endif