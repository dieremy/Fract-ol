/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:46:56 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/14 09:46:59 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/fractal.h"

void mouse_butt(int x, int y, t_fractal *d)
{
    if ((x > (HW / 2)) && (y < (HW / 2)))
    {//up-dx
        d->x_shift += 0.02; //dx
        d->y_shift -= 0.02; //up
    }
    if ((x < (HW / 2)) && (y > (HW / 2)))
    {//down-sx
        d->x_shift -= 0.02;
        d->y_shift += 0.02;
    }
    if ((y < (HW / 2)) && (x < (HW / 2)))
    {//up-sx
        d->x_shift -= 0.02;
        d->y_shift -= 0.02;
    }
    if ((y > (HW / 2)) && (x > (HW / 2)))
    {//down-dx
        d->x_shift += 0.02;
        d->y_shift += 0.02;
    }
    d->zoom *= 0.9;
}

int mouse_hook(int button, int x, int y, t_fractal *d)
{
    d->x = x;
    d->y = y;
    if (button == 5)
        d->zoom *= 1.5;
    else if (button == 4)
        d->zoom *= 0.9;
    else if (button == 1)
        mouse_butt(d->x, d->y, d);
    which_fract(d);
    return (0);  
}

int ft_key_press3(int keycode, t_fractal *d)
{
    if (keycode == KEY_ESC || keycode == KEY_X)
    {
        write(1, "\nWELCOME HOME SON.\n", 19);
        mlx_destroy_window(d->mlx, d->win);
        free(d);
        exit(0);
    }
    else if (keycode == SHIFT_SX || keycode == SHIFT_DX)
    {
        d->shade -= 4000;
        which_fract(d);
    }
    else if (keycode == KEY_MINUS)
    { 
        d->zoom += 0.002;
        which_fract(d);
    }
    else if (keycode == KEY_PLUS)
    { 
        d->zoom -= 0.002;
        which_fract(d);
    }
    return (0);
}

int ft_key_press2(int keycode, t_fractal *d)
{
    if (keycode == KEY_M)
    {
        d->name = "Mandelbrot";
        which_fract(d);
    }
    else if (keycode == KEY_J)
    {
        d->name = "Julia";
        which_fract(d);
    }
    else if (keycode == KEY_D)
    {
        d->name = "Douady";
        which_fract(d);
    }
    else
        ft_key_press3(keycode, d);
    return (0);
}

int ft_key_press(int keycode, t_fractal *d)
{
    if (keycode == KEY_LEFT)
    { 
        d->x_shift -= 0.0002;
        which_fract(d);
    }
    else if (keycode == KEY_RIGHT)
    { 
        d->x_shift += 0.0002;
        which_fract(d);
    }
    else if (keycode == KEY_DOWN)
    {
        d->y_shift += 0.0002;
        which_fract(d);
    }
    else if (keycode == KEY_UP)
    { 
        d->y_shift -= 0.0002;
        which_fract(d);
    }
    else
        ft_key_press2(keycode, d);
    return (0);
}

