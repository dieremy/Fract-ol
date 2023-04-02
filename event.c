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

#include "fractal.h"

int mouse_hook(int button, int x, int y, t_fractal *d)
{
    if (button == MOUSEUP)
    {
        d->y = y;
        d->x = x;
        d->zoom *= 1.5;
    }
    else if (button == MOUSEDOWN)
    {
        d->y = y;
        d->x = x;
        d->zoom /= 1.5;
    }
    else if (button == 1)
    {
        d->y = y;
        d->x = x;
        d->x_shift = (d->x / (HW / (d->x_end - d->x_start))
            + d->x_start) * d->zoom + d->x_shift;
        d->y_shift = (d->y / (HW / (d->y_end - d->y_start))
            + d->y_start) * d->zoom + d->y_shift;
        which_fract(d);
        // d->x_shift = ((d->x - (HW / 2.0)) * (4.0 / HW) * (1.0 / d->zoom)) + d->x_shift;
        // d->y_shift = ((HW / 2.0) - d->y) * (4.0 / HW) * (1.0 / d->zoom) + d->y_shift;
    }
    which_fract(d);
    return (0);  
}

void    str_put(t_fractal *d)
{
    mlx_string_put(d->mlx, d->win, 720, 200,
     YELLOW, "KEYBOARD SHORCUTS:");
    mlx_string_put(d->mlx, d->win, 720, 250,
     YELLOW, "      CLOSE THE WINDOW: >>>>> X/ESC");
    mlx_string_put(d->mlx, d->win, 720, 300,
     YELLOW, "      CHANGE COLOR SHADE: >>>>> SHIFT");
    mlx_string_put(d->mlx, d->win, 720, 350,
     YELLOW, "      MOVE FRACTAL: >>>>> ARROWS");
    mlx_string_put(d->mlx, d->win, 720, 400,
     YELLOW, "      ZOOM/UNZOOM >>>>> PLUS/MINUS");
    mlx_string_put(d->mlx, d->win, 720, 450,
     YELLOW, "      CHANGE TO JULIA >>>>> J");
    mlx_string_put(d->mlx, d->win, 720, 500,
     YELLOW, "      CHANGE TO MANDELBROT: >>>>> M");
    mlx_string_put(d->mlx, d->win, 720, 550,
     YELLOW, "      CHANGE TO DOUADY: >>>>> D");
    mlx_string_put(d->mlx, d->win, 720, 600,
     YELLOW, "MOUSE INTERATION:");
    mlx_string_put(d->mlx, d->win, 720, 650,
     YELLOW, "      ZOOM/UNZOOM: >>>>> MOUSE ROLL");
}

void    mlx_look(t_fractal *d)
{
    mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
    str_put(d);
    mlx_key_hook(d->win, ft_key_press, d);
    mlx_hook(d->win, 17, 1L<<0, ft_close, d);
    mlx_mouse_hook(d->win, mouse_hook, d);
    mlx_loop(d->mlx);
    free(d);
}

int ft_close(t_fractal *d)
{
    write(1, "\nWELCOME BACK TO REALITY SON\n", 29);
    mlx_destroy_window(d->mlx, d->win);
    free(d);
    exit(0);
}

int ft_key_press3(int keycode, t_fractal *d)
{
    if (keycode == KEY_ESC || keycode == KEY_X)
    {//ESC - X
        write(1, "\nWELCOME BACK TO REALITY SON.\n", 30);
        mlx_destroy_window(d->mlx, d->win);
        free(d);
        exit(0);
    }
    else if (keycode == KEY_SHIFT_L || keycode == KEY_SHIFT_R)
    {//shift
        d->shade -= 4000;
        which_fract(d);
    }
    else if (keycode == KEY_MINUS)
    {//minus
        d->zoom += 0.02;
        which_fract(d);
    }
    else if (keycode == KEY_PLUS)
    {//plus
        d->zoom -= 0.02;
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
    {//sx
        d->x_shift -= 0.04;
        which_fract(d);
    }
    else if (keycode == KEY_RIGHT)
    {//dx
        d->x_shift += 0.04;
        which_fract(d);
    }
    else if (keycode == KEY_DOWN)
    {//down
        d->y_shift += 0.04;
        which_fract(d);
    }
    else if (keycode == KEY_UP)
    {//up
        d->y_shift -= 0.04;
        which_fract(d);
    }
    else
        ft_key_press2(keycode, d);
    return (0);
}

