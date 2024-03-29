/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:52:09 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/10 10:52:14 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static void *ft_memcpy(void *dst, const void *src, size_t n) {
  size_t i;

  i = 0;
  if (!dst && !src)
    return (NULL);
  while (i < n) {
    *(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
    i++;
  }
  return (dst);
}

int ft_strcmp(char *s1, char *s2) {
  int i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

static t_fractal *id(char *s) {
  t_fractal *d;

  d = (t_fractal *)malloc(sizeof(t_fractal));
  d->max_i = 500;
  d->name = s;
  d->zoom = 1;
  d->x_shift = 0;
  d->y_shift = 0;
  d->shade = 0;
  d->x_start = -2.0;
  d->x_end = 2.0;
  d->y_start = -2.0;
  d->y_end = 2.0;
  return (d);
}

static int description(char *av[]) {
  ///// CLEAN THIS /////
  if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "Julia") == 0 ||
      ft_strcmp(av[1], "Douady") == 0) {
    write(1, "KEYBOARD SHORCUTS:\n", 20);
    write(1, "\tCLOSE THE WINDOW:\tX/ESC\n", 25);
    write(1, "\tCHANGE COLOR SHADE:\tSHIFT\n", 27);
    write(1, "\tMOVE FRACTAL:\t\t", 16);
    write(1, "ARROW-LEFT/ARROW-RIGHT/ARROW-UP/ARROW-DOWN\n", 43);
    write(1, "\tZOOM/UNZOOM:\t\tPLUS/MINUS\n", 26);
    write(1, "\tCHANGE TO JULIA:\tJ\n", 20);
    write(1, "\tCHANGE TO MANDELBROT:\tM\n", 25);
    write(1, "\tCHANGE TO DOUADY:\tD\n", 21);
    write(1, "MOUSE INTERATION:\n", 18);
    write(1, "\tZOOM/UNZOOM:\t\tMOUSE ROLL\n", 26);
    write(1, "\tZOOM & MOVE:\t\tLEFT MOUSE CLICK\n", 32);
    return (0);
  }
  write(2, "USAGE: ./fractal", 16);
  write(2, "\tMandelbrot\tJulia\tDouady\n", 25);
  return (1);
}

void which_fract(t_fractal *d) {
  pthread_t th[NUM_THREADS];
  t_fractal *thread_data;
  int i;

  ///// THIS CHECK IS NO LONGER NECESSARY /////
  if (ft_strcmp(d->name, "Mandelbrot") && ft_strcmp(d->name, "Julia") &&
      ft_strcmp(d->name, "Douady")) {
    write(2, "USAGE: ./fractal", 16);
    write(2, "\tMandelbrot\tJulia\tDouady\n", 25);
    exit(0);
  }
  i = -1;
  while (++i < NUM_THREADS) {
    thread_data = malloc(sizeof(t_fractal));
    ft_memcpy(thread_data, d, sizeof(t_fractal));
    pthread_create(&th[i], NULL, plotting_fractal, thread_data);
  }
  i = -1;
  while (++i < NUM_THREADS) {
    pthread_join(th[i], NULL);
    free(&thread_data[i]);
  }
}

int main(int ac, char **av) {
  t_fractal *d;

  ///// RE-PLAN MAIN FUNCTION /////
  if (ac == 2) {
    if (description(av) == 0) {
      d = id(av[1]);
      d->pid = system(NEW_ERROR_MP3);
      d->mlx = mlx_init();
      d->win = mlx_new_window(d->mlx, HW, HW, "FRACT'OL");
      d->img = mlx_new_image(d->mlx, HW, HW);
      d->addr = (int *)mlx_get_data_addr(d->img, &d->bits_per_pixel,
                                         &d->line_length, &d->endian);
      which_fract(d);
    } else
      exit(1);
  }
  write(2, "USAGE: ./fractal", 16);
  write(2, "\tMandelbrot\tJulia\tDouady\n", 25);
  pthread_exit(NULL);
  return (0);
}
