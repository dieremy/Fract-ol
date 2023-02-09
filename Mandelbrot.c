#include "minilibx-linux/mlx.h"
#include "fractal.h"

t_fractal   *create_struct(void)
{
    t_fractal   *elem;

    elem = malloc(sizeof(t_fractal));
    return (elem);
}

int escape_time_algo(int x, int y, int width, int height)
{
    t_fractal  *mBrot;
    int         iterations;
    int         iter;

    mBrot = create_struct();
    iterations = 1000;
    iter = 0;
    mBrot->x0 = (x - width / 2.0) * 4.0 / width;
    mBrot->y0 = (y - height / 2.0) * 4.0 / width;
    mBrot->x_ = 0;
    mBrot->y_ = 0;
    while (mBrot->x_ * mBrot->x_ + mBrot->y_ * mBrot->y_ <= 4 && iter < iterations)
    {
        double xtemp = mBrot->x_ * mBrot->x_ - mBrot->y_ * mBrot->y_ + mBrot->x0;
        mBrot->y_ = 2 * mBrot->x_ * mBrot->y_ + mBrot->y0;
        mBrot->x_ = xtemp;
        iter++;
    }
    if (iter == iterations)
        return 0;
    else
        return iter * NEUTRALBLACK / iterations;
}

int main(void)
{
    t_fractal  *fractal;
    int         i;
    int         j;

    fractal = create_struct();
    fractal->mlx = mlx_init();
    fractal->mlx_win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "FRACTAL");
    i = -1;
    while (++i < WIDTH)
    {
        j = -1;
        while (++j < WIDTH)
        {
            int color = escape_time_algo(i, j, WIDTH, HEIGHT);
            mlx_pixel_put(fractal->mlx, fractal->mlx_win, i, j, color);// redo the function
        }
    }
    mlx_loop(fractal->mlx);
    return (0);
}
