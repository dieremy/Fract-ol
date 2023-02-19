/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:40:53 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/19 10:40:56 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/fractal.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

void    description(int ac, char **av)
{
    if (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1], "Julia")
     || !ft_strcmp(av[1], "Douady"))
    {
        write(1, "\nKEYBOARD SHORCUTS:\n", 21);
        write(1, "\tCLOSE THE PROGRAM:\tX/ESC\n", 26);
        write(1, "\tCHANGE COLOR SHADE:\tSHIFT\n", 27);
        write(1, "\tMOVE FRACTAL:\t\t", 16);
        write(1, "\tARROWS\n", 8);
        write(1, "\tZOOM/UNZOOM:\t\tPLUS/MINUS\n", 26);
        write(1, "\tCHANGE TO JULIA:\tJ\n", 20);
        write(1, "\tCHANGE TO MANDELBROT:\tM\n", 25);
        write(1, "\tCHANGE TO DOUADY:\tD\n", 21);
        write(1, "\nMOUSE INTERATION:\n", 19);
        write(1, "\tZOOM/UNZOOM:\t\tMOUSE ROLL\n", 26);
    }
}

void    str_put(t_fractal *d)
{
    mlx_string_put(d->mlx, d->win, 970, 450,
     RED, "KEYBOARD SHORCUTS:");
    mlx_string_put(d->mlx, d->win, 970, 500,
     RED, "      CLOSE THE WINDOW:      X/ESC");
    mlx_string_put(d->mlx, d->win, 970, 550,
     RED, "      CHANGE COLOR SHADE:    SHIFT");
    mlx_string_put(d->mlx, d->win, 970, 600,
     RED, "      MOVE FRACTAL:          ARROWS");
    mlx_string_put(d->mlx, d->win, 970, 650,
     RED, "      ZOOM/UNZOOM:           PLUS/MINUS");
    mlx_string_put(d->mlx, d->win, 970, 700,
     RED, "      CHANGE TO JULIA:       J");
    mlx_string_put(d->mlx, d->win, 970, 750,
     RED, "      CHANGE TO MANDELBROT:  M");
    mlx_string_put(d->mlx, d->win, 970, 800,
     RED, "      CHANGE TO DOUADY:      D");
    mlx_string_put(d->mlx, d->win, 970, 850,
     RED, "MOUSE INTERATION:");
    mlx_string_put(d->mlx, d->win, 970, 900,
     RED, "      ZOOM/UNZOOM:           MOUSE ROLL");
}

int ft_close(t_fractal *d)
{
    write(1, "\nWELCOME HOME SON.\n", 19);
    mlx_destroy_window(d->mlx, d->win);
    free(d);
    exit(0);
}
