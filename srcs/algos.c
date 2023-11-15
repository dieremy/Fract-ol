/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:33:38 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/12 13:33:42 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	put_pixel_image(int x, int y, t_fractal *d, int color)
{
	int	pos;

	pos = (y * HW) + x;
	d->addr[pos] = color;
}

void    *plotting_fractal(void *void_data)
{
    t_fractal   *d;

    d = (t_fractal *)void_data;
    d->x = -1;
    while (++d->x < HW)
    {
        d->y = -1;
        while (++d->y < HW)
        {
            if (ft_strcmp(d->name, "Mandelbrot") == 0)
                mandelbrot(d);
            else if (ft_strcmp(d->name, "Julia") == 0)
                julia(d);
            else if (ft_strcmp(d->name, "Douady") == 0)
                douady(d);
            put_pixel_image(d->x, d->y, d, d->color);
        }
    }
	mlx_look(d);
    return (0);
}

void	mandelbrot(t_fractal *mBrot)
{
	mand_plane(mBrot);
	while (mBrot->zx * mBrot->zx + mBrot->zy * mBrot->zy < 4 && mBrot->i < mBrot->max_i)
	{
		mBrot->tmp = mBrot->zx * mBrot->zx - mBrot->zy * mBrot->zy + mBrot->cx;
		mBrot->zy = 2 * mBrot->zx * mBrot->zy + mBrot->cy;
		mBrot->zx = mBrot->tmp;
		mBrot->i++;
	}
}

void	julia(t_fractal *julia)
{
	julia_plane(julia);
	while (julia->zx * julia->zx + julia->zy * julia->zy < 4 && julia->i < julia->max_i)
	{
		julia->tmp = julia->zx;
		julia->zx = julia->zx * julia->zx - julia->zy * julia->zy + julia->cx;
		julia->zy = 2 * julia->tmp * julia->zy + julia->cy;
		julia->i++;
	}
}

void	douady(t_fractal *dou)
{
	dou_plane(dou);
	while (dou->zx * dou->zx + dou->zy * dou->zy < 4 && dou->i < dou->max_i)
	{
		dou->tmp = dou->zx;
		dou->zx = dou->zx * dou->zx - dou->zy * dou->zy + dou->cx;
		dou->zy = 2 * dou->tmp * dou->zy + dou->cy;
		dou->i++;
	}
}
